#include <raylib.h>
#include <iostream>
#include "simulation.hpp"

int main() {

    Color GREY = {29, 29, 29, 255};
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    const int CELL_SIZE = 10; // Size of each cell in pixels
    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);
    Simulation simulation(WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE);
    simulation.SetCellValue(5, 29, 1); // Example to set a cell value
    simulation.SetCellValue(6, 0, 1); // Example to set a cell value
    simulation.SetCellValue(5, 0, 1); // Example to set a cell value
    simulation.SetCellValue(4, 0, 1); // Example to set a cell value

    std::cout << simulation.CountLiveNeighbors(5, 5) << std::endl; // Example to count live neighbors

    // Simulation loop
    while(WindowShouldClose() == false) {
        // Event handling


        // Updating state


        // Drawing
        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();

    }

    CloseWindow();
    return 0;
}