#include <raylib.h>
#include <iostream>
#include "simulation.hpp"

int main()
{
    Color darkGray = {29, 29, 29, 255};

    const int SCREEN_WIDTH = 750;
    const int SCREEN_HEIGHT = 750;
    const int CELL_SIZE = 25;
    int fps = 12;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game of Life Simulator");
    SetTargetFPS(fps);
    Simulation simulation(SCREEN_WIDTH, SCREEN_HEIGHT, CELL_SIZE);

    // simulation.SetCellValue(5, 29, 1);
    // simulation.SetCellValue(6, 0, 1);
    // simulation.SetCellValue(5, 0, 1);
    // simulation.SetCellValue(4, 0, 1);

    // std::cout << simulation.CountLiveNeighbors(5, 29) << std::endl;

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkGray);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}