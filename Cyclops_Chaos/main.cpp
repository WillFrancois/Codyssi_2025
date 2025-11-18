#include "./parts/part1.cpp"
#include "./parts/part2.cpp"
#include "./parts/part3.cpp"
#include <fstream>
#include <iostream>
#include <vector>

int main() {
  std::ifstream input("input.txt");
  std::string contents;
  std::vector<std::vector<int>> grid;

  while (std::getline(input, contents)) {
    std::vector<int> row;
    auto pos = contents.find(' ');

    while (pos != std::string::npos) {
      row.push_back(std::stoi(contents.substr(0, pos)));
      contents.erase(0, pos + 1);
      pos = contents.find(' ');
    }

    row.push_back(
        std::stoi(contents.substr(contents.size() - 1, contents.size())));
    grid.push_back(row);
  }

  std::cout << part1(grid) << std::endl;
  std::cout << part2(grid) << std::endl;
}
