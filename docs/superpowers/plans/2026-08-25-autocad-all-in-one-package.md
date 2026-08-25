# AutoCAD-all-in-one Package Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Build and verify nine public-ready `AutoCAD-all-in-one` facade NuGet package lines for AutoCAD 2019–2027 without repackaging Autodesk binaries.

**Architecture:** A single SDK-style pack project selects one year, framework, wrapper version, and exact official `AutoCAD.NET` dependency. A year-specific `.props` file carries the selected year into consumers while one common `buildTransitive` target validates configuration, defines `AUTOCAD<year>`, and removes AutoCAD host assemblies from copy-local output. PowerShell contract tests inspect packages and build temporary consumers.

**Tech Stack:** MSBuild/.NET SDK, NuGet, PowerShell, GitHub Actions on Windows, official Autodesk `AutoCAD.NET` packages.

## Global Constraints

- Public package ID is exactly `AutoCAD-all-in-one`.
- Wrapper lines are `2019.0.1` through `2027.0.1`, with exact Autodesk mappings from the approved design spec.
- Produced packages contain no DLL, EXE, native binary, ObjectARX archive, or copied Autodesk XML documentation.
- AutoCAD 2019–2024 consumers use .NET Framework; 2025 uses .NET 8 Windows; 2026 Update 1.2+ and 2027 use .NET 10 Windows.
- Existing `libs/ObjectARX_Cad*` content remains untouched and is never packed.
- Publishing, tagging, pushing, and `Paper.AutoCad` migration are outside this implementation plan.
- Every build claim must come from a fresh command; runtime AutoCAD compatibility remains unclaimed until live-host testing.

---

## File Map

- `AutoCADAllInOne/AutoCADAllInOne.csproj`: package identity, year-to-framework/dependency mapping, and pack file selection.
- `build/Pack.ps1`: validated single-year/all-year pack entry point.
- `build/AutoCAD-all-in-one.targets`: shared consumer validation, constants, and copy-local filtering.
- `build/years/<year>/AutoCAD-all-in-one.props`: immutable package-year identity imported into consumers.
- `metadata/<year>.json`: machine-readable public compatibility and local SDK status.
- `tests/package-contract.ps1`: nupkg structure, dependency, consumer compilation, mismatch, and output checks.
- `.github/workflows/build.yml`: PR/main nine-year verification matrix.
- `.github/workflows/publish.yml`: explicit version-tag, single-line NuGet trusted publishing.
- `README.md`: public consumer and maintainer documentation.
- `THIRD-PARTY-NOTICES.md`: Autodesk dependency/provenance notice.
- `.gitignore`: only generated bin/obj/artifact/test-work directories.

### Task 1: Packaging metadata and year identity

**Files:**
- Create: `metadata/2019.json` through `metadata/2027.json`
- Create: `build/years/2019/AutoCAD-all-in-one.props` through `build/years/2027/AutoCAD-all-in-one.props`
- Create: `tests/package-contract.ps1`

**Interfaces:**
- Consumes: approved year/dependency/framework/local-SDK table from the design spec.
- Produces: JSON properties `year`, `wrapperVersion`, `autodeskPackageVersion`, `targetFramework`, `localSdkStatus`, `localSdkPath`; MSBuild property `AutoCadPackageYear`.

- [ ] **Step 1: Write the failing metadata test**

Add a `-MetadataOnly` mode that enumerates exactly nine JSON files, validates the exact mapping below, checks that every `present` local path exists, and verifies each year props file has the matching `AutoCadPackageYear`.

- [ ] **Step 2: Run it to verify failure**

```powershell
pwsh -NoProfile -File .\tests\package-contract.ps1 -MetadataOnly
```

Expected: non-zero because metadata and props do not yet exist.

- [ ] **Step 3: Add exact metadata and props**

```text
2019|2019.0.1|23.0.0|net47|missing|
2020|2020.0.1|23.1.0|net47|present|libs/ObjectARX_Cad20
2021|2021.0.1|24.0.0|net47|missing|
2022|2022.0.1|24.1.51000|net47|missing|
2023|2023.0.1|24.2.0|net47|present|libs/ObjectARX_Cad23
2024|2024.0.1|24.3.0|net48|present|libs/ObjectARX_Cad24
2025|2025.0.1|25.0.1|net8.0-windows|present|libs/ObjectARX_Cad25
2026|2026.0.1|25.1.1|net10.0-windows|present|libs/ObjectARX_Cad26
2027|2027.0.1|26.0.0|net10.0-windows|present|libs/ObjectARX_Cad27
```

