# Maze-Generator-and-solver

This C++ program generates a random maze using a recursive backtracking algorithm and solves it using a simple depth-first search approach. The maze is displayed using the SDL2 library, providing a visual representation of the maze generation and solving process.

![maze](https://github.com/HimanshuMK/Maze-Generator-and-solver/assets/105967041/a8ab9e08-5766-4f2f-ab56-f8def5eba60f)

## Getting Started

### Prerequisites

Make sure you have SDL2 installed on your system. You can install it using the package manager specific to your operating system.

Also if your usage is related to this project only, Then just go ahead with the below steps you will just need a c++ compiler.

## Building and Running

1. **Clone the repository:**

   ```bash
   git clone https://github.com/HimanshuMK/Maze-Generator-and-solver.git
   cd Maze-Generator-and-solver
   ```
2. **Build the program:**
   ```bash
   g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2
   ```

3. **Run the executable:**
   ```bash
   ./main
   ```

### Usage
The program will generate a random maze, display it using SDL2, and then attempt to find a solution. The start and end points of the maze are marked in red and blue, respectively.

If a solution is found, "Path found!" will be printed to the console; otherwise, "No Path found!" will be displayed.

### Customization
You can modify the program to change the maze size, cell size, or other parameters by updating the constants in the source code.

### Dependencies
SDL2: Simple DirectMedia Layer is used for graphical rendering

