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

void Simulation::Update()
{
    if(IsRunning())
    {
        for(int row = 0; row < grid.GetRows(); row++)
        {
            for(int col = 0; col < grid.GetCols(); col++)
            {
                int liveNeighbors = CountLiveNeighbors(row, col);
                int currentValue = grid.GetValue(row, col);

                if(currentValue == 1) // Cell is currently alive
                {
                    if(liveNeighbors < 2 || liveNeighbors > 3)
                    {
                        tempGrid.SetValue(row, col, 0); // Cell dies
                    }
                    else
                    {
                        tempGrid.SetValue(row, col, 1); // Cell stays alive
                    }
                }
                else // Cell is currently dead
                {
                    if(liveNeighbors == 3)
                    {
                        tempGrid.SetValue(row, col, 1); // Cell becomes alive
                    }
                    else
                    {
                        tempGrid.SetValue(row, col, 0); // Cell stays dead
                    }
                }
            }
        }

        // Swap grids
        std::swap(grid, tempGrid);
    }
}

void Simulation::ClearGrid()
{
    if(!IsRunning())
    {
        grid.Clear();
    }
}

void Simulation::CreateRandomState()
{
    if(!IsRunning())
    {
        grid.FillRandom();
    }
}