Each props file has this shape, substituting its own year:

```xml
<Project>
  <PropertyGroup>
    <AutoCadPackageYear>2024</AutoCadPackageYear>
  </PropertyGroup>
</Project>
```

- [ ] **Step 4: Run the metadata test to verify pass**

Expected: `Metadata contract: PASS (9 years)` and exit code 0.

- [ ] **Step 5: Commit**

```powershell
git add metadata build/years tests/package-contract.ps1
git commit -m "test: define AutoCAD package year contract"
```

### Task 2: Facade package project and pack command

**Files:**
- Create: `AutoCADAllInOne/AutoCADAllInOne.csproj`
- Create: `build/Pack.ps1`
- Create: `.gitignore`
- Modify: `tests/package-contract.ps1`

**Interfaces:**
- Consumes: Task 1 metadata and props.
- Produces: `build/Pack.ps1 -Year <2019..2027> -OutputDirectory <path>` and `-All`; package `AutoCAD-all-in-one.<wrapperVersion>.nupkg`.

- [ ] **Step 1: Add a failing static package test**

For each year, open the nupkg with `System.IO.Compression.ZipFile`, assert zero binary extensions, parse one nuspec for exact ID/version/`AutoCAD.NET` dependency, and require:

```text
buildTransitive/AutoCAD-all-in-one.props
README.md
LICENSE
```

- [ ] **Step 2: Verify packing fails**

```powershell
pwsh -NoProfile -File .\build\Pack.ps1 -Year 2024 -OutputDirectory .\artifacts\packages
```

Expected: non-zero because `build/Pack.ps1` does not exist.

- [ ] **Step 3: Implement minimal package project and script**

The project sets package identity/readme/license, `IncludeBuildOutput=false`, `SuppressDependenciesWhenPacking=false`, target framework, exact Autodesk dependency, and packs only repository-owned content. The script validates the year, reads metadata, and invokes:

```powershell
dotnet pack .\AutoCADAllInOne\AutoCADAllInOne.csproj `
  --configuration Release `
  --output .\artifacts\packages `
  -p:AutoCadVersion=2024 `
  -p:PackageVersion=2024.0.1 `
  -p:AutoCadSdkPackageVersion=24.3.0
