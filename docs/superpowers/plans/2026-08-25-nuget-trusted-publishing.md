# NuGet Trusted Publishing Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Publish exactly one `.csproj`-selected `AutoCAD-all-in-one` package from a matching Git tag through NuGet.org Trusted Publishing.

**Architecture:** `AutoCADAllInOne.csproj` supplies the public release year and version. The tag workflow evaluates those MSBuild properties, rejects mismatches, builds and validates the package, then exchanges GitHub OIDC for a short-lived NuGet credential immediately before the push. The existing metadata-driven 2019-2027 build matrix remains independent and unpublished.

**Tech Stack:** SDK-style MSBuild, PowerShell 5.1/7, GitHub Actions, `NuGet/login@v1`, NuGet.org OIDC trusted publishing.

## Global Constraints

- Local `Debug` and `Release` builds must never publish externally.
- Pushes and pull requests must keep running the unpublished 2019-2027 matrix.
- Only a tag matching `vYYYY.0.PATCH` may start public publishing.
- `AutoCadVersion` and `PackageVersion` from `AutoCADAllInOne.csproj` are authoritative for a public release.
- The workflow must test before requesting a NuGet credential.
- No long-lived NuGet API key may enter source, configuration, or logs.
- Do not add `--skip-duplicate`; a duplicate version must fail visibly.
- Implementation and local verification must not create a Git tag or publish a package.

## File Map

- Modify `AutoCADAllInOne/AutoCADAllInOne.csproj`: make the release version visibly editable while retaining command-line overrides used by the matrix.
- Modify `tests/package-contract.ps1`: allow a selected public-release package version to override the metadata version and assert the new workflow contract.
- Modify `.github/workflows/publish.yml`: evaluate `.csproj` release properties, validate the tag, build, test, log in with OIDC, and push one package.
- Modify `README.md`: document one-time NuGet/GitHub configuration and the tag release procedure.
- Reference `docs/superpowers/specs/2026-08-25-nuget-trusted-publishing-design.md`: approved behavior and boundaries.

---

### Task 1: Make `.csproj` Release Inputs Explicit and Testable

**Files:**
- Modify: `AutoCADAllInOne/AutoCADAllInOne.csproj`
- Modify: `tests/package-contract.ps1`

**Interfaces:**
- Consumes: existing `AutoCadVersion`, `PackageVersion`, `Year`, and `PackageDirectory` inputs.
- Produces: `ExpectedPackageVersion` string parameter for validating a public-release artifact independently of `metadata/<year>.json`.

- [ ] **Step 1: Create an alternate-version package that demonstrates the missing test interface**

Run from the repository root:

```powershell
$testRoot = '.\artifacts\verification\release-contract-red-' + [System.Guid]::NewGuid().ToString('N')
New-Item -ItemType Directory -Path $testRoot -Force | Out-Null
dotnet pack .\AutoCADAllInOne\AutoCADAllInOne.csproj --configuration Release --output $testRoot -p:AutoCadVersion=2024 -p:PackageVersion=2024.0.2
powershell -NoProfile -ExecutionPolicy Bypass -File .\tests\package-contract.ps1 -Year 2024 -ExpectedPackageVersion 2024.0.2 -PackageDirectory $testRoot -SkipConsumerBuild
```

Expected: packing succeeds, then the contract command fails because `ExpectedPackageVersion` is not yet a recognized parameter.

- [ ] **Step 2: Add the public-release version parameter**

Add this parameter after `PackageDirectory` in `tests/package-contract.ps1`:

```powershell
[ValidatePattern('^(2019|202[0-7])\.0\.[1-9][0-9]*$')]
[string]$ExpectedPackageVersion,
```

Replace `Get-SelectedYearContracts` with:

```powershell
function Get-SelectedYearContracts {
    $contracts = @(Get-ExpectedYearContracts)
    $selectedContracts = if ($Year -ne 0) {
        @($contracts | Where-Object { $_.Year -eq $Year })
    }
    else {
        $contracts
    }

    if (-not [string]::IsNullOrWhiteSpace($ExpectedPackageVersion)) {
        Assert-Contract ($Year -ne 0) "ExpectedPackageVersion requires one selected Year"
        Assert-Contract ($ExpectedPackageVersion.StartsWith("$Year.", [System.StringComparison]::Ordinal)) "expected package version '$ExpectedPackageVersion' does not belong to AutoCAD $Year"
        $selectedContracts[0].WrapperVersion = $ExpectedPackageVersion
    }

    return $selectedContracts
}
```

