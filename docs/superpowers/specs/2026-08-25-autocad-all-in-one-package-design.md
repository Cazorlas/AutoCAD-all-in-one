# AutoCAD-all-in-one Public NuGet Package Design

**Date:** 2026-08-25

**Status:** Approved design, awaiting written-spec review

**Repository:** `D:\Repository\Cazorlas\AutoCAD-all-in-one`

## 1. Goal

Create a public NuGet package family that gives Paper and other AutoCAD add-in projects one stable dependency name for AutoCAD managed API references from AutoCAD 2019 through 2027.

The first consumer will be `Paper.AutoCad`. AutoCAD 2024 is the first fully integrated and runtime-validated host, while the package architecture must already define an unambiguous path for 2019–2027.

Success means a consumer can choose an AutoCAD year, restore the matching official Autodesk managed API package, compile against it, and avoid copying Autodesk host assemblies into its build or deployment output.

## 2. Scope

This workstream includes:

- A public facade/meta package named `AutoCAD-all-in-one`.
- One wrapper release line per AutoCAD year from 2019 through 2027.
- Exact dependency mapping to Autodesk's official `AutoCAD.NET` packages.
- Transitive MSBuild safeguards for year selection and host-DLL copy prevention.
- Package contract tests and public build/publish workflows.
- Documentation, licensing attribution, and local ObjectARX inventory metadata.

This workstream does not include:

- Republishing Autodesk DLLs inside our `.nupkg`.
- Publishing a package or tag during implementation without a separate explicit instruction.
- Migrating `Paper.AutoCad` during this package workstream.
- Implementing `Paper.AutoCad` DB/F5 launch, RL auto-deployment, `0.Deployment`, or its installer. Those remain the next workstream after this package is accepted and verified.
- Claiming runtime compatibility for a host year based only on restore/build success. AutoCAD runtime validation is a separate gate.

## 3. Chosen Architecture

### 3.1 Decision

`AutoCAD-all-in-one` is a thin public facade over Autodesk's official `AutoCAD.NET` NuGet package. It owns selection, validation, build behavior, documentation, and tests; Autodesk continues to own and distribute its binaries.

Each wrapper version selects exactly one Autodesk dependency version. The package contains no Autodesk assembly, native binary, SDK archive, or copied XML documentation from the ObjectARX SDK.

### 3.2 Why this approach

- Consumers get one predictable package ID across supported AutoCAD years.
- Autodesk binaries come from the authoritative publisher rather than being repackaged by this repository.
- Package size remains small and public publishing avoids duplicating hundreds of megabytes of SDK content.
- Exact dependencies make restores reproducible and make an incorrect year mapping visible in the package manifest.
- Build-transitive safeguards centralize the rule that AutoCAD host DLLs must not ship with an add-in.

### 3.3 Alternatives not selected

1. **Pack local ObjectARX DLLs into one large package.** Rejected because it duplicates Autodesk-distributed binaries, produces a large package, and makes licensing, provenance, and multi-year selection harder to audit.
2. **Publish one independently maintained package ID per year.** Rejected because it increases consumer configuration and release maintenance without adding useful isolation. Year-specific wrapper versions already provide deterministic selection.
3. **Reference local SDK folders directly from every consumer.** Retained only as a local diagnostic fallback, not as the public contract. It causes machine-specific builds and is the failure currently seen in `Paper.AutoCad` when `PAPER_AUTOCAD_SDK_2024` is absent.

## 4. Version and Compatibility Contract

The wrapper version encodes the AutoCAD host year as the SemVer major number. The initial public patch for every line is `.0.1`.

| AutoCAD year | Wrapper version | Exact Autodesk dependency | Consumer runtime family |
|---:|---:|---:|---|
| 2019 | `2019.0.1` | `AutoCAD.NET` `23.0.0` | .NET Framework |
| 2020 | `2020.0.1` | `AutoCAD.NET` `23.1.0` | .NET Framework |
| 2021 | `2021.0.1` | `AutoCAD.NET` `24.0.0` | .NET Framework |
| 2022 | `2022.0.1` | `AutoCAD.NET` `24.1.51000` | .NET Framework |
| 2023 | `2023.0.1` | `AutoCAD.NET` `24.2.0` | .NET Framework |
| 2024 | `2024.0.1` | `AutoCAD.NET` `24.3.0` | .NET Framework 4.8 consumer |
| 2025 | `2025.0.1` | `AutoCAD.NET` `25.0.1` | .NET 8 Windows consumer |
| 2026 | `2026.0.1` | `AutoCAD.NET` `25.1.1` | .NET 10 Windows consumer; AutoCAD 2026 Update 1.2+ |
| 2027 | `2027.0.1` | `AutoCAD.NET` `26.0.0` | .NET 10 Windows consumer |

