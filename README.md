# AutoCAD-all-in-one

`AutoCAD-all-in-one` is a public, build-only NuGet facade for AutoCAD managed add-in development. One package ID selects the official Autodesk `AutoCAD.NET` dependency that matches a specific AutoCAD host year.

The package does not include Autodesk DLLs, native ObjectARX binaries, or copied Autodesk XML documentation. Those references are restored from Autodesk's official NuGet packages and removed from the consumer's copy-local output because AutoCAD supplies them at runtime.

This is an independent convenience package and is not endorsed by Autodesk.

## Supported versions

| AutoCAD | Package version | Official `AutoCAD.NET` | Consumer framework |
|---:|---:|---:|---|
| 2019 | `2019.0.1` | `23.0.0` | .NET Framework 4.7 |
| 2020 | `2020.0.1` | `23.1.0` | .NET Framework 4.7 |
| 2021 | `2021.0.1` | `24.0.0` | .NET Framework 4.7 |
| 2022 | `2022.0.1` | `24.1.51000` | .NET Framework 4.7 |
| 2023 | `2023.0.1` | `24.2.0` | .NET Framework 4.7 |
| 2024 | `2024.0.1` | `24.3.0` | .NET Framework 4.8 |
| 2025 | `2025.0.1` | `25.0.1` | .NET 8 for Windows |
| 2026 | `2026.0.1` | `25.1.1` | .NET 10 for Windows |
| 2027 | `2027.0.1` | `26.0.0` | .NET 10 for Windows |

AutoCAD 2024 is the first intended end-to-end Paper consumer and live-host validation target. Other lines have separate build and runtime evidence; a successful restore or compile is not proof of live AutoCAD compatibility.

The 2026 wrapper follows Autodesk's `AutoCAD.NET 25.1.1` package and therefore requires AutoCAD 2026 Update 1.2 or later with .NET 10. AutoCAD 2026 through Update 1.1 used .NET 8 and belongs to the earlier `25.1.0` SDK contract, which this wrapper line does not select.

## Use from an add-in project

Choose the host year once and reference the matching wrapper line:

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

The package imports build-transitive files that:

- Validate `AutoCadVersion` against the package year.
- Define `AUTOCAD2019` through `AUTOCAD2027` for the selected line.
- Prevent every assembly restored from `AutoCAD.NET`, `AutoCAD.NET.Core`, and `AutoCAD.NET.Model` from being copied into add-in output. This includes core files such as `AcCoreMgd.dll`, `AcDbMgd.dll`, and `AcMgd.dll` as well as year-specific auxiliary assemblies.

It does not launch AutoCAD, deploy a bundle, or change `SECURELOAD` and trusted-path settings.

## Local ObjectARX archive

The tracked `libs` directory is a local reference archive only; no content below it enters a NuGet package.

- Present: 2020, 2023, 2024, 2025, 2026, and 2027.
- Metadata placeholders only: 2019, 2021, and 2022.

Missing local archives do not block the facade package because compilation references come from the official Autodesk dependency.

## Build and verify locally

The solution keeps the same simple Visual Studio workflow as `Revit_packages_all_versions`:

1. Edit `AutoCadVersion` and, when needed, `PackageVersion` in `AutoCADAllInOne/AutoCADAllInOne.csproj`.
2. Use `Debug` to restore and build without creating a package.
3. Use `Release` to build and automatically create the selected `.nupkg` under `artifacts/packages`.

The project maps the selected AutoCAD year to its target framework and official `AutoCAD.NET` dependency. No year-specific Visual Studio configurations are required.

Windows PowerShell 5.1 and PowerShell 7 are both supported:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\build\Pack.ps1 -Year 2024
powershell -NoProfile -ExecutionPolicy Bypass -File .\tests\package-contract.ps1 -Year 2024
```

To verify every line:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\build\Pack.ps1 -All
powershell -NoProfile -ExecutionPolicy Bypass -File .\tests\package-contract.ps1
```

Generated packages stay under `artifacts/packages` and are not committed. Packing and testing never publish. Public publishing is tag-driven and requires a separately configured NuGet.org trusted-publishing policy for this repository and `publish.yml`.

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

## Runtime responsibility

Consumers must target the correct framework, create a valid AutoCAD bundle, execute Autodesk API calls in the valid host context, and test the add-in inside the actual AutoCAD year. Package contract tests intentionally distinguish compile-time evidence from live AutoCAD validation.

## License and third-party terms

Repository-owned source is Apache-2.0. Autodesk packages and binaries remain subject to Autodesk's own terms; see [THIRD-PARTY-NOTICES.md](THIRD-PARTY-NOTICES.md).
