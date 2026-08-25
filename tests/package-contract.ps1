[CmdletBinding()]
param(
    [switch]$MetadataOnly,
    [ValidateRange(2019, 2027)]
    [int]$Year,
    [string]$PackageDirectory = ".\artifacts\packages",
    [switch]$SkipConsumerBuild
)

$ErrorActionPreference = "Stop"
Set-StrictMode -Version Latest

$script:RepositoryRoot = Split-Path -Parent $PSScriptRoot

function Assert-Contract {
    param(
        [Parameter(Mandatory = $true)]
        [bool]$Condition,
        [Parameter(Mandatory = $true)]
        [string]$Message
    )

    if (-not $Condition) {
        throw "Contract failed: $Message"
    }
}

function Get-ExpectedYearContracts {
    @(
        [pscustomobject]@{ Year = 2019; WrapperVersion = "2019.0.1"; AutodeskPackageVersion = "23.0.0"; TargetFramework = "net47"; LocalSdkStatus = "missing"; LocalSdkPath = "" }
        [pscustomobject]@{ Year = 2020; WrapperVersion = "2020.0.1"; AutodeskPackageVersion = "23.1.0"; TargetFramework = "net47"; LocalSdkStatus = "present"; LocalSdkPath = "libs/ObjectARX_Cad20" }
        [pscustomobject]@{ Year = 2021; WrapperVersion = "2021.0.1"; AutodeskPackageVersion = "24.0.0"; TargetFramework = "net47"; LocalSdkStatus = "missing"; LocalSdkPath = "" }
        [pscustomobject]@{ Year = 2022; WrapperVersion = "2022.0.1"; AutodeskPackageVersion = "24.1.51000"; TargetFramework = "net47"; LocalSdkStatus = "missing"; LocalSdkPath = "" }
        [pscustomobject]@{ Year = 2023; WrapperVersion = "2023.0.1"; AutodeskPackageVersion = "24.2.0"; TargetFramework = "net47"; LocalSdkStatus = "present"; LocalSdkPath = "libs/ObjectARX_Cad23" }
        [pscustomobject]@{ Year = 2024; WrapperVersion = "2024.0.1"; AutodeskPackageVersion = "24.3.0"; TargetFramework = "net48"; LocalSdkStatus = "present"; LocalSdkPath = "libs/ObjectARX_Cad24" }
        [pscustomobject]@{ Year = 2025; WrapperVersion = "2025.0.1"; AutodeskPackageVersion = "25.0.1"; TargetFramework = "net8.0-windows"; LocalSdkStatus = "present"; LocalSdkPath = "libs/ObjectARX_Cad25" }
        [pscustomobject]@{ Year = 2026; WrapperVersion = "2026.0.1"; AutodeskPackageVersion = "25.1.1"; TargetFramework = "net10.0-windows"; LocalSdkStatus = "present"; LocalSdkPath = "libs/ObjectARX_Cad26" }
        [pscustomobject]@{ Year = 2027; WrapperVersion = "2027.0.1"; AutodeskPackageVersion = "26.0.0"; TargetFramework = "net10.0-windows"; LocalSdkStatus = "present"; LocalSdkPath = "libs/ObjectARX_Cad27" }
    )
}

function Test-MetadataContract {
    $metadataDirectory = Join-Path $script:RepositoryRoot "metadata"
    Assert-Contract (Test-Path -LiteralPath $metadataDirectory -PathType Container) "metadata directory is missing"

    $metadataFiles = @(Get-ChildItem -LiteralPath $metadataDirectory -Filter "*.json" -File)
    Assert-Contract ($metadataFiles.Count -eq 9) "expected 9 metadata files, found $($metadataFiles.Count)"

    $expectedContracts = @(Get-ExpectedYearContracts)
    foreach ($expected in $expectedContracts) {
        $metadataPath = Join-Path $metadataDirectory "$($expected.Year).json"
        Assert-Contract (Test-Path -LiteralPath $metadataPath -PathType Leaf) "missing metadata/$($expected.Year).json"

        $actual = Get-Content -LiteralPath $metadataPath -Raw | ConvertFrom-Json
        Assert-Contract ([int]$actual.year -eq $expected.Year) "$($expected.Year) metadata has the wrong year"
        Assert-Contract ([string]$actual.wrapperVersion -eq $expected.WrapperVersion) "$($expected.Year) wrapper version mismatch"
        Assert-Contract ([string]$actual.autodeskPackageVersion -eq $expected.AutodeskPackageVersion) "$($expected.Year) Autodesk package version mismatch"
        Assert-Contract ([string]$actual.targetFramework -eq $expected.TargetFramework) "$($expected.Year) target framework mismatch"
        Assert-Contract ([string]$actual.localSdkStatus -eq $expected.LocalSdkStatus) "$($expected.Year) local SDK status mismatch"
        Assert-Contract ([string]$actual.localSdkPath -eq $expected.LocalSdkPath) "$($expected.Year) local SDK path mismatch"

        if ($expected.LocalSdkStatus -eq "present") {
            $sdkPath = Join-Path $script:RepositoryRoot $expected.LocalSdkPath
            Assert-Contract (Test-Path -LiteralPath $sdkPath -PathType Container) "$($expected.Year) local SDK path does not exist: $($expected.LocalSdkPath)"
        }

        $propsPath = Join-Path $script:RepositoryRoot "build/years/$($expected.Year)/AutoCAD-all-in-one.props"
        Assert-Contract (Test-Path -LiteralPath $propsPath -PathType Leaf) "missing year props for $($expected.Year)"
        [xml]$props = Get-Content -LiteralPath $propsPath -Raw
        $propsYear = [string]$props.Project.PropertyGroup.AutoCadPackageYear
        Assert-Contract ($propsYear -eq [string]$expected.Year) "$($expected.Year) props identity mismatch"
    }

    Write-Output "Metadata contract: PASS (9 years)"
}

