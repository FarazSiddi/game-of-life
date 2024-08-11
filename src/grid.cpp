#include <raylib.h>
#include "grid.hpp"

void Grid::Draw()
{
  for(int row = 0; row < rows; row++)
  {
    for(int col = 0; col < cols; col++)
    {
      Color color = cells[row][col] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
      DrawRectangle(col * cell_size, row * cell_size, cell_size-1, cell_size-1, color);
    }
  }
}

void Grid::SetValue(int row, int col, int value)
{
  if(row >= 0 && row < rows && col >= 0 && col < cols)
  {
    cells[row][col] = value;
  }
}
