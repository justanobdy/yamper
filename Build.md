# Building Yamper
- [Linux](#linux)
- [Windows](#windows)
- [MacOS](#macos)

# Requirements
- SFML (2.5.1 minimum, 2.6 recommended)
- CMake
- git

# Linux

Run this to clone the repository:
```git clone https://github.com/justanobdy/yamper.git```

Then, to install imgui, imgui-sfml, portable-file-dialogs, and simpleini, run:
```./install_deps.sh```

Finally, to actually build it, run these:
```
mkdir build
cd build
cmake ../
cmake --build .
```

And thats it!

# Windows

Run this to clone the repository:
```git clone https://github.com/justanobdy/yamper.git```

Then, to install imgui, imgui-sfml, portable-file-dialogs, and simpleini, run:
```install_deps.bat```

Then, to generate the build files, run:
```
mkdir build
cd build
cmake ../
```
Or use the CMake GUI.

If you are building using Mingw, simply run make to build it.

If you are building using Visual Studio, open the solution file and build it.

# MacOS
Building on MacOS should be the same as building on Linux. Although, I don't have a way to debug on MacOS, so if you have any issues, you're on your own.