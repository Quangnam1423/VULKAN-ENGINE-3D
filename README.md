# Vulkan Engine

- 3D Graphics Engine based on Vulkan.

## Init dependencies Installation - Dependencies for Linux (Ubuntu)

Before building the VulKan Game Engine, make sure your system has all requireed development package installed.
Run the following commands in your terminal:

```bash
# --- Update system packages ---
sudo apt update && sudo apt upgrade -y
# --- Essential build tools ---
sudo apt install -y vulkan-tools vulkan-validationlayers-dev libvulkan-dev

# --- GLFW (for window creation and input) ---
sudo apt install -y libglfw3-dev

# --- GLM (math library for 3D transformations) ---
sudo apt install -y libglm-dev

# --- STB image loader (header-only, can be manually added) ---
```

## Compile and Run

```bash
mkdir -p out/builds
cmake -S . -B out/build
cd out/build
make
```