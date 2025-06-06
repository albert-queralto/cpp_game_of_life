#pragma once
#include <vector>


enum CellState {
    DEAD = 0,
    ALIVE = 1,
    NEWBORN = 2,
    DYING = 3
};

class Grid
{
    public:
        Grid(int width, int height, int cellSize)
            : rows(height/cellSize),
            cols(width/cellSize), 
            cellSize(cellSize), 
            cells(rows, std::vector<CellState>(cols, DEAD))
            {};
        void Draw();
        void SetValue(int row, int col, CellState value);
        CellState GetValue(int row, int col);
        bool IsWithinBounds(int row, int col);
        int GetRows() { return rows; }
        int GetCols() { return cols; }
        void FillRandom();
        void Clear();

    private:
        int rows;
        int cols;
        int cellSize;
        std::vector<std::vector<CellState>> cells; // 2D vector to represent the grid
};