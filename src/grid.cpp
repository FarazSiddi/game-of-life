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
  if(IsWithinBounds(row, col))
  {
    cells[row][col] = value;
  }
}

int Grid::GetValue(int row, int col)
{
  if (IsWithinBounds(row, col))
  {
    return cells[row][col];
  }
  return 0;
}

bool Grid::IsWithinBounds(int row, int col)
{
  if(row >= 0 && row < rows && col >= 0 && col < cols)
  {
    return true;
  }
  return false;
}

void Grid::FillRand()
{
  for(int row = 0; row < rows; row++)
  {
    for(int col = 0; col < cols; col++)
    {
      int randomValue = GetRandomValue(0, 4);
      cells[row][col] = (randomValue == 4) ? 1 : 0;
    }
  }

}

void Grid::Clear()
{
  for(int row = 0; row < rows; row++)
  {
    for(int col = 0; col < cols; col++)
    {
      cells[row][col] = 0;
    }
  }
}

void Grid::ToggleCell(int row, int col)
{
  if(IsWithinBounds(row, col))
  {
    cells[row][col] = !cells[row][col];
  }
}