function Get-SelectedYearContracts {
    $contracts = @(Get-ExpectedYearContracts)
    if ($Year -ne 0) {
        return @($contracts | Where-Object { $_.Year -eq $Year })
    }

    return $contracts
}

function Read-ZipEntryText {
    param(
        [Parameter(Mandatory = $true)]
        [System.IO.Compression.ZipArchiveEntry]$Entry
    )

    $reader = New-Object System.IO.StreamReader($Entry.Open())
    try {
        return $reader.ReadToEnd()
    }
    finally {
        $reader.Dispose()
    }
}

function Test-StaticPackageContract {
    $resolvedPackageDirectory = Join-Path $script:RepositoryRoot $PackageDirectory
    Assert-Contract (Test-Path -LiteralPath $resolvedPackageDirectory -PathType Container) "package directory is missing: $PackageDirectory"

    Add-Type -AssemblyName System.IO.Compression.FileSystem
    $binaryExtensions = @(".dll", ".exe", ".arx", ".dbx", ".lib", ".msi", ".zip", ".7z")
    $requiredEntries = @(
        "buildTransitive/AutoCAD-all-in-one.props",
        "buildTransitive/AutoCAD-all-in-one.targets",
        "README.md",
        "LICENSE",
        "THIRD-PARTY-NOTICES.md"
    )

    foreach ($expected in @(Get-SelectedYearContracts)) {
        $packagePath = Join-Path $resolvedPackageDirectory "AutoCAD-all-in-one.$($expected.WrapperVersion).nupkg"
        Assert-Contract (Test-Path -LiteralPath $packagePath -PathType Leaf) "missing package for $($expected.Year): $packagePath"

        $archive = [System.IO.Compression.ZipFile]::OpenRead($packagePath)
        try {
            $entryNames = @($archive.Entries | ForEach-Object { $_.FullName })
            $binaryEntries = @($archive.Entries | Where-Object {
                $binaryExtensions -contains [System.IO.Path]::GetExtension($_.FullName).ToLowerInvariant()
            })
            $binaryEntryNames = @($binaryEntries | ForEach-Object { $_.FullName })
            Assert-Contract ($binaryEntries.Count -eq 0) "$($expected.Year) package contains binary entries: $($binaryEntryNames -join ', ')"

            foreach ($requiredEntry in $requiredEntries) {
                Assert-Contract ($entryNames -contains $requiredEntry) "$($expected.Year) package is missing $requiredEntry"
            }

            $nuspecEntries = @($archive.Entries | Where-Object { $_.FullName -like "*.nuspec" })
            Assert-Contract ($nuspecEntries.Count -eq 1) "$($expected.Year) package must contain exactly one nuspec"

            $reader = New-Object System.IO.StreamReader($nuspecEntries[0].Open())
            try {
                [xml]$nuspec = $reader.ReadToEnd()
            }
            finally {
                $reader.Dispose()
            }

            $idNode = $nuspec.SelectSingleNode("//*[local-name()='metadata']/*[local-name()='id']")
            $versionNode = $nuspec.SelectSingleNode("//*[local-name()='metadata']/*[local-name()='version']")
            Assert-Contract ($null -ne $idNode -and $idNode.InnerText -eq "AutoCAD-all-in-one") "$($expected.Year) package ID mismatch"
            Assert-Contract ($null -ne $versionNode -and $versionNode.InnerText -eq $expected.WrapperVersion) "$($expected.Year) package version mismatch"

            $dependencyNodes = @($nuspec.SelectNodes("//*[local-name()='dependency'][@id='AutoCAD.NET']"))
            Assert-Contract ($dependencyNodes.Count -eq 1) "$($expected.Year) package must have exactly one AutoCAD.NET dependency"
            Assert-Contract ($dependencyNodes[0].version -eq "[$($expected.AutodeskPackageVersion)]") "$($expected.Year) AutoCAD.NET dependency must be exact $($expected.AutodeskPackageVersion)"

            $readmeEntry = $archive.GetEntry("README.md")
            $readmeText = Read-ZipEntryText -Entry $readmeEntry
            foreach ($requiredText in @("facade", "does not include Autodesk DLLs", "AutoCadVersion", 'PrivateAssets="all"', "live AutoCAD")) {
                Assert-Contract ($readmeText.IndexOf($requiredText, [System.StringComparison]::OrdinalIgnoreCase) -ge 0) "README is missing required text: $requiredText"
            }
            foreach ($yearContract in @(Get-ExpectedYearContracts)) {
                Assert-Contract ($readmeText.Contains([string]$yearContract.Year)) "README is missing AutoCAD $($yearContract.Year)"
                Assert-Contract ($readmeText.Contains($yearContract.AutodeskPackageVersion)) "README is missing AutoCAD.NET $($yearContract.AutodeskPackageVersion)"
            }

            $noticeEntry = $archive.GetEntry("THIRD-PARTY-NOTICES.md")
            $noticeText = Read-ZipEntryText -Entry $noticeEntry
            foreach ($requiredText in @("Autodesk", "AutoCAD.NET", "not included", "not endorsed")) {
                Assert-Contract ($noticeText.IndexOf($requiredText, [System.StringComparison]::OrdinalIgnoreCase) -ge 0) "third-party notice is missing required text: $requiredText"
            }
        }
        finally {
            $archive.Dispose()
        }

        Write-Output "Static package contract: PASS ($($expected.Year))"
    }
}

