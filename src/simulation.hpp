#pragma once
#include "grid.hpp"

class Simulation
{
  public:
    Simulation(int width, int height, int cell_size)
    : grid(width, height, cell_size) {};
    void Draw();
    void SetCellValue(int row, int col, int value);
    int CountLiveNeighbors(int row, int col);
  private:
    Grid grid;
};