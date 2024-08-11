#include <raylib.h>
#include "grid.hpp"

int main()
{
    Color darkGray = {29, 29, 29, 255};

    const int SCREEN_WIDTH = 750;
    const int SCREEN_HEIGHT = 750;
    const int CELL_SIZE = 25;
    int fps = 12;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game of Life Simulator");
    SetTargetFPS(fps);
    Grid grid(SCREEN_WIDTH, SCREEN_HEIGHT, CELL_SIZE);

    while(!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(darkGray);
        grid.Draw();
        EndDrawing();

    }

    CloseWindow();
    return 0;
}