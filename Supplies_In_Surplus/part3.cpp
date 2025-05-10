#include <fstream>
#include <iostream>
#include <set>

int main() {
  std::ifstream input("input.txt");
  std::string receiver;
  std::string receiver2;

  std::set<long long> set;
  long long acc = 0;

  getline(input, receiver);
  while (!input.eof()) {
    try {
      getline(input, receiver2);
      int split = receiver.find_first_of(" ");
      int split2 = receiver2.find_first_of(" ");

      std::string l = receiver.substr(0, split);
      std::string r = receiver.substr(split, receiver.size());
      std::string l2 = receiver2.substr(0, split2);
      std::string r2 = receiver2.substr(split2, receiver.size());

      int split_l = l.find_first_of("-");
      int split_r = r.find_first_of("-");
      int split2_l = l2.find_first_of("-");
      int split2_r = r2.find_first_of("-");

      std::string l_l = l.substr(0, split_l);
      std::string l_r = l.substr(split_l + 1, l.size());
      std::string r_l = r.substr(0, split_r);
      std::string r_r = r.substr(split_r + 1, r.size());
      std::string l2_l = l2.substr(0, split2_l);
      std::string l2_r = l2.substr(split2_l + 1, l2.size());
      std::string r2_l = r2.substr(0, split2_r);
      std::string r2_r = r2.substr(split2_r + 1, r2.size());

      for (int i = std::stoll(l_l); i < std::stoll(l_r) + 1; i++) {
        set.insert(i);
      }

      for (int i = std::stoll(r_l); i < std::stoll(r_r) + 1; i++) {
        set.insert(i);
      }

      for (int i = std::stoll(l2_l); i < std::stoll(l2_r) + 1; i++) {
        set.insert(i);
      }

      for (int i = std::stoll(r2_l); i < std::stoll(r2_r) + 1; i++) {
        set.insert(i);
      }

      acc = std::max(acc, (long long)set.size());
      set.clear();

      receiver = receiver2;

    } catch (std::out_of_range) {
    }
  }

  std::cout << acc << std::endl;

  return 0;
}
