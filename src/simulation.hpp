#pragma once
#include "grid.hpp"

class Simulation {
    public:
        Simulation(int width, int height, int cellSize)
            : grid(width, height, cellSize), 
            tempGrid(width, height, cellSize),
            run(false)
            {};
        void Draw();
        void SetCellValue(int row, int col, CellState value);
        int CountLiveNeighbors(int row, int col);
        void Update();
        bool IsRunning() { return run; }
        void Start() { run = true; }
        void Stop() { run = false; }
        void ClearGrid();
        void CreateRandomState();

    private:
        Grid grid;
        Grid tempGrid;
        bool run;
};