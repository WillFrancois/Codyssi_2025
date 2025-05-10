#include <fstream>
#include <iostream>
#include <set>

int main() {
  std::ifstream input("input.txt");
  std::string receiver;

  std::set<long long> set;
  long long acc = 0;

  while (!input.eof()) {
    try {
      getline(input, receiver);
      int split = receiver.find_first_of(" ");

      std::string l = receiver.substr(0, split);
      std::string r = receiver.substr(split, receiver.size());

      int split_l = l.find_first_of("-");
      int split_r = r.find_first_of("-");

      std::string l_l = l.substr(0, split_l);
      std::string l_r = l.substr(split_l + 1, l.size());
      std::string r_l = r.substr(0, split_r);
      std::string r_r = r.substr(split_r + 1, r.size());

      for (int i = std::stoll(l_l); i < std::stoll(l_r) + 1; i++) {
        set.insert(i);
      }

      for (int i = std::stoll(r_l); i < std::stoll(r_r) + 1; i++) {
        set.insert(i);
      }

      acc += set.size();
      set.clear();

    } catch (std::out_of_range) {
    }
  }

  std::cout << acc << std::endl;

  return 0;
}
