[CmdletBinding()]
param(
    [ValidateRange(2019, 2027)]
    [int]$Year,
    [switch]$All,
    [string]$OutputDirectory = ".\artifacts\packages"
)

$ErrorActionPreference = "Stop"
Set-StrictMode -Version Latest

$repositoryRoot = Split-Path -Parent $PSScriptRoot
$projectPath = Join-Path $repositoryRoot "AutoCADAllInOne/AutoCADAllInOne.csproj"
$resolvedOutputDirectory = if ([System.IO.Path]::IsPathRooted($OutputDirectory)) {
    [System.IO.Path]::GetFullPath($OutputDirectory)
}
else {
    [System.IO.Path]::GetFullPath((Join-Path $repositoryRoot $OutputDirectory))
}

if (($Year -eq 0 -and -not $All) -or ($Year -ne 0 -and $All)) {
    throw "Specify exactly one of -Year or -All."
}

$years = if ($All) { 2019..2027 } else { @($Year) }
[System.IO.Directory]::CreateDirectory($resolvedOutputDirectory) | Out-Null

foreach ($selectedYear in $years) {
    $metadataPath = Join-Path $repositoryRoot "metadata/$selectedYear.json"
    if (-not (Test-Path -LiteralPath $metadataPath -PathType Leaf)) {
        throw "Metadata is missing for AutoCAD ${selectedYear}: $metadataPath"
    }

    $metadata = Get-Content -LiteralPath $metadataPath -Raw | ConvertFrom-Json
    Write-Output "Packing AutoCAD $selectedYear facade $($metadata.wrapperVersion) -> AutoCAD.NET $($metadata.autodeskPackageVersion)"

    $arguments = @(
        "pack",
        $projectPath,
        "--configuration", "Release",
        "--output", $resolvedOutputDirectory,
        "-p:AutoCadVersion=$selectedYear",
        "-p:PackageVersion=$($metadata.wrapperVersion)",
        "-p:AutoCadSdkPackageVersion=$($metadata.autodeskPackageVersion)"
    )

    & dotnet @arguments
    if ($LASTEXITCODE -ne 0) {
        throw "dotnet pack failed for AutoCAD $selectedYear with exit code $LASTEXITCODE."
    }
}

Write-Output "Package output: $resolvedOutputDirectory"
