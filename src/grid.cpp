#include "raylib.h"
#include "grid.hpp"

void Grid::Draw()
{
    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < cols; col++)
        {
            Color color;
            switch (cells[row][col]) {
                case DEAD:    color = Color{55, 55, 55, 255}; break;
                case ALIVE:   color = Color{0, 255, 0, 255}; break;
                case NEWBORN: color = Color{0, 200, 255, 255}; break; // Cyan for newborn
                case DYING:   color = Color{255, 100, 0, 255}; break; // Orange for dying
                default:      color = Color{55, 55, 55, 255}; break;
            }
            DrawRectangle(col * cellSize, row * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }
}

void Grid::SetValue(int row, int col, CellState value)
{
    if(IsWithinBounds(row, col))
    {
        cells[row][col] = value;
    }
}

CellState Grid::GetValue(int row, int col)
{
    if(IsWithinBounds(row, col))
    {
        return cells[row][col];
    }
    return DEAD;
}

bool Grid::IsWithinBounds(int row, int col)
{
    if(row >= 0 && row < rows && col >= 0 && col < cols)
    {
        return true;
    }
    return false;
}

void Grid::FillRandom()
{
    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < cols; col++)
        {
            int r = GetRandomValue(0, 4);
            if (r == 4)
                cells[row][col] = NEWBORN;
            else
                cells[row][col] = DEAD;
        }
    }
}

void Grid::Clear()
{
    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < cols; col++)
        {
            cells[row][col] = DEAD;
        }
    }
}