- [ ] **Step 3: Make the default release version explicit in the project**

Replace:

```xml
<PackageVersion Condition="'$(PackageVersion)' == ''">$(AutoCadVersion).0.1</PackageVersion>
```

with:

```xml
<PackageVersion Condition="'$(PackageVersion)' == ''">2024.0.1</PackageVersion>
```

This remains overrideable by `Pack.ps1` and CI through `-p:PackageVersion=...`, while giving the maintainer one literal value to edit before a public release.

- [ ] **Step 4: Verify the alternate-version contract passes**

Re-run the Step 1 commands with a new relative directory under `artifacts/verification`.

Expected output includes:

```text
Metadata contract: PASS (9 years)
Static package contract: PASS (2024)
Automation contract: PASS
```

Expected exit code: `0`.

- [ ] **Step 5: Verify invalid public-release input fails clearly**

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\tests\package-contract.ps1 -Year 2024 -ExpectedPackageVersion 2025.0.2 -PackageDirectory $testRoot -SkipConsumerBuild
```

Expected: nonzero exit with `expected package version '2025.0.2' does not belong to AutoCAD 2024`.

- [ ] **Step 6: Save the increment after authorization**

```powershell
git add AutoCADAllInOne/AutoCADAllInOne.csproj tests/package-contract.ps1
git commit -m "test: support explicit NuGet release versions"
```

Expected: one atomic commit containing only the release input and package-contract changes. Do not commit unless the user has authorized commits for this implementation.

---

### Task 2: Make the Tag Workflow Read `.csproj` and Publish One Validated Package

**Files:**
- Modify: `tests/package-contract.ps1`
- Modify: `.github/workflows/publish.yml`

**Interfaces:**
- Consumes: evaluated MSBuild properties `AutoCadVersion` and `PackageVersion`, plus GitHub `github.ref_name` and repository variable `NUGET_USER`.
- Produces: workflow step outputs `year` and `version`, one verified `.nupkg`, and one OIDC-authenticated NuGet push.

- [ ] **Step 1: Strengthen the workflow contract before editing the workflow**

In `Test-AutomationContract`, replace the publish-workflow requirements with:

```powershell
foreach ($requiredText in @(
    "tags:",
    "id-token: write",
    "NuGet/login@v1",
    "NUGET_API_KEY",
    "dotnet nuget push",
    "AutoCADAllInOne/AutoCADAllInOne.csproj",
    "-getProperty:AutoCadVersion",
    "-getProperty:PackageVersion",
    "dotnet build",
    "ExpectedPackageVersion",
    "tests/package-contract.ps1"
)) {
    Assert-Contract ($publishWorkflow.Contains($requiredText)) "publish workflow is missing: $requiredText"
}
Assert-Contract (-not $publishWorkflow.Contains("metadata/")) "publish workflow must not take the public release version from metadata"
Assert-Contract (-not $publishWorkflow.Contains("--skip-duplicate")) "publish workflow must surface duplicate package versions"
Assert-Contract (-not $publishWorkflow.Contains("NUGET_API_KEY:")) "publish workflow must not declare a long-lived NUGET_API_KEY secret"
```

- [ ] **Step 2: Run the focused contract and verify it fails for the old workflow**

```powershell
$testRoot = '.\artifacts\verification\publish-workflow-red-' + [System.Guid]::NewGuid().ToString('N')
New-Item -ItemType Directory -Path $testRoot -Force | Out-Null
dotnet pack .\AutoCADAllInOne\AutoCADAllInOne.csproj --configuration Release --output $testRoot
powershell -NoProfile -ExecutionPolicy Bypass -File .\tests\package-contract.ps1 -Year 2024 -ExpectedPackageVersion 2024.0.1 -PackageDirectory $testRoot -SkipConsumerBuild
```

Expected: failure naming the first missing `.csproj`-driven workflow string.

- [ ] **Step 3: Replace the tag validation and package creation steps**

Keep the trigger, checkout, SDK installation, OIDC login, and push boundary. Replace the current metadata-driven validation, pack, and verify steps in `.github/workflows/publish.yml` with:

```yaml
      - name: Read and validate release
        id: release
        shell: powershell
        run: |
          $projectPath = "AutoCADAllInOne/AutoCADAllInOne.csproj"
          $tag = "${{ github.ref_name }}"

          if ($tag -notmatch '^v(?<year>2019|202[0-7])\.0\.(?<patch>[1-9][0-9]*)$') {
            throw "Tag '$tag' must match vYYYY.0.PATCH for AutoCAD 2019-2027."
          }
          $tagYear = $Matches.year

          $year = (& dotnet msbuild $projectPath -nologo -getProperty:AutoCadVersion).Trim()
          if ($LASTEXITCODE -ne 0) {
            throw "Could not evaluate AutoCadVersion from $projectPath."
          }

          $version = (& dotnet msbuild $projectPath -nologo -getProperty:PackageVersion).Trim()
          if ($LASTEXITCODE -ne 0) {
            throw "Could not evaluate PackageVersion from $projectPath."
          }

          if ($year -ne $tagYear) {
            throw "Tag year '$tagYear' does not match AutoCadVersion '$year'."
          }
          if ($tag -ne "v$version") {
            throw "Tag '$tag' does not match PackageVersion '$version'."
          }

          "year=$year" | Out-File -FilePath $env:GITHUB_OUTPUT -Encoding utf8 -Append
          "version=$version" | Out-File -FilePath $env:GITHUB_OUTPUT -Encoding utf8 -Append

      - name: Build selected facade
        shell: powershell
        run: dotnet build ./AutoCAD-all-in-one.sln --configuration Release --nologo

      - name: Verify selected package and consumer
        shell: powershell
        run: ./tests/package-contract.ps1 -Year ${{ steps.release.outputs.year }} -ExpectedPackageVersion ${{ steps.release.outputs.version }} -PackageDirectory ./artifacts/packages
