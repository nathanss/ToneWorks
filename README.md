# ToneWorks

Minimal JUCE audio-plugin project configured with CMake. The initial processor
passes audio through unchanged and provides a foundation for integrating
NeuralAmpModelerCore.

## Requirements

- CMake 3.22 or newer
- Visual Studio Build Tools with the Desktop development with C++ workload
- Git

## Build on Windows

```powershell
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

The Windows build produces VST3 and standalone application targets. The AU
format from the original example is intentionally omitted because Audio Units
are only available on macOS.

## Visual Studio Code

Install the workspace's recommended C/C++ and CMake Tools extensions. When the
folder opens, CMake Tools configures the project. The workspace IntelliSense
configuration uses the generated JUCE header, JUCE module paths, and installed
x64 MSVC toolchain.

If prompted to select a kit, choose the x64 Visual Studio Build Tools compiler.
Use **CMake: Configure** after changing `CMakeLists.txt`, and **CMake: Build** to
build the selected Release or Debug configuration.