function Test-AutomationContract {
    $buildWorkflowPath = Join-Path $script:RepositoryRoot ".github/workflows/build.yml"
    $publishWorkflowPath = Join-Path $script:RepositoryRoot ".github/workflows/publish.yml"
    Assert-Contract (Test-Path -LiteralPath $buildWorkflowPath -PathType Leaf) "build workflow is missing"
    Assert-Contract (Test-Path -LiteralPath $publishWorkflowPath -PathType Leaf) "publish workflow is missing"

    $buildWorkflow = Get-Content -LiteralPath $buildWorkflowPath -Raw
    foreach ($requiredText in @("pull_request:", "push:", "matrix:", "actions/upload-artifact@v4", "build/Pack.ps1", "tests/package-contract.ps1")) {
        Assert-Contract ($buildWorkflow.Contains($requiredText)) "build workflow is missing: $requiredText"
    }
    foreach ($expectedYear in 2019..2027) {
        Assert-Contract ($buildWorkflow.Contains([string]$expectedYear)) "build workflow matrix is missing $expectedYear"
    }

    $publishWorkflow = Get-Content -LiteralPath $publishWorkflowPath -Raw
    foreach ($requiredText in @("tags:", "id-token: write", "NuGet/login@v1", "NUGET_API_KEY", "dotnet nuget push", "metadata/", "tests/package-contract.ps1")) {
        Assert-Contract ($publishWorkflow.Contains($requiredText)) "publish workflow is missing: $requiredText"
    }
    Assert-Contract (-not $publishWorkflow.Contains("NUGET_API_KEY:")) "publish workflow must not declare a long-lived NUGET_API_KEY secret"

    Write-Output "Automation contract: PASS"
}

function Invoke-DotNet {
    param(
        [Parameter(Mandatory = $true)]
        [string[]]$Arguments,
        [Parameter(Mandatory = $true)]
        [string]$WorkingDirectory
    )

    Push-Location $WorkingDirectory
    try {
        $output = & dotnet @Arguments 2>&1 | Out-String
        return [pscustomobject]@{
            ExitCode = $LASTEXITCODE
            Output = $output
        }
    }
    finally {
        Pop-Location
    }
}