Rules:

- A wrapper patch release may fix package logic or documentation without changing its AutoCAD year.
- Changing a wrapper line to a different Autodesk dependency is allowed only when that dependency still targets the same AutoCAD host year and the change is recorded for consumers.
- A package version must never silently select a different AutoCAD year.
- The AutoCAD 2024 line is the first end-to-end consumer and host-validation target.
- The AutoCAD 2026 line intentionally follows Autodesk's `25.1.1` package and its .NET 10 contract for AutoCAD 2026 Update 1.2 or later. AutoCAD 2026 through Update 1.1 used the earlier .NET 8/`25.1.0` contract and is not selected by this wrapper version.

## 5. Repository Layout

The implementation plan will create this focused structure:

```text
AutoCAD-all-in-one/
├── AutoCAD-all-in-one.sln
├── .github/
│   └── workflows/
│       ├── build.yml
│       └── publish.yml
├── AutoCADAllInOne/
│   └── AutoCADAllInOne.csproj
├── build/
│   └── AutoCAD-all-in-one.targets
├── docs/
│   └── superpowers/specs/
├── metadata/
│   ├── 2019.json
│   ├── ...
│   └── 2027.json
├── tests/
│   └── package-contract.ps1
├── LICENSE
├── README.md
└── THIRD-PARTY-NOTICES.md
```

The existing `libs/ObjectARX_Cad*` directories remain untouched as a local SDK/reference archive. They are never packed into the public NuGet artifact.

### 5.1 Visual Studio entry point

`AutoCAD-all-in-one.sln` lives at the repository root and contains only `AutoCADAllInOne/AutoCADAllInOne.csproj`.

The solution intentionally excludes projects found below `libs/ObjectARX_Cad*`. Those are Autodesk SDK samples and reference material, not projects owned or built by this package repository. Keeping them out makes solution restore/build deterministic and keeps Visual Studio responsive.

The repository uses the traditional `.sln` format requested by the maintainer, not `.slnx`. A default Release solution build selects the package project's AutoCAD 2024 defaults; producing all nine NuGet lines continues to use `build/Pack.ps1 -All`.

## 6. Package Contents

Every produced `.nupkg` contains only:

- The NuGet manifest and metadata.
- `buildTransitive/AutoCAD-all-in-one.targets`.
- Package README, license, and third-party notice files.
- The exact dependency on the official `AutoCAD.NET` version for the selected year.

Every produced `.nupkg` must contain zero `.dll`, `.exe`, native binary, ObjectARX archive, and Autodesk XML documentation entries.

The package project is packaging infrastructure, not an add-in library. It does not expose a runtime assembly of its own.

## 7. Build-Transitive Contract

The targets imported into consumers perform four bounded jobs:

1. Expose the package's selected host year as `AutoCadPackageYear`.
2. If the consumer sets `AutoCadVersion`, fail the build when it differs from `AutoCadPackageYear`.
3. Define the compilation symbol `AUTOCAD<year>` exactly once, preserving existing consumer constants.
4. Remove Autodesk host assemblies from `ReferenceCopyLocalPaths` before files are copied to the consumer output.

The copy-prevention list covers the managed assemblies delivered by the official package dependency, including at minimum:

- `AcCoreMgd.dll`
- `AcDbMgd.dll`
- `AcMgd.dll`
- `AcCui.dll`
- `AcWindows.dll`
- `AdWindows.dll`
- `acdbmgdbrep.dll`

Matching is by normalized filename, case-insensitive, rather than by an absolute NuGet-cache path. A diagnostic MSBuild error names both years when the consumer property and package line conflict.

The targets do not:

- Change `SECURELOAD` or AutoCAD trusted paths.
- Launch AutoCAD.
- Deploy an add-in bundle.
- Copy files from `libs`.
- Hide a missing or incompatible Autodesk dependency.

## 8. Local SDK Inventory and Placeholders

Metadata files document the relationship between AutoCAD year, Autodesk package version, expected managed assembly version, consumer framework family, and local ObjectARX availability.

Current local archive status is:

