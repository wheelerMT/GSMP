# Contributing to the GSMP

## Installing the required dependencies
The GSMP is built using C# and so the developer requires .NET in order to build the project.
The minimum supported version is `>=.NET 8.0.0`.
To install .NET visit the [Microsoft website](https://dotnet.microsoft.com/en-us/)
and follow the installation instructions.

### Using VSCode
If using the VSCode editor, ensure you have the
[C# Dev Kit](https://marketplace.visualstudio.com/items?itemName=ms-dotnettools.csdevkit) extension installed, which
allows  you to view the individual C# projects and solution.

### Using Visual Studio
If using the Visual Studio IDE, ensure you have the latest '.NET desktop development' pack installed (see
[here](https://learn.microsoft.com/en-us/visualstudio/install/install-visual-studio?view=vs-2022) for  more
information).

## Linting and Formatting
The GSMP should be linted and formatted according to the provided `.editorconfig`.
Ensure you either:
1. Have auto-format on save enabled in your editor (and that it uses the `.editorconfig`),
2. Run `dotnet format` before you push your changes.
