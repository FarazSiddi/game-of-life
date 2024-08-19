# game-of-life

A simulation of Conway's Game of Life using C++ and Raylib

## Screenshots

<p width="600">
  Game of Life:
  </br>
    <img src="https://github.com/FarazSiddi/game-of-life/blob/master/images/cgol.png" alt="cgol" width="600" >
</p>

## About the Project

Since the beginning of April 2024, I haven't worked on any programming projects for a few months until recently. I have decided to embark on this project as a way to review my knowledge of data structures and the C++ syntax to get even more familiar with this environment. I decided to make a Game of Life Simulator as a quick and simple project to work on my free time to get back into my usual routine.

## What is Conway's Game of Life?

Conway's Game of Life is a cellular automaton devised by mathematician John Conway in 1970. It consists of a grid of cells that can be in one of two states: alive or dead. The game evolves in discrete steps according to a set of simple rules based on the states of neighboring cells: a living cell with two or three neighbors stays alive, while a living cell with fewer than two or more than three neighbors dies. A dead cell with exactly three neighbors becomes alive. Despite its simple rules, the Game of Life can produce complex and varied patterns, making it a popular example in the study of emergent behavior and complexity.

### How does the algorithm work?

Let's have a look at the rules of CGOL in better detail:

- If a live cell has fewer than two live neighbors, it dies (Underpopulation)
- If a live cell is next to two or three live neighbors, it lives on to the next generation (Stasis)
- If a live cell has more than three live neighbors, it dies (Overpopulation)
- If there is a dead cell with exactly three live neighbors, it becomes a live cell (Reproduction)

All cells have a total of eight neigbors. Furthermore, the grid in this program is a Toroidal Grid, which is a type of grid where the edges are connected in such a way that the grid wraps around both horizontally and vertically, creating a continuous surface without boundaries. In a 2D toroidal grid, the left edge is connected to the right edge, and the top edge is connected to the bottom edge, effectively forming the shape of a torus (a doughnut-shaped surface). This means that if you move off one edge of the grid, you reappear on the opposite edge. Thus, it would create a seamless, infinite-like environment.

## Getting Started

Make sure to have Mingw64 installed onto your computer, then open the project folder and double-click on the Makefile. Then once Visual Studio Code opens, press F5 to compile the code and launch the program.