| Year | Local archive status |
|---:|---|
| 2019 | Placeholder: local SDK not present |
| 2020 | Present as `libs/ObjectARX_Cad20` |
| 2021 | Placeholder: local SDK not present |
| 2022 | Placeholder: local SDK not present |
| 2023 | Present as `libs/ObjectARX_Cad23` |
| 2024 | Present as `libs/ObjectARX_Cad24` |
| 2025 | Present as `libs/ObjectARX_Cad25` |
| 2026 | Present as `libs/ObjectARX_Cad26` |
| 2027 | Present as `libs/ObjectARX_Cad27` |

A placeholder is explicit metadata, not an empty fake SDK folder and not a binary package. Missing local archives do not block the corresponding NuGet line because compilation references come from Autodesk's official NuGet dependency.

## 9. Consumer Contract

A consumer selects one AutoCAD year in MSBuild and references the matching wrapper line:

```xml
<PropertyGroup>
  <AutoCadVersion>2024</AutoCadVersion>
</PropertyGroup>

<ItemGroup>
  <PackageReference Include="AutoCAD-all-in-one"
                    Version="$(AutoCadVersion).0.*"
                    PrivateAssets="all" />
</ItemGroup>
```

`PrivateAssets="all"` is recommended for add-in projects so the build-only SDK facade does not become part of an add-in's own downstream package contract.

The consumer remains responsible for:

- Targeting the framework required by its AutoCAD host.
- Producing a valid AutoCAD bundle or other deployment layout.
- Running all Autodesk API work on the valid AutoCAD execution context.
- Runtime testing in the actual AutoCAD year.

## 10. Build and Publish Workflows

### 10.1 Pull request and main build

A Windows CI matrix builds and contract-tests every year from 2019 through 2027. Each matrix entry generates only its selected wrapper line and uploads the `.nupkg` as an unpublished workflow artifact.

CI must fail if any of these are wrong:

- The wrapper version does not encode the matrix year.
- The dependency version differs from the approved mapping.
- The package contains a binary.
- Required metadata or notices are missing.
- A sample consumer cannot restore/build.
- Autodesk host assemblies appear in the sample consumer output.

### 10.2 Public publishing

Publishing is tag-driven. A tag in the form `vYYYY.0.PATCH` selects exactly one year line, verifies it again, and publishes exactly one package.

The workflow uses NuGet.org trusted/OIDC publishing where available and does not store a long-lived API key in the repository. GitHub Packages may be added as a separate destination later, but it is not required for the first public release.

Creating or pushing a tag and publishing to NuGet.org are external actions and require explicit user authorization at release time.

## 11. Verification Strategy

### 11.1 Static package contract

For every year:

- Open the generated `.nupkg` as a ZIP archive.
- Assert there are zero binary entries.
- Parse the `.nuspec` and assert exactly the approved `AutoCAD.NET` dependency version.
- Assert the targets, README, license, and third-party notice are present.
- Assert package identity/version matches the selected year.

### 11.2 Consumer build contract

For every year, generate or parameterize a minimal temporary consumer project that:

- Targets the expected framework family.
- References the locally produced wrapper package.
- Compiles a small type using Autodesk managed API symbols.
- Verifies the `AUTOCAD<year>` constant.
- Verifies a mismatched `AutoCadVersion` fails with the intended diagnostic.
- Verifies no listed Autodesk host DLL appears in its output directory.

### 11.3 First real consumer

After this package workstream passes, migrate `Paper.AutoCad` 2024 from `AutoCadSdkRoot` references to `AutoCAD-all-in-one` `2024.0.x`. Verify restore and DB/RL compilation, inspect output for zero Autodesk host DLLs, and then validate loading inside AutoCAD 2024.

Build/restore success is not evidence of live AutoCAD loading or API behavior. Those results will be reported separately.

## 12. Licensing and Public Documentation

- Repository-owned source and build logic remain under Apache-2.0.
- `THIRD-PARTY-NOTICES.md` states that Autodesk binaries are not included and points consumers to Autodesk's package and license terms.
- README clearly describes the facade model, the year table, consumer usage, supported framework families, and the distinction between compile validation and live-host validation.
- Public package metadata identifies this project as an independent convenience facade and does not imply Autodesk endorsement.

## 13. Delivery Sequence

1. Implement and test `AutoCAD-all-in-one` locally for all nine year lines.
2. Review generated package contents and CI configuration.
3. Integrate the verified 2024 package into `Paper.AutoCad`.
4. Implement `Paper.AutoCad` DB/F5 launch behavior.
5. Add `0.Deployment`, RL bundle staging/locked-file-safe auto-deploy, and installer support.
6. Perform live AutoCAD 2024 validation.
7. Publish only after an explicit release instruction.

This sequence keeps the SDK dependency contract independent from add-in execution and deployment behavior.
