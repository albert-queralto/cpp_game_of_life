#include <vector>
#include <utility>
#include "simulation.hpp"

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::SetCellValue(int row, int col, CellState value)
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
        CellState neighborState = grid.GetValue(neighborRow, neighborCol);
        if (neighborState == ALIVE || neighborState == DYING)
            liveNeighbors++;
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
                CellState currentValue = grid.GetValue(row, col);

                // State transitions
                if(currentValue == DEAD)
                {
                    if(liveNeighbors == 3)
                        tempGrid.SetValue(row, col, NEWBORN); // Dead cell with 3 neighbors becomes NEWBORN
                    else
                        tempGrid.SetValue(row, col, DEAD);
                }
                else if(currentValue == NEWBORN)
                {
                    tempGrid.SetValue(row, col, ALIVE); // NEWBORN becomes ALIVE
                }
                else if(currentValue == ALIVE)
                {
                    if(liveNeighbors < 2 || liveNeighbors > 3)
                        tempGrid.SetValue(row, col, DYING); // ALIVE with too few/many neighbors becomes DYING
                    else
                        tempGrid.SetValue(row, col, ALIVE); // Otherwise stays ALIVE
                }
                else if(currentValue == DYING)
                {
                    tempGrid.SetValue(row, col, DEAD); // DYING becomes DEAD
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
