#pragma once
#include "grid.hpp"

class Simulation
{
  public:
    Simulation(int width, int height, int cell_size)
    : grid(width, height, cell_size), tempGrid(width, height, cell_size), run(false) {grid.FillRand();};
    void Draw();
    void SetCellValue(int row, int col, int value);
    int CountLiveNeighbors(int row, int col);
    void Update();
    bool IsRunning() {return run;}
    void Start() {run = true;}
    void Stop() {run = false;}
  private:
    Grid grid;
    Grid tempGrid;
    bool run;
};