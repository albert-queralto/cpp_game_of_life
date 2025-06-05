#include <raylib.h>
#include <iostream>
#include "simulation.hpp"

int main() {

    Color GREY = {29, 29, 29, 255};
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 4; // Size of each cell in pixels
    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);

    // Simulation loop
    while(WindowShouldClose() == false) {
        // Event handling
        if(IsKeyPressed(KEY_SPACE)) {
            if(simulation.IsRunning()) {
                simulation.Stop();
                SetWindowTitle("Game of Life - Paused");
            } else {
                simulation.Start();
                SetWindowTitle("Game of Life - Running");
            }
        }
        else if(IsKeyPressed(KEY_R)) {
            simulation.CreateRandomState(); // Reset the simulation
            SetWindowTitle("Game of Life - Reset");
        }
        else if(IsKeyPressed(KEY_W)) {
            FPS += 2; // Increase FPS
            SetTargetFPS(FPS);
            SetWindowTitle(("Game of Life - Running at " + std::to_string(FPS) + " FPS").c_str());
        }
        else if(IsKeyPressed(KEY_S)) {
            if(FPS > 2) {
                FPS -= 2; // Decrease FPS
                SetTargetFPS(FPS);
                SetWindowTitle(("Game of Life - Running at " + std::to_string(FPS) + " FPS").c_str());
            }
        }
        else if(IsKeyPressed(KEY_C)) {
            // Clear the grid
            simulation.ClearGrid();
            SetWindowTitle("Game of Life - Cleared");
        }
        else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePos = GetMousePosition();
            int row = mousePos.y / CELL_SIZE;
            int col = mousePos.x / CELL_SIZE;
            simulation.SetCellValue(row, col, 1); // Set cell to alive
        }
        else if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            Vector2 mousePos = GetMousePosition();
            int row = mousePos.y / CELL_SIZE;
            int col = mousePos.x / CELL_SIZE;
            simulation.SetCellValue(row, col, 0); // Set cell to dead
        }

        // Updating state
        simulation.Update();

        // Drawing
        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();

    }

    CloseWindow();
    return 0;
}