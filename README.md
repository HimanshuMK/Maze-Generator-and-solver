# Maze Generator and Solver

Welcome to the Maze Generator and Solver project! This project demonstrates two different implementations of maze generation and solving algorithms using Depth-First Search (DFS). The first implementation uses recursion, while the second one uses a stack data structure.

## Recursion 
![MazeRecursion](https://github.com/HimanshuMK/Maze-Generator-and-solver/assets/105967041/a8ab9e08-5766-4f2f-ab56-f8def5eba60f)

## Using Stack
![mazeStack](https://github.com/HimanshuMK/Maze-Generator-and-solver/assets/105967041/16055eba-51bf-4d6b-b5ca-1b47a6e817ac)

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
  - [Building and Running](#building-and-running)
- [Usage](#usage)
- [Customization](#customization)
- [Dependencies](#dependencies)
- [Contributing](#contributing)

## Introduction

This project provides two ways to generate and solve mazes:
1. **DFS using Recursion**: A simple and elegant approach leveraging the call stack.
2. **DFS using Stack**: An iterative approach that manually manages the stack.

Both methods generate mazes by carving out paths from an initial cell and then solve the mazes by finding a path from the start to the end.

## Features

- Maze generation using DFS.
- Maze solving using DFS.
- Two implementation methods:
  - Recursive DFS
  - Iterative DFS with a stack
- Visualization of the maze generation and solving process.

## Project Structure

The project is structured into two main directories, each containing an implementation of the maze generator and solver:

- **Maze using Recursion/**: Contains the recursive implementation of the maze generator and solver.
- **Maze using Stack/**: Contains the stack-based implementation of the maze generator and solver.

## Getting Started

### Prerequisites

Make sure you have SDL2 installed on your system. You can install it using the package manager specific to your operating system.

If your usage is related to this project only, then just go ahead with the below steps. You will only need a C++ compiler.

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/HimanshuMK/Maze-Generator-and-Solver.git
   cd Maze-Generator-and-Solver

### Building and Running
1. Build the program
   ```bash
   g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2

2. Run the executable:
   ```bash
   ./main

## Usage
The program will generate a random maze, display it using SDL2, and then attempt to find a solution. The start and end points of the maze are marked in red and blue, respectively.

If a solution is found, "Path found!" will be printed to the console; otherwise, "No Path found!" will be displayed.

## Customization
You can modify the program to change the maze size, cell size, or other parameters by updating the constants in the source code.

## Dependencies
SDL2: Simple DirectMedia Layer is used for graphical rendering.

## Contributing
Contributions are welcome! If you have any ideas, suggestions, or improvements, feel free to open an issue or submit a pull request.


