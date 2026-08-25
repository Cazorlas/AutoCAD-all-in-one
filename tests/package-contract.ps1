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

try {
    Test-MetadataContract
    if (-not $MetadataOnly) {
        throw "Package contract modes are not implemented yet."
    }
}
catch {
    Write-Error $_
    exit 1
}
