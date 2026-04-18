# OpenGL 3D Cube Demo

A modern C++ OpenGL application demonstrating core real-time 3D rendering concepts,
including a free-roaming FPS camera, texture mapping, and MVP matrix transformations.
Renders multiple independently rotating textured cubes in a 3D scene.

![Demo Screenshot](screenshots/demo.png)

**The codebase of this project currently only works on macOS with ARM SoCs.**
---
## Features

- **FPS-Style Camera** – Full camera system with WASD movement and mouse look
- **Zoom** – Mouse scroll wheel adjusts the Field of View (FOV)
- **Multiple Cubes** – 10 cubes rendered in 3D space with individual time-based rotation
- **Texture Mapping** – High-resolution textures loaded via `stb_image`
- **MVP Transforms** – Model, View, and Projection matrices via GLM

---
## Tech Stack

* **[OpenGL](https://www.opengl.org/):** Core graphics rendering.
* **[GLFW](https://www.glfw.org/):** Window creation, context management, and input handling.
* **[GLEW](http://glew.sourceforge.net/):** OpenGL Extension Wrangler for modern OpenGL function pointers.
* **[GLM](https://github.com/g-truc/glm):** Mathematics library for vector and matrix operations.
* **[stb_image](https://github.com/nothings/stb):** Lightweight image loading.
---

## Installation & Build
### Prerequisites

All dependencies are bundled in the `dep/` and `vendor/` directories —
no manual library installation needed.

- **Xcode Command Line Tools**
```bash
  xcode-select --install
```
- **CMake** (bundled with CLion, or via Homebrew: `brew install cmake`)

### Build Steps

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/realdaveeeed/OpenGL_3DCube.git
    ```

2.  **Open in CLion:**
    * Select **File -> Open** and choose the project folder.
    * CLion will detect `CMakeLists.txt`

3.  **Run:**
    * Select the configuration and click the **Run** button.
---
## Project Structure

```
OpenGL_3DCube/
├── source/        # C++ source files
├── shaders/       # GLSL vertex & fragment shaders
├── textures/      # Texture assets
├── dep/           # Prebuilt dependencies
├── vendor/        # Header-only libraries (stb_image, etc.)
└── CMakeLists.txt
```
