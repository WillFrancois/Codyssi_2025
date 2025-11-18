#pragma once
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

int part1(std::vector<std::vector<int>> grid) {
  int lowest = INT32_MAX;

  for (std::vector<int> row : grid) {
    int sum = std::accumulate(row.begin(), row.end(), 0);
    if (sum < lowest) {
      lowest = sum;
    }
  }

  for (int i = 0; i < grid[0].size(); i++) {
    int sum = 0;
    for (int j = 0; j < grid.size(); j++) {
      sum += grid[j][i];
    }
    if (sum < lowest) {
      lowest = sum;
    }
  }

  return lowest;
}
