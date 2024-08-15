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
  int live_neighbors = 0;
  std::vector<std::pair<int, int>> neighbor_offsets =
  {
    {-1, 0}, // top
    {1, 0}, // bottom
    {0, -1}, // left
    {0, 1}, // right
    {-1, -1}, // top left
    {-1, 1}, // top right
    {1, -1}, // bottom left
    {1, 1} // bottom right
  };

  for(const auto& offset : neighbor_offsets)
  {
    int neighbor_row = (row + offset.first + grid.GetRows()) % grid.GetRows();
    int neighbor_col = (col + offset.second + grid.GetCols()) % grid.GetCols();
    live_neighbors += grid.GetValue(neighbor_row, neighbor_col);
  }
  return live_neighbors;
  
}

void Simulation::Update()
{
  if(IsRunning())
  {
    for(int row = 0; row < grid.GetRows(); row++)
    {
      for(int col = 0; col < grid.GetCols(); col++)
      {
        int live_neighbors = CountLiveNeighbors(row, col);
        int cell_value = grid.GetValue(row, col);

        if(cell_value == 1)
        {
          if(live_neighbors < 2 || live_neighbors > 3)
          {
            tempGrid.SetValue(row, col, 0);
          }
          else
          {
            tempGrid.SetValue(row, col, 1);
          }
        }
        else{
          if(live_neighbors == 3)
          {
            tempGrid.SetValue(row, col, 1);
          }
          else
          {
            tempGrid.SetValue(row, col, 0);
          }
        }
      }
    }
    grid = tempGrid;
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
    grid.FillRand();
  }
}

void Simulation::ToggleCell(int row, int col)
{
  if(!IsRunning())
  {
    grid.ToggleCell(row, col);
  }
}