function Test-ConsumerBuildContract {
    $resolvedPackageDirectory = [System.IO.Path]::GetFullPath((Join-Path $script:RepositoryRoot $PackageDirectory))

    foreach ($expected in @(Get-SelectedYearContracts)) {
        $workDirectory = Join-Path $script:RepositoryRoot ".test-work/$($expected.Year)"
        if (Test-Path -LiteralPath $workDirectory) {
            $resolvedWorkDirectory = [System.IO.Path]::GetFullPath($workDirectory)
            $resolvedTestRoot = [System.IO.Path]::GetFullPath((Join-Path $script:RepositoryRoot ".test-work"))
            Assert-Contract ($resolvedWorkDirectory.StartsWith($resolvedTestRoot, [System.StringComparison]::OrdinalIgnoreCase)) "refusing to clean an unexpected test path"
            Remove-Item -LiteralPath $resolvedWorkDirectory -Recurse -Force
        }
        [System.IO.Directory]::CreateDirectory($workDirectory) | Out-Null

        $projectPath = Join-Path $workDirectory "ConsumerProbe.csproj"
        $sourcePath = Join-Path $workDirectory "CompileProbe.cs"
        $escapedPackageSource = [System.Security.SecurityElement]::Escape($resolvedPackageDirectory)
        $projectContent = @"
<Project Sdk="Microsoft.NET.Sdk">
  <PropertyGroup>
    <TargetFramework>$($expected.TargetFramework)</TargetFramework>
    <AutoCadVersion>$($expected.Year)</AutoCadVersion>
    <RestoreSources>$escapedPackageSource;https://api.nuget.org/v3/index.json</RestoreSources>
    <RestorePackagesPath>$(Join-Path $workDirectory 'packages')</RestorePackagesPath>
  </PropertyGroup>
  <ItemGroup>
    <PackageReference Include="AutoCAD-all-in-one" Version="[$($expected.WrapperVersion)]" PrivateAssets="all" />
  </ItemGroup>
</Project>
"@
        $sourceContent = @"
using Autodesk.AutoCAD.Runtime;

internal static class CompileProbe
{
#if !AUTOCAD$($expected.Year)
#error Expected AutoCAD year constant was not defined.
#endif
    internal static readonly System.Type CommandAttributeType = typeof(CommandMethodAttribute);
}
"@
        [System.IO.File]::WriteAllText($projectPath, $projectContent, [System.Text.UTF8Encoding]::new($false))
        [System.IO.File]::WriteAllText($sourcePath, $sourceContent, [System.Text.UTF8Encoding]::new($false))

        $build = Invoke-DotNet -WorkingDirectory $workDirectory -Arguments @(
            "build", $projectPath, "--configuration", "Release", "--nologo"
        )
        Assert-Contract ($build.ExitCode -eq 0) "$($expected.Year) consumer build failed:`n$($build.Output)"

        $restoredPackageDirectory = Join-Path $workDirectory "packages"
        $autodeskPackageDirectories = @(Get-ChildItem -LiteralPath $restoredPackageDirectory -Directory | Where-Object {
            $_.Name -eq "autocad.net" -or $_.Name -eq "autocad.net.core" -or $_.Name -eq "autocad.net.model"
        })
        $autodeskAssemblyFiles = @($autodeskPackageDirectories | ForEach-Object {
            Get-ChildItem -LiteralPath $_.FullName -Filter "*.dll" -File -Recurse
        })
        $hostAssemblyNames = @($autodeskAssemblyFiles | Select-Object -ExpandProperty Name -Unique)
        Assert-Contract ($hostAssemblyNames.Count -gt 0) "$($expected.Year) test could not discover Autodesk host assemblies from restored packages"

        $outputDirectory = Join-Path $workDirectory "bin/Release/$($expected.TargetFramework)"
        $copiedHostAssemblies = @(Get-ChildItem -LiteralPath $outputDirectory -File -Recurse | Where-Object {
            $hostAssemblyNames -contains $_.Name
        })
        $copiedHostAssemblyPaths = @($copiedHostAssemblies | ForEach-Object { $_.FullName })
        Assert-Contract ($copiedHostAssemblies.Count -eq 0) "$($expected.Year) consumer output contains AutoCAD host DLLs: $($copiedHostAssemblyPaths -join ', ')"

        $mismatchYear = if ($expected.Year -eq 2024) { 2023 } else { 2024 }
        $mismatch = Invoke-DotNet -WorkingDirectory $workDirectory -Arguments @(
            "build", $projectPath, "--configuration", "Release", "--nologo", "-p:AutoCadVersion=$mismatchYear"
        )
        $expectedDiagnostic = "AutoCAD-all-in-one year mismatch: package targets $($expected.Year), project requests $mismatchYear."
        Assert-Contract ($mismatch.ExitCode -ne 0) "$($expected.Year) mismatched consumer build unexpectedly succeeded"
        Assert-Contract ($mismatch.Output.Contains($expectedDiagnostic)) "$($expected.Year) mismatch diagnostic was not found:`n$($mismatch.Output)"

        Write-Output "Consumer build contract: PASS ($($expected.Year))"
    }
}

try {
    Test-MetadataContract
    if ($MetadataOnly) {
        exit 0
    }

    Test-StaticPackageContract
    Test-AutomationContract
    if (-not $SkipConsumerBuild) {
        Test-ConsumerBuildContract
    }
}
catch {
    Write-Error $_
    exit 1
}
