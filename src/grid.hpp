#pragma once
#include <vector>

class Grid
{
    public:
        Grid(int width, int height, int cellSize)
            : rows(height/cellSize),
            cols(width/cellSize), 
            cellSize(cellSize), 
            cells(rows, std::vector<int>(cols, 0))
            {};
        void Draw();
        void SetValue(int row, int col, int value);

    private:
        int rows;
        int cols;
        int cellSize;
        std::vector<std::vector<int>> cells; // 2D vector to represent the grid
};