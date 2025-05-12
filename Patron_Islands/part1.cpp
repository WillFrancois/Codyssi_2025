#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>

int main() {
  auto position = std::make_tuple(0, 0);
  auto max_dist = 0;
  auto min_dist = INFINITY;
  std::ifstream input("./input.txt");
  std::string receiver;

  while (!input.eof()) {
    try {
      std::getline(input, receiver);
      int del_1 = receiver.find_first_of(",");
      int del_2 = receiver.find_first_of(")");

      long long num1 = std::stoll(receiver.substr(1, del_1));
      long long num2 = std::stoll(receiver.substr(del_1 + 2, del_2));

      std::cout << num1 << " " << num2 << std::endl;
      auto island = std::make_tuple(num1, num2);
      auto manhattan =
          std::abs(std::get<0>(island)) + std::abs(std::get<1>(island));

      if (manhattan > max_dist) {
        max_dist = manhattan;
      } else if (manhattan < min_dist) {
        min_dist = manhattan;
      }

    } catch (std::out_of_range) {
    }
  }

  std::cout << max_dist - min_dist << std::endl;

  return 0;
}
