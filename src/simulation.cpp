#include <vector>
#include <utility>
#include "simulation.hpp"

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::SetCellValue(int row, int col, int value)
{
    grid.SetValue(row, col, value);
}

int Simulation::CountLiveNeighbors(int row, int col)
{
    int liveNeighbors = 0;
    std::vector<std::pair<int, int>> neighborOffsets = {
        {-1, 0}, // Directly above
        {1, 0},  // Directly below
        {0, -1}, // Directly left
        {0, 1},  // Directly right
        {-1, -1}, // Top-left diagonal
        {-1, 1},  // Top-right diagonal
        {1, -1},  // Bottom-left diagonal
        {1, 1}    // Bottom-right diagonal
    };

    for(const auto& offset : neighborOffsets)
    {
        int neighborRow = (row + offset.first + grid.GetRows()) % grid.GetRows(); 
        int neighborCol = (col + offset.second + grid.GetCols()) % grid.GetCols();
        liveNeighbors += grid.GetValue(neighborRow, neighborCol);
    }
    return liveNeighbors;
}
