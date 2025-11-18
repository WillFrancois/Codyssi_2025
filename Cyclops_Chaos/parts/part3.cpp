#pragma once
#include <cstdint>
#include <vector>

int part3(std::vector<std::vector<int>> grid) {
  int lowest = INT32_MAX;

  for (int r = 0; r < grid[0].size(); r++) {
    for (int c = 0; c < grid.size(); c++) {
      if (r == 0 && c != 0) {
        grid[r][c] = grid[r][c] + grid[r][c - 1];
      } else if (r != 0 && c == 0) {
        grid[r][c] = grid[r][c] + grid[r - 1][c];
      } else if (r == 0 && c == 0) {
        continue;
      } else {
        int p1 = grid[r][c] + grid[r][c - 1];
        int p2 = grid[r][c] + grid[r - 1][c];

        if (p1 < p2) {
          grid[r][c] = p1;
        } else {
          grid[r][c] = p2;
        }
      }
    }
  }

  return grid[49][49];
}
