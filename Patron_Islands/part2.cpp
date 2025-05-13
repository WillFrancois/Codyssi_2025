#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

class WorldSpace {
public:
  static std::tuple<long long, long long> position;
  static std::tuple<long long, long long> get_position() { return position; }
  static void set_position(std::tuple<long long, long long> new_pos) {
    position = new_pos;
  }
};

std::tuple<long long, long long> WorldSpace::position = std::make_tuple(0, 0);

int get_manhattan(std::tuple<long long, long long> island) {
  long long x = std::abs((std::get<0>(WorldSpace::get_position())) -
                         (std::get<0>(island)));
  long long y = std::abs((std::get<1>(WorldSpace::get_position())) -
                         (std::get<1>(island)));
  return x + y;
}

bool sort_islands(std::tuple<long long, long long> island1,
                  std::tuple<long long, long long> island2) {
  if (get_manhattan(island1) != get_manhattan(island2)) {
    return get_manhattan(island1) < get_manhattan(island2);
  } else if (std::get<0>(island1) != std::get<0>(island2)) {
    return std::get<0>(island1) < std::get<0>(island2);
  } else {
    return std::get<1>(island1) < std::get<1>(island1);
  }
}

int main() {
  std::ifstream input("./input.txt");
  std::string receiver;
  std::vector<std::tuple<long long, long long>> sorted_islands =
      std::vector<std::tuple<long long, long long>>();

  while (!input.eof()) {
    try {
      std::getline(input, receiver);
      int del_1 = receiver.find_first_of(",");
      int del_2 = receiver.find_first_of(")");

      long long num1 = std::stoll(receiver.substr(1, del_1));
      long long num2 = std::stoll(receiver.substr(del_1 + 2, del_2));

      auto island = std::make_tuple(num1, num2);

      sorted_islands.push_back(island);

    } catch (std::out_of_range) {
    }
  }

  std::sort(sorted_islands.begin(), sorted_islands.end(), sort_islands);

  WorldSpace::set_position(std::make_tuple(std::get<0>(sorted_islands[0]),
                                           std::get<1>(sorted_islands[0])));

  std::sort(sorted_islands.begin() + 1, sorted_islands.end(), sort_islands);

  std::cout << get_manhattan(sorted_islands[1]) << std::endl;

  return 0;
}