```

- [ ] **Step 4: Pack and statically test 2024**

```powershell
pwsh -NoProfile -File .\tests\package-contract.ps1 -Year 2024 -PackageDirectory .\artifacts\packages -SkipConsumerBuild
```

Expected: one package and all static checks pass.

- [ ] **Step 5: Commit**

```powershell
git add AutoCADAllInOne build/Pack.ps1 .gitignore tests/package-contract.ps1
git commit -m "feat: pack year-specific AutoCAD facade"
```

### Task 3: Consumer build safeguards

**Files:**
- Create: `build/AutoCAD-all-in-one.targets`
- Modify: `tests/package-contract.ps1`

**Interfaces:**
- Consumes: `AutoCadPackageYear` and dependency references.
- Produces: `AUTOCAD<year>`, an exact mismatch error, and zero AutoCAD host DLLs in consumer output.

- [ ] **Step 1: Add failing consumer tests**

First require `buildTransitive/AutoCAD-all-in-one.targets` in the static package contract. Then generate a temporary consumer using Autodesk's `CommandMethodAttribute`, require the selected `AUTOCAD<year>` constant, build it, and reject any output named `AcCoreMgd.dll`, `AcDbMgd.dll`, `AcMgd.dll`, `AcCui.dll`, `AcWindows.dll`, `AdWindows.dll`, or `acdbmgdbrep.dll`. Build once more with another `AutoCadVersion` and require:

```text
AutoCAD-all-in-one year mismatch: package targets <package>, project requests <project>.
```

- [ ] **Step 2: Confirm failure before targets exist**

```powershell
pwsh -NoProfile -File .\tests\package-contract.ps1 -Year 2024 -PackageDirectory .\artifacts\packages
```

Expected: FAIL on constant, copy-local, or mismatch checks.

- [ ] **Step 3: Implement common buildTransitive targets**

Define `AUTOCAD$(AutoCadPackageYear)`, validate `AutoCadVersion`, and after reference resolution remove filenames matching this case-insensitive expression from `ReferenceCopyLocalPaths`:

```regex
^(accoremgd|acdbmgd|acmgd|accui|acwindows|adwindows|acdbmgdbrep)$
```

- [ ] **Step 4: Repack and verify 2024 consumer behavior**

Run the Task 2 pack command and Task 3 test command. Expected: all checks pass.

- [ ] **Step 5: Commit**

```powershell
git add build/AutoCAD-all-in-one.targets tests/package-contract.ps1
git commit -m "feat: enforce AutoCAD consumer build contract"
```

### Task 4: Public documentation and automation

**Files:**
- Modify: `README.md`
- Create: `THIRD-PARTY-NOTICES.md`
- Create: `.github/workflows/build.yml`
- Create: `.github/workflows/publish.yml`
- Modify: `tests/package-contract.ps1`

**Interfaces:**
- Consumes: pack and test scripts.
- Produces: public usage docs, unpublished CI artifacts, and tag-selected trusted publishing.

- [ ] **Step 1: Add failing documentation assertions**

Require `THIRD-PARTY-NOTICES.md` in the package, plus the facade/no-binary rule, full year table, `AutoCadVersion`, `PrivateAssets="all"`, build-versus-live validation distinction, Autodesk attribution, and official dependency name.

- [ ] **Step 2: Verify failure against current README**

Run the 2024 static package test. Expected: FAIL.

- [ ] **Step 3: Write README and third-party notice**

Document installation, mapping, frameworks, safeguards, local SDK status, maintainer commands, runtime-validation boundary, and independent/non-endorsed status.

- [ ] **Step 4: Add CI and publish workflows**

`build.yml` uses a Windows 2019–2027 matrix and uploads unpublished nupkgs. `publish.yml` accepts only `vYYYY.0.PATCH`, validates the tag against metadata, retests one package, and uses NuGet.org trusted/OIDC publishing without a repository API key.

- [ ] **Step 5: Verify documentation, workflows, and 2024 contract**

Parse both files with PowerShell `ConvertFrom-Yaml` when installed; otherwise assert their required triggers, matrix years, commands, artifact action, NuGet login action, and push command with `Select-String`. Then rerun the 2024 test. Expected: PASS.

- [ ] **Step 6: Commit**

```powershell
git add README.md THIRD-PARTY-NOTICES.md .github tests/package-contract.ps1
git commit -m "docs: add public package and release workflow"
```

### Task 5: Nine-year verification and review

**Files:**
- Modify only files directly required by verification failures.
- Update: this plan's checkbox state.

**Interfaces:**
- Consumes: all previous tasks.
- Produces: nine locally verified, unpublished packages and an evidence-backed handoff.

- [ ] **Step 1: Pack all years**

```powershell
pwsh -NoProfile -File .\build\Pack.ps1 -All -OutputDirectory .\artifacts\packages
```

Expected: exactly nine nupkgs from `2019.0.1` through `2027.0.1`.

- [ ] **Step 2: Run all contracts**

```powershell
pwsh -NoProfile -File .\tests\package-contract.ps1 -PackageDirectory .\artifacts\packages
```

Expected: metadata, nine manifests, nine compile probes/constants/mismatch diagnostics, and nine zero-host-DLL checks pass. If a required SDK/targeting pack is unavailable, report the precise environmental gap and do not claim that consumer line as verified.

- [ ] **Step 3: Run hygiene checks**

```powershell
git diff --check
git status --short
git ls-files artifacts bin obj
```

Expected: no whitespace error, generated output ignored, and only intentional source changes.

- [ ] **Step 4: Review scope and package contents**

Confirm `libs` is unchanged, no package contains a binary, workflows contain no credential, and no push/tag/publish command ran.

- [ ] **Step 5: Commit verification fixes only when needed**

Stage the explicit source paths reported by `git status --short`, excluding generated artifacts, and commit them with `git commit -m "fix: satisfy AutoCAD package contracts"`. Skip this step when verification required no source correction.

## Completion Boundary

The plan is complete when nine unpublished facade packages are produced, all static contracts pass, all locally supportable consumer builds pass, the worktree is clean, and any runtime/SDK gaps are stated exactly. The next plan migrates `Paper.AutoCad` 2024 and implements DB/F5, RL deployment, and `0.Deployment`.
