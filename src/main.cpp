#include <raylib.h>
#include <iostream>
#include "simulation.hpp"

int main()
{
    Color darkGray = {29, 29, 29, 255};

    const int SCREEN_WIDTH = 800; // Width of the Grid
    const int SCREEN_HEIGHT = 200; // Height of the Grid

    const int WINDOW_WIDTH = SCREEN_WIDTH + 300;
    const int WINDOW_HEIGHT = SCREEN_HEIGHT + 100;

    const int CELL_SIZE = 20;
    int fps = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life Simulator");

    Font font = LoadFontEx("fonts/monogram.ttf", 132, 0, 0);

    SetTargetFPS(fps);
    Simulation simulation(SCREEN_WIDTH, SCREEN_HEIGHT, CELL_SIZE);

    char stateText[10];
    char fpsText[10];
    sprintf(stateText, "Stopped");
    sprintf(fpsText, "FPS: %d", fps);

    while(!WindowShouldClose())
    {

        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            Vector2 mousePosition = GetMousePosition();
            int row = (mousePosition.y - 75) / CELL_SIZE;
            int col = (mousePosition.x - 25) / CELL_SIZE;

            simulation.ToggleCell(row, col);
        }
        if(IsKeyPressed(KEY_ENTER))
        {
            simulation.Start();
            SetWindowTitle("Game of Life Simulator - Running");

            sprintf(stateText, "Running");
        }
        if(IsKeyPressed(KEY_SPACE))
        {
            simulation.Stop();
            SetWindowTitle("Game of Life Simulator - Stopped");
            sprintf(stateText, "Stopped");
        }
        if(IsKeyPressed(KEY_UP))
        {
            fps += 2;
            SetTargetFPS(fps);
            sprintf(fpsText, "FPS: %d", fps);
        }
        if(IsKeyPressed(KEY_DOWN)) 
        {
            if(fps > 2)
            {
                fps -= 2;
                SetTargetFPS(fps);
                SetTargetFPS(fps);
                sprintf(fpsText, "FPS: %d", fps);
            }
        }
        if(IsKeyPressed(KEY_C))
        {
            simulation.ClearGrid();
        }

        if(IsKeyPressed(KEY_R))
        {
            simulation.CreateRandomState();
        }

        simulation.Update();

        BeginDrawing();
        ClearBackground(darkGray);

        simulation.Draw();

        DrawTextEx(font, stateText, {40, 15}, 50.0, 0.0, WHITE);
        DrawTextEx(font, fpsText, {SCREEN_WIDTH + 100, 15}, 50.0, 0.0, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}