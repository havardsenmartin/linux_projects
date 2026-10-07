You do not usually need to know the *architecture* of your GPU just to start writing OpenGL shaders. What matters more is:

* which GPU you have
* which OpenGL version it supports
* which GLSL (shader language) version it supports
* whether your drivers are installed correctly

On Arch + Hyprland, you can check all of this quickly.

## 1. Find your GPU

Run:

```bash
lspci | grep -E "VGA|3D"
```

Example output:

```bash
01:00.0 VGA compatible controller: NVIDIA Corporation RTX 3060
```

or

```bash
00:02.0 VGA compatible controller: Intel Corporation UHD Graphics
```

or

```bash
03:00.0 VGA compatible controller: Advanced Micro Devices, Inc. [AMD/ATI] Navi 22
```

---

## 2. Check OpenGL support

Install Mesa utilities if needed:

```bash
sudo pacman -S mesa-utils
```

Then run:

```bash
glxinfo | grep -E "OpenGL vendor|OpenGL renderer|OpenGL version"
```

Example:

```bash
OpenGL vendor string: NVIDIA Corporation
OpenGL renderer string: NVIDIA GeForce RTX 3060/PCIe/SSE2
OpenGL version string: 4.6.0 NVIDIA 555.58
```

This is the important part.

---

## 3. Check GLSL shader version

Run:

```bash
glxinfo | grep "OpenGL shading language version"
```

Example:

```bash
OpenGL shading language version string: 4.60 NVIDIA
```

That means you can write shaders with:

```glsl
#version 460 core
```

---

## 4. Do you need to care about GPU architecture?

Only later.

At the beginning:

* OpenGL abstracts the hardware away
* your shaders are written in GLSL
* the driver compiles them for your GPU

So whether your GPU is:

* AMD RDNA
* NVIDIA Ada/Lovelace
* Intel Xe
* etc.

does not matter much initially.

Architecture becomes relevant when:

* optimizing performance
* using Vulkan
* compute shaders
* vendor-specific extensions
* understanding GPU execution

---

## 5. Recommended beginner stack on Arch

A very common setup:

* OpenGL
* GLFW (window/context creation)
* GLAD or GLEW (OpenGL function loading)

Install:

```bash
sudo pacman -S glfw mesa
```

For GLAD, many people generate it online from:

[GLAD generator](https://glad.dav1d.de/?utm_source=chatgpt.com)

Or use:

* [GLFW documentation](https://www.glfw.org/docs/latest/?utm_source=chatgpt.com)
* [LearnOpenGL](https://learnopengl.com/?utm_source=chatgpt.com)

The best beginner tutorial for shaders is probably:

[LearnOpenGL Shaders chapter](https://learnopengl.com/Getting-started/Shaders?utm_source=chatgpt.com)

---

## 6. Very small example shader

Vertex shader:

```glsl
#version 330 core

layout (location = 0) in vec3 aPos;

void main()
{
    gl_Position = vec4(aPos, 1.0);
}
```

Fragment shader:

```glsl
#version 330 core

out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}
```

This just draws red geometry.

---

## 7. Wayland / Hyprland note

Hyprland uses Wayland, but GLFW supports Wayland directly, so OpenGL development works fine.

You generally do **not** need X11 unless:

* some old tutorials assume X11
* certain debugging tools require it

GLFW handles this automatically.

---

## 8. One more useful command

To see Vulkan + GPU info too:

```bash
vulkaninfo | less
```

Install:

```bash
sudo pacman -S vulkan-tools
```

Even if you use OpenGL, this is useful for confirming drivers are healthy.
