# sdl2-template

A starting point for SDL2 projects, pre-configured with **SDL\_image** and **SDL\_ttf**, a basic game loop, fixed timestep physics, rendering capabilities, and file-based logging.

---

## Table of Contents

- [Features](#features)
- [Prerequisites](#prerequisites)
- [Getting Started](#getting-started)
  - [Clone the Repository](#clone-the-repository)
  - [Build (Debug)](#build-debug)
  - [Clean](#clean)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Configuration](#configuration)
- [Extending the Template](#extending-the-template)

---

## Features

- **SDL2 Initialization**: Sets up the SDL video subsystem.
- **SDL\_image Support**: Enables loading PNG, JPG, and other image formats.
- **SDL\_ttf Support**: Enables rendering TrueType fonts.
- **Basic Game Loop**: Implements a fixed timestep loop with event polling and rendering.
- **RenderWindow Class**: Simplifies window creation, renderer management, texture loading, and frame pacing.
- **Entity & Text Classes**: Provides examples of rendering textured entities and text objects.
- **Utility Modules**: Includes math functions (`Math.hpp`), high-resolution timing (`Utils.hpp`), and a simple **Logger** that writes to a log file.

## Prerequisites

Ensure you have the following installed on your system:

- A C++ compiler with C++20 support (e.g., `g++`).
- [SDL2](https://www.libsdl.org/).
- [SDL2\_image](https://www.libsdl.org/projects/SDL_image/).
- [SDL2\_ttf](https://www.libsdl.org/projects/SDL_ttf/).

On Debian/Ubuntu-based systems, you can install dependencies via:

```bash
sudo apt-get update
sudo apt-get install build-essential libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev
```

---

## Getting Started

### Clone the Repository

```bash
git clone https://github.com/Takkapi/sdl2-template.git
cd sdl2-template
```

### Build (Debug)

A simple `Makefile` is provided with a `debug` target:

```makefile
debug:
	g++ -c src/*.cpp -std=c++20 -m64 -g -Wall -I include
	g++ *.o -o bin/debug/template -lSDL2 -lSDL2_image -lSDL2_ttf
```

To compile:

```bash
make debug
```

### Clean

Remove build artifacts:

```bash
make clean
```

---

## Usage

After building, run the executable from the project root so that the `assets/` folder is in the working directory:

```bash
./bin/debug/template
```

You should see a window titled **"Minijam 187"** rendering the `background.png` image and sample text. Close the window or press the close button to exit.

---

## Project Structure

```
sdl2-template/
├── assets/              # Graphics and font files (e.g., assets/gfx, assets/fonts)
├── bin/                 # Binaries (debug/, release/)
├── include/             # Header files
│   ├── Entity.hpp
│   ├── Logger.hpp
│   ├── Math.hpp
│   ├── RenderWindow.hpp
│   ├── Text.hpp
│   └── Utils.hpp
├── src/                 # Source files (.cpp)
│   └── main.cpp         # Entry point and game loop
├── Makefile             # Build and clean targets
├── .gitignore           # Exclude build artifacts
└── README.md            # Project overview (this file)
```

---

## Configuration

- **Window size & title**: Modify in `main.cpp` when instantiating `RenderWindow window("Title", width, height);`.
- **Frame rate**: Controlled via `window.getRefreshRate()` and the fixed timestep (`timeStep`) in `main.cpp`.
- **Assets paths**: Update the paths in `main.cpp` when loading textures or fonts.

---

## Extending the Template

- **Add new systems**: Create new classes under `include/` and `src/` (e.g., an `Input` manager or `Audio` system).
- **Release build**: Enhance the `Makefile` with a `release` target (e.g., `-O3` optimizations, stripping symbols).
- **Unit tests**: Integrate a testing framework (e.g., Google Test) and add a `tests/` directory.

---

