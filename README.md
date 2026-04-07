_This project has been created as part of the 42 curriculum by clumertz and adpinhei._

# Description

cub3D is a 3D graphical representation of the inside of a maze from a first-person perspective, created using ray-casting principles.
Inspired by the world-famous Wolfenstein 3D (1992), which is considered the first true "First Person Shooter," this project serves as a technical exploration of the algorithms that powered early 3D gaming


The goal is to create a dynamic view where the user can navigate through a maze defined by a configuration file. The engine calculates the player's field of vision in real-time, rendering walls with textures that vary depending on the compass direction (North, South, East, West) they face.

# Instructions

## Compilation
The project includes a Makefile that compiles the source files using the -Wall, -Wextra, and -Werror flags.

To compile the mandatory part:

```bash
make
```

Other available rules:

```bash
clean: Removes object files.
fclean: Removes object files and the compiled executable.
re: Recompiles the entire project.
```

## Execution
The program requires a scene description file with the .cub extension as its only argument:
./cub3D path_to_map.cub

## Controls
W, A, S, D: Move the point of view through the maze.

Left/Right Arrows: Rotate the camera view.

ESC: Close the window and quit the program.

Red Cross: Clicking the window's close button also exits the program cleanly.

# Resources

## References
Digital Differential Analyzer (DDA) - Wikipedia

The DDA Algorithm, Explained Interactively

Lode's Computer Graphics Tutorial - Raycasting

## AI Usage
AI was utilized in this project for the following tasks:
Technical Explanations: Assisting in the conceptual breakdown of the Digital Differential Analyzer (DDA) implementation.

Documentation: Generating the project's README.md and clarifying specific algorithm steps.

## Technical Highlights
DDA Algorithm: Used for infinite precision in wall detection on a 2D grid, avoiding the "skipping" issues found in constant-step algorithms.

Vector-Based Camera: Implementation of a 2D camera using direction and plane vectors instead of Euclidean angles for more efficient rotations.

Fisheye Prevention: Distance is calculated perpendicular to the camera plane rather than directly to the player, ensuring walls appear flat and straight.

MiniLibX: All graphical rendering is handled through the miniLibX library, managing window events and pixel-level display.

