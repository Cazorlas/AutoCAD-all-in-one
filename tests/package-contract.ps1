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
        [pscustomobject]@{ Year = 2026; WrapperVersion = "2026.0.1"; AutodeskPackageVersion = "25.1.1"; TargetFramework = "net8.0-windows"; LocalSdkStatus = "present"; LocalSdkPath = "libs/ObjectARX_Cad26" }
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

function Test-StaticPackageContract {
    $resolvedPackageDirectory = Join-Path $script:RepositoryRoot $PackageDirectory
    Assert-Contract (Test-Path -LiteralPath $resolvedPackageDirectory -PathType Container) "package directory is missing: $PackageDirectory"

    Add-Type -AssemblyName System.IO.Compression.FileSystem
    $binaryExtensions = @(".dll", ".exe", ".arx", ".dbx", ".lib", ".msi", ".zip", ".7z")
    $requiredEntries = @(
        "buildTransitive/AutoCAD-all-in-one.props",
        "README.md",
        "LICENSE"
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
        }
        finally {
            $archive.Dispose()
        }

        Write-Output "Static package contract: PASS ($($expected.Year))"
    }
}

try {
    Test-MetadataContract
    if ($MetadataOnly) {
        exit 0
    }

    Test-StaticPackageContract
    if (-not $SkipConsumerBuild) {
        throw "Consumer build contract is not implemented yet."
    }
}
catch {
    Write-Error $_
    exit 1
}
