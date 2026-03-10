
#  cub3D


---

##  Introduction

cub3D is a 42 school project that introduces the basics of graphic programming through the Raycasting technique. The goal is to create a dynamic 3D view from a 2D map, similar to the famous game Wolfenstein 3D.

---

##  Features

* **3D Perspective**: Smooth 1st-person navigation in a 3D environment.
* **Map Parsing**: Accurate reading of .cub files, handling walls, floor/ceiling colors, and textures.
* **Wall Texturing**: Distinct textures for North, South, East, and West faces of walls.
* **Movement Control**:
* W, A, S, D: Moving the player.
* Left/Right arrows: Rotating the camera.
* ESC & Close Window: Proper clean exit.


* **Collision Handling**: Prevents the player from walking through walls.
* **Performance**: Optimized rendering loop for a fluid frame rate.

---

##  Installation

### 1. Clone the repository

git clone [https://github.com/slkrt111/cub3d.git](https://www.google.com/search?q=https://github.com/slkrt111/cub3d.git)
cd cub3d

### 2. Compilation

The project uses a Makefile and requires the MinilibX:
make

---

##  Usage

Launch the engine by providing a map file as an argument:
./cub3D maps/map.cub

### Map format rules (.cub):

* Wall textures: NO, SO, WE, EA paths.
* Colors: Floor (F) and Ceiling (C) in R,G,B format.
* Map layout: Surrounded by walls ('1'), with a starting position (N, S, E, or W).

---

##  Technical Implementation

### 1. The Raycasting Algorithm

For every vertical line on the screen, the engine shoots a ray from the player's position. It calculates the distance to the first wall encountered and renders its height based on that distance to simulate depth.

### 2. DDA (Digital Differential Analysis)

Used to efficiently find wall hits without checking every single pixel, ensuring high performance even on older hardware.

### 3. MinilibX

The project uses the MinilibX (42's simple graphics library) to manage windows, handle keyboard/mouse events, and push pixel arrays to the screen.

### 4. Texture Mapping

Calculating the exact X coordinate on a wall texture depending on where the ray hit, then scaling it vertically to match the wall's height on the screen.
