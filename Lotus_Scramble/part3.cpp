#include <fstream>
#include <iostream>

int main() {
  std::ifstream input("./input.txt");
  std::string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string receiver = "";
  int out = 0;
  int last = 0;

  std::getline(input, receiver);

  for (char character : receiver) {
    int idx = alpha.find(character);
    if (idx != std::string::npos) {
      out += idx + 1;
      last = idx + 1;
    } else {
      int res = last * 2 - 5;
      while (res > 52) {
        res -= 52;
      }
      while (res < 1) {
        res += 52;
      }
      last = res;
      out += res;
    }
  }

  std::cout << out << std::endl;
}