```

The existing publish step must remain:

```yaml
      - name: NuGet login with OIDC
        uses: NuGet/login@v1
        id: login
        with:
          user: ${{ vars.NUGET_USER }}

      - name: Publish to NuGet.org
        shell: powershell
        run: |
          $packages = @(Get-ChildItem -LiteralPath .\artifacts\packages -Filter *.nupkg -File)
          if ($packages.Count -ne 1) {
            throw "Expected exactly one package to publish, found $($packages.Count)."
          }

          dotnet nuget push $packages[0].FullName --api-key "${{ steps.login.outputs.NUGET_API_KEY }}" --source https://api.nuget.org/v3/index.json
```

- [ ] **Step 4: Re-run the focused package and automation contract**

Repeat the Step 2 commands with a new temporary directory.

Expected output includes `Automation contract: PASS` and exit code `0`.

- [ ] **Step 5: Verify MSBuild returns the exact release inputs used by the workflow**

```powershell
$year = (& dotnet msbuild .\AutoCADAllInOne\AutoCADAllInOne.csproj -nologo -getProperty:AutoCadVersion).Trim()
$version = (& dotnet msbuild .\AutoCADAllInOne\AutoCADAllInOne.csproj -nologo -getProperty:PackageVersion).Trim()
"YEAR=$year"
"VERSION=$version"
```

Expected:

```text
YEAR=2024
VERSION=2024.0.1
```

- [ ] **Step 6: Save the workflow increment after authorization**

```powershell
git add tests/package-contract.ps1 .github/workflows/publish.yml
git commit -m "ci: publish NuGet release from project version"
```

Expected: one atomic commit containing the workflow contract and implementation. Do not push a tag.

---

### Task 3: Document Setup and Run the Full Non-Publishing Verification

**Files:**
- Modify: `README.md`
- Verify: `build/Pack.ps1`
- Verify: `tests/package-contract.ps1`
- Verify: `.github/workflows/build.yml`
- Verify: `.github/workflows/publish.yml`

**Interfaces:**
- Consumes: repository variable `NUGET_USER`, NuGet.org Trusted Publishing policy, and release tag `v$(PackageVersion)`.
- Produces: a repeatable maintainer release checklist and complete local evidence without an external publish.

- [ ] **Step 1: Demonstrate the setup instructions are absent**

```powershell
rg -n "Trusted Publishing|NUGET_USER|git tag v2024\.0\.1|publish\.yml" README.md
```

Expected: at least one required release instruction is absent.

- [ ] **Step 2: Add the one-time deployment setup to `README.md`**

Add a `Publish to NuGet.org` section after `Build and verify locally` containing these exact operational facts:

````markdown
## Publish to NuGet.org

Local builds never publish. Public releases are triggered only by a matching Git tag and use NuGet.org Trusted Publishing with GitHub OIDC.

One-time setup:

1. In NuGet.org, open the account's Trusted Publishing page and add a GitHub policy.
2. Set repository owner to `Cazorlas`, repository to `AutoCAD-all-in-one`, workflow file to `publish.yml`, and leave environment empty.
3. In GitHub repository Actions variables, set `NUGET_USER` to the NuGet.org profile username, not an email address.

For each release:

1. Edit `AutoCadVersion` and `PackageVersion` in `AutoCADAllInOne/AutoCADAllInOne.csproj`.
2. Build `Release` and run the focused package contract.
3. Commit and push the release change, then wait for the main build workflow to pass.
4. Create and push the exact matching tag:

```powershell
git tag v2024.0.1
git push origin v2024.0.1
```

The tag workflow builds and tests exactly one package before requesting a short-lived NuGet credential. Duplicate versions fail visibly and are not skipped.
````

- [ ] **Step 3: Verify Debug and Release behavior through the solution**

```powershell
$testRoot = Join-Path (Get-Location) ('.\artifacts\verification\release-final-' + [System.Guid]::NewGuid().ToString('N'))
$debugPackages = Join-Path $testRoot 'debug'
$releasePackages = Join-Path $testRoot 'release'
New-Item -ItemType Directory -Path $debugPackages, $releasePackages -Force | Out-Null

