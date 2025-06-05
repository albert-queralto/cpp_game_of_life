#include <raylib.h>
#include "grid.hpp"

int main() {

    Color GREY = {29, 29, 29, 255};
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 10; // Size of each cell in pixels
    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    Grid grid{WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE};
    grid.SetValue(0, 0, 1); // Example to set a cell alive

    // Simulation loop
    while(WindowShouldClose() == false) {
        // Event handling


        // Updating state


        // Drawing
        BeginDrawing();
        ClearBackground(GREY);
        grid.Draw();
        EndDrawing();

    }

    CloseWindow();
    return 0;
}