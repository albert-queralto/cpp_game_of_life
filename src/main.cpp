#include <raylib.h>

int main() {

    Color GREY = {29, 29, 29, 255};
    const int WINDOW_WIDTH = 750;
    const int WINDOW_HEIGHT = 750;
    int FPS = 12;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
    SetTargetFPS(FPS);

    // Simulation loop
    while(WindowShouldClose() == false) {
        // Event handling


        // Updating state


        // Drawing
        BeginDrawing();
        ClearBackground(GREY);
        EndDrawing();

    }

    CloseWindow();
    return 0;
}