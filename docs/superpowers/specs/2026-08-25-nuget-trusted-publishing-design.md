# NuGet Trusted Publishing Design

**Date:** 2026-08-25

**Status:** Approved

**Repository:** `D:\Repository\Cazorlas\AutoCAD-all-in-one`

## 1. Goal

Publish one explicitly selected `AutoCAD-all-in-one` package to NuGet.org from GitHub Actions without storing a long-lived NuGet API key.

Success means the maintainer edits the release year and package version in `AutoCADAllInOne.csproj`, pushes a matching Git tag, and GitHub Actions builds, validates, and publishes exactly one package. Ordinary local Release builds and pushes to `main` must never publish externally.

## 2. Chosen Release Model

Publishing is tag-driven and uses NuGet.org Trusted Publishing with GitHub OIDC.

- `Debug` builds compile without creating or publishing a package.
- `Release` builds create a local package under `artifacts/packages` and never publish it.
- Pushes and pull requests run the existing 2019-2027 build-and-test matrix without publishing.
- A tag matching `vYYYY.0.PATCH` starts the publish workflow.
- The publish workflow obtains a short-lived NuGet API key through `NuGet/login@v1` immediately before pushing the package.

Publishing on every push to `main` is rejected because an ordinary source change must not create an irreversible public release. A long-lived NuGet API key is rejected because OIDC already provides a narrower, short-lived credential.

## 3. Release Source of Truth

The pushed `vYYYY.0.PATCH` tag selects the public release year and complete NuGet version. The
matching `metadata/<year>.json` entry supplies the official `AutoCAD.NET` dependency, target
framework, and wrapper version used by `build/Pack.ps1`. The package contract requires the generated
wrapper version to equal the tag version before authentication or publication.

`AutoCADAllInOne/AutoCADAllInOne.csproj` keeps 2024 as the convenient local Visual Studio default,
but public multi-year releases do not require commits that change that default back and forth.

## 4. Publish Workflow

For a release such as AutoCAD 2024 package `2024.0.1`, the maintainer pushes tag `v2024.0.1`.

The workflow performs these steps in order:

1. Check out the tagged commit.
2. Install the required .NET 8 and .NET 10 SDKs.
3. Parse the release year and complete version from the `vYYYY.0.PATCH` tag.
4. Run `build/Pack.ps1 -Year <year>`, producing exactly one `.nupkg` under `artifacts/packages`.
5. Require the metadata-driven package version and year identity to match the tag.
6. Run the selected-year static and consumer package contracts against that exact package version.
7. Request a short-lived credential through `NuGet/login@v1`.
8. Require exactly one `.nupkg`, then push it to NuGet.org.

The workflow does not use `--skip-duplicate`. A duplicate version is a release error and must remain visible rather than being silently accepted.

## 5. Test Changes

The package contract script will accept an optional expected package version for the public-release path.

- Matrix validation continues using each year's metadata.
- Publish validation supplies the tag package version explicitly.
- Consumer build verification continues checking the selected framework, dependency, constants, and copy-local exclusions.
- Static automation tests verify the tag gate, OIDC permission, temporary-key login, contract test, and single-package push.

No test claims live AutoCAD runtime compatibility; this workflow validates packaging and consumer compilation only.

## 6. External One-Time Setup

The NuGet.org account owner must create a Trusted Publishing policy with:

- Repository owner: `Cazorlas`
- Repository: `AutoCAD-all-in-one`
- Workflow file: `publish.yml`
- Environment: empty, because the workflow does not use a GitHub environment

The GitHub repository must define `NUGET_USER` as the NuGet.org profile username, not an email address. No permanent NuGet API key is stored in the repository.

These account-level actions require the maintainer's authenticated NuGet.org and GitHub sessions and are not performed by repository code.

## 7. Failure Behavior

- Invalid tag syntax fails before packing; a metadata/tag version mismatch fails before authentication.
- Restore, build, or contract failure: fail before requesting a NuGet credential.
- Missing Trusted Publishing policy or incorrect `NUGET_USER`: fail during OIDC login without publishing.
- Zero or multiple packages: fail before `dotnet nuget push`.
- Duplicate public version: allow NuGet.org to reject the push visibly.

## 8. Release Procedure

After the repository workflow and external policy are configured:

1. Confirm the selected year's metadata and run its focused pack/consumer contract locally.
2. Push any required source changes to `main` and wait for the all-year build workflow to pass.
3. Create and push the matching tag, for example `v2024.0.2`.
4. Verify the publish workflow and the new package page on NuGet.org.

Tag creation and public publishing remain explicit external actions; implementation and verification do not create a tag or publish a package automatically.
