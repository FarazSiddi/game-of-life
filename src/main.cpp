#include <raylib.h>
#include <iostream>
#include "simulation.hpp"

int main()
{
    Color darkGray = {29, 29, 29, 255};

    const int SCREEN_WIDTH = 750;
    const int SCREEN_HEIGHT = 750;
    const int CELL_SIZE = 4;
    int fps = 12;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game of Life Simulator");
    SetTargetFPS(fps);
    Simulation simulation(SCREEN_WIDTH, SCREEN_HEIGHT, CELL_SIZE);

    while(!WindowShouldClose())
    {
        if(IsKeyPressed(KEY_ENTER))
        {
            simulation.Start();
            SetWindowTitle("Game of Life Simulator - Running");
        }
        if(IsKeyPressed(KEY_SPACE))
        {
            simulation.Stop();
            SetWindowTitle("Game of Life Simulator - Stopped");
        }
        if(IsKeyPressed(KEY_UP))
        {
            fps += 2;
            SetTargetFPS(fps);
        }
        if(IsKeyPressed(KEY_DOWN)) 
        {
            if(fps > 2)
            {
                fps -= 2;
                SetTargetFPS(fps);
            }
        }

        simulation.Update();

        BeginDrawing();
        ClearBackground(darkGray);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}