# Visual Studio Solution and Main Push Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Add the requested root Visual Studio `.sln`, verify the complete package repository through that entry point, merge the feature branch into `main`, and push `origin/main`.

**Architecture:** The traditional solution contains only the repository-owned `AutoCADAllInOne.csproj`. ObjectARX SDK sample projects under `libs` remain excluded. Packaging and full contract verification continue through the existing PowerShell entry points.

**Tech Stack:** Visual Studio solution format, .NET SDK 10 CLI, MSBuild, PowerShell, Git.

## Global Constraints

- Create exactly `AutoCAD-all-in-one.sln` at the repository root.
- Include exactly `AutoCADAllInOne/AutoCADAllInOne.csproj`.
- Do not modify or include projects below `libs/ObjectARX_Cad*`.
- Default solution build uses the package project's AutoCAD 2024 configuration.
- Push only after fresh solution build and all nine package contracts pass on merged `main`.
- Do not create a NuGet tag or publish to NuGet.org.

---

### Task 1: Root solution entry point

**Files:**
- Create: `AutoCAD-all-in-one.sln`

**Interfaces:**
- Consumes: `AutoCADAllInOne/AutoCADAllInOne.csproj`.
- Produces: a Visual Studio entry point that restores and builds the AutoCAD 2024 package project by default.

- [ ] **Step 1: Verify the solution contract currently fails**

```powershell
if (Test-Path -LiteralPath .\AutoCAD-all-in-one.sln) { exit 0 } else { exit 1 }
```

Expected: exit code 1 because the root solution does not exist.

- [ ] **Step 2: Generate the traditional solution**

```powershell
dotnet new sln --name AutoCAD-all-in-one --format sln
dotnet sln .\AutoCAD-all-in-one.sln add .\AutoCADAllInOne\AutoCADAllInOne.csproj
```

Expected: one `.sln` is created and the package project is added.

- [ ] **Step 3: Verify membership and build**

```powershell
dotnet sln .\AutoCAD-all-in-one.sln list
dotnet build .\AutoCAD-all-in-one.sln --configuration Release --nologo
```

Expected: the list contains only `AutoCADAllInOne\AutoCADAllInOne.csproj`; build succeeds with zero errors.

- [ ] **Step 4: Commit the solution**

```powershell
git add AutoCAD-all-in-one.sln
git commit -m "chore: add Visual Studio solution"
```

### Task 2: Merge, verify, and push main

**Files:**
- No source files are created in this task.

**Interfaces:**
- Consumes: clean `feature/autocad-nuget-facade` and `main` branches.
- Produces: remote `origin/main` containing the complete facade package repository and root solution.

- [ ] **Step 1: Confirm both worktrees are clean and update remote state**

```powershell
git status --short
git -C D:\Repository\Cazorlas\AutoCAD-all-in-one status --short
git -C D:\Repository\Cazorlas\AutoCAD-all-in-one fetch origin
git -C D:\Repository\Cazorlas\AutoCAD-all-in-one merge --ff-only origin/main
```

Expected: both status outputs are empty and local `main` is current with `origin/main`.

- [ ] **Step 2: Fast-forward main to the feature branch**

```powershell
git -C D:\Repository\Cazorlas\AutoCAD-all-in-one merge --ff-only feature/autocad-nuget-facade
```

Expected: `main` advances without a merge commit or conflict.

- [ ] **Step 3: Verify the merged main checkout**

```powershell
dotnet build D:\Repository\Cazorlas\AutoCAD-all-in-one\AutoCAD-all-in-one.sln --configuration Release --nologo
powershell -NoProfile -ExecutionPolicy Bypass -File D:\Repository\Cazorlas\AutoCAD-all-in-one\build\Pack.ps1 -All
powershell -NoProfile -ExecutionPolicy Bypass -File D:\Repository\Cazorlas\AutoCAD-all-in-one\tests\package-contract.ps1
```

Expected: solution build succeeds; exactly nine packages are created; metadata, static, automation, and all nine consumer contracts pass.

- [ ] **Step 4: Push main and verify remote commit**

```powershell
git -C D:\Repository\Cazorlas\AutoCAD-all-in-one push origin main
git -C D:\Repository\Cazorlas\AutoCAD-all-in-one rev-parse HEAD
git -C D:\Repository\Cazorlas\AutoCAD-all-in-one ls-remote origin refs/heads/main
```

Expected: push succeeds and local/remote main hashes match.

## Completion Boundary

This increment is complete when the root `.sln` exists on `origin/main`, contains only the package project, the merged checkout passes the nine-year contracts, and no NuGet package was published.
