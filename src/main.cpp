#include <raylib.h>
#include <iostream>
#include "simulation.hpp"

int main()
{
    Color darkGray = {29, 29, 29, 255};

    const int SCREEN_WIDTH = 800; // Width of the Grid
    const int SCREEN_HEIGHT = 800; // Height of the Grid

    const int WINDOW_WIDTH = SCREEN_WIDTH + 350;
    const int WINDOW_HEIGHT = SCREEN_HEIGHT + 100;

    const int CELL_SIZE = 15;
    int fps = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life Simulator");

    Font font = LoadFontEx("fonts/monogram.ttf", 132, 0, 0);

    SetTargetFPS(fps);
    Simulation simulation(SCREEN_WIDTH, SCREEN_HEIGHT, CELL_SIZE);

    char stateText[10];
    char fpsText[10];
    sprintf(stateText, "Stopped");
    sprintf(fpsText, "FPS: %d", fps);

    Rectangle clearButton = {SCREEN_WIDTH + 75, 125, 200, 50};
    Rectangle randomButton = {SCREEN_WIDTH + 75, 225, 200, 50};
    Rectangle startButton = {SCREEN_WIDTH + 75, 325, 200, 50};
    Rectangle stopButton = {SCREEN_WIDTH + 75, 425, 200, 50};
    Rectangle addFPSButton = {SCREEN_WIDTH + 180, 75, 25, 25};
    Rectangle subtractFPSButton = {SCREEN_WIDTH + 130, 75, 25, 25};

    Color clearButtonColor = LIGHTGRAY;
    Color randomButtonColor = LIGHTGRAY;
    Color startButtonColor = LIGHTGRAY;
    Color stopButtonColor = LIGHTGRAY;
    Color addFPSButtonColor = LIGHTGRAY;
    Color subtractFPSButtonColor = LIGHTGRAY;


    while(!WindowShouldClose())
    {
        bool clearButtonPressed = false;
        bool randomButtonPressed = false;
        bool startButtonPressed = false;
        bool stopButtonPressed = false;
        bool addFPSButtonPressed = false;
        bool subtractFPSButtonPressed = false;

        Vector2 mousePosition = GetMousePosition();

        // Clear Button
        if (CheckCollisionPointRec(mousePosition, clearButton)) {
            clearButtonColor = DARKGRAY;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                clearButtonPressed = true;
            }
        } else {
            clearButtonColor = LIGHTGRAY;
        }

        // Random Button
        if (CheckCollisionPointRec(mousePosition, randomButton)) {
            randomButtonColor = DARKGRAY;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                randomButtonPressed = true;
            }
        } else {
            randomButtonColor = LIGHTGRAY;
        }

        // Start Button
        if (CheckCollisionPointRec(mousePosition, startButton)) {
            startButtonColor = DARKGRAY;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                startButtonPressed = true;
            }
        } else {
            startButtonColor = LIGHTGRAY;
        }

        // Stop Button
        if (CheckCollisionPointRec(mousePosition, stopButton)) {
            stopButtonColor = DARKGRAY;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                stopButtonPressed = true;
            }
        } else {
            stopButtonColor = LIGHTGRAY;
        }

        // Add FPS Button
        if (CheckCollisionPointRec(mousePosition, addFPSButton)) {
            addFPSButtonColor = DARKGRAY;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                addFPSButtonPressed = true;
            }
        } else {
            addFPSButtonColor = LIGHTGRAY;
        }

        // Subtract FPS Button
        if (CheckCollisionPointRec(mousePosition, subtractFPSButton)) {
            subtractFPSButtonColor = DARKGRAY;
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                subtractFPSButtonPressed = true;
            }
        } else {
            subtractFPSButtonColor = LIGHTGRAY;
        }

        // Mouse Input
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            int row = (mousePosition.y - 75) / CELL_SIZE;
            int col = (mousePosition.x - 25) / CELL_SIZE;

            simulation.ToggleCell(row, col);
        }

        // Keyboard Input
        if(IsKeyPressed(KEY_ENTER) || startButtonPressed)
        {
            simulation.Start();
            SetWindowTitle("Game of Life Simulator - Running");

            sprintf(stateText, "Running");
        }
        if(IsKeyPressed(KEY_SPACE) || stopButtonPressed)
        {
            simulation.Stop();
            SetWindowTitle("Game of Life Simulator - Stopped");
            sprintf(stateText, "Stopped");
        }
        if(IsKeyPressed(KEY_UP) || addFPSButtonPressed)
        {
            fps += 2;
            SetTargetFPS(fps);
            sprintf(fpsText, "FPS: %d", fps);
        }
        if(IsKeyPressed(KEY_DOWN) || subtractFPSButtonPressed) 
        {
            if(fps > 2)
            {
                fps -= 2;
                SetTargetFPS(fps);
                SetTargetFPS(fps);
                sprintf(fpsText, "FPS: %d", fps);
            }
        }
        if(IsKeyPressed(KEY_C) || clearButtonPressed)
        {
            simulation.ClearGrid();
        }

        if(IsKeyPressed(KEY_R) || randomButtonPressed)
        {
            simulation.CreateRandomState();
        }

        simulation.Update();

        BeginDrawing();
        ClearBackground(darkGray);

        simulation.Draw();

        DrawTextEx(font, stateText, {40, 15}, 50.0, 0.0, WHITE);
        DrawTextEx(font, fpsText, {SCREEN_WIDTH + 85, 15}, 50.0, 0.0, WHITE);

        // Draw Buttons
        DrawRectangleRec(clearButton, clearButtonColor);
        DrawRectangleRec(randomButton, randomButtonColor);
        DrawRectangleRec(startButton, startButtonColor);
        DrawRectangleRec(stopButton, stopButtonColor);

        DrawRectangleRec(addFPSButton, addFPSButtonColor);
        DrawRectangleRec(subtractFPSButton, subtractFPSButtonColor);
        
        DrawTextEx(font, "Clear", {SCREEN_WIDTH + 115, 120}, 50.0, 0.0, WHITE);
        DrawTextEx(font, "Random", {SCREEN_WIDTH + 100, 220}, 50.0, 0.0, WHITE);
        DrawTextEx(font, "Start", {SCREEN_WIDTH + 110, 320}, 50.0, 0.0, WHITE);
        DrawTextEx(font, "Stop", {SCREEN_WIDTH + 120, 420}, 50.0, 0.0, WHITE);

        DrawTextEx(font, "+", {SCREEN_WIDTH + 187, 70}, 30.0, 0.0, WHITE);
        DrawTextEx(font, "-", {SCREEN_WIDTH + 137, 70}, 30.0, 0.0, WHITE);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}