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
