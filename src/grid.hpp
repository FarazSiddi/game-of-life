#pragma once
#include <vector>

class Grid
{
  public:
    Grid(int n_width, int n_height, int n_cell_size)
    : rows(n_height/n_cell_size), cols(n_width/n_cell_size), cell_size(n_cell_size), cells(rows, std::vector<int>(cols, 0)) {};
    void Draw();
    void SetValue(int row, int col, int value);
    int GetValue(int row, int col);
    bool IsWithinBounds(int row, int col);
    int GetRows() { return rows; }
    int GetCols() { return cols; }
    void FillRand();
    void Clear();
    void ToggleCell(int row, int col);
  private:
    int rows;
    int cols;
    int cell_size;
    std::vector<std::vector<int>> cells;
};