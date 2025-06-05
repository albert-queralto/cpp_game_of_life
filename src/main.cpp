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