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

`AutoCADAllInOne/AutoCADAllInOne.csproj` is the source of truth for the package selected for public release:

- `AutoCadVersion` selects the AutoCAD host year.
- `PackageVersion` is the complete NuGet version and must begin with the selected AutoCAD year.
- The existing year mapping selects the target framework and official `AutoCAD.NET` dependency.

The `metadata/<year>.json` files remain the compatibility and build-matrix inventory for all supported years. Their `wrapperVersion` values may be used for unpublished matrix artifacts, but they do not override the `.csproj` values during a public release.

This separation allows one release to be edited like `Revit_packages_all_versions` without weakening the all-year compatibility checks.

## 4. Publish Workflow

For a release such as AutoCAD 2024 package `2024.0.1`, the maintainer pushes tag `v2024.0.1`.

The workflow performs these steps in order:

1. Check out the tagged commit.
2. Install the required .NET 8 and .NET 10 SDKs.
3. Evaluate `AutoCadVersion` and `PackageVersion` from `AutoCADAllInOne.csproj` through MSBuild.
4. Require the Git tag to equal `v$(PackageVersion)`.
5. Require the tag year, `AutoCadVersion`, and package-version major number to match.
6. Build the solution in `Release`, producing exactly one `.nupkg` under `artifacts/packages`.
7. Run the selected-year static and consumer package contracts against that exact package version.
8. Request a short-lived credential through `NuGet/login@v1`.
9. Require exactly one `.nupkg`, then push it to NuGet.org.

The workflow does not use `--skip-duplicate`. A duplicate version is a release error and must remain visible rather than being silently accepted.

## 5. Test Changes

The package contract script will accept an optional expected package version for the public-release path.

- Matrix validation continues using each year's metadata.
- Publish validation supplies the `.csproj` package version explicitly.
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

- Missing or mismatched tag, year, or package version: fail before packing.
- Restore, build, or contract failure: fail before requesting a NuGet credential.
- Missing Trusted Publishing policy or incorrect `NUGET_USER`: fail during OIDC login without publishing.
- Zero or multiple packages: fail before `dotnet nuget push`.
- Duplicate public version: allow NuGet.org to reject the push visibly.

## 8. Release Procedure

After the repository workflow and external policy are configured:

1. Edit `AutoCadVersion` and `PackageVersion` in `AutoCADAllInOne.csproj`.
2. Build `Release` and run the focused package contract locally.
3. Commit and push the release change to `main`.
4. Wait for the all-year build workflow to pass.
5. Create and push a matching tag, for example `v2024.0.1`.
6. Verify the publish workflow and the new package page on NuGet.org.

Tag creation and public publishing remain explicit external actions; implementation and verification do not create a tag or publish a package automatically.