dotnet build .\AutoCAD-all-in-one.sln --configuration Debug --nologo -p:PackageOutputPath=$debugPackages
if (@(Get-ChildItem -LiteralPath $debugPackages -Filter *.nupkg -File).Count -ne 0) { throw 'Debug unexpectedly created a package.' }

dotnet build .\AutoCAD-all-in-one.sln --configuration Release --nologo -p:PackageOutputPath=$releasePackages
$packages = @(Get-ChildItem -LiteralPath $releasePackages -Filter *.nupkg -File)
if ($packages.Count -ne 1 -or $packages[0].Name -ne 'AutoCAD-all-in-one.2024.0.1.nupkg') { throw 'Release did not create exactly the expected package.' }
```

Expected: both builds succeed with zero warnings and zero errors; Debug produces no package; Release produces one `AutoCAD-all-in-one.2024.0.1.nupkg`.

- [ ] **Step 4: Run the complete all-year package contract**

```powershell
$allPackages = '.\artifacts\verification\all-years-' + [System.Guid]::NewGuid().ToString('N')
powershell -NoProfile -ExecutionPolicy Bypass -File .\build\Pack.ps1 -All -OutputDirectory $allPackages
powershell -NoProfile -ExecutionPolicy Bypass -File .\tests\package-contract.ps1 -PackageDirectory $allPackages
```

Expected:

- Nine packages are created for AutoCAD 2019-2027.
- Metadata, static package, automation, and consumer build contracts all pass.
- No command pushes to NuGet.org.

- [ ] **Step 5: Perform final repository checks**

```powershell
git diff --check
git status --short
git diff -- AutoCADAllInOne/AutoCADAllInOne.csproj tests/package-contract.ps1 .github/workflows/publish.yml README.md docs/superpowers/specs/2026-08-25-nuget-trusted-publishing-design.md docs/superpowers/plans/2026-08-25-nuget-trusted-publishing.md
```

Expected: no whitespace errors; only the approved publishing files and documentation are changed.

- [ ] **Step 6: Save the documentation after authorization**

```powershell
git add README.md docs/superpowers/specs/2026-08-25-nuget-trusted-publishing-design.md docs/superpowers/plans/2026-08-25-nuget-trusted-publishing.md
git commit -m "docs: explain trusted NuGet publishing"
```

Expected: documentation is committed separately from workflow behavior. Do not push `main`, create a release tag, or publish until the user explicitly requests those external actions.

## External Activation Checklist

Repository implementation cannot perform these authenticated account steps automatically:

- [ ] Sign in to NuGet.org and create the Trusted Publishing policy defined in the spec.
- [ ] Add GitHub Actions repository variable `NUGET_USER` with the NuGet.org profile username.
- [ ] Push the verified implementation commits to `main` when authorized.
- [ ] Confirm the `Build packages` workflow passes on `main`.
- [ ] Push the first release tag only after confirming its package ID and version.
- [ ] Confirm the `Publish package` workflow succeeds and the NuGet.org package page is visible.
