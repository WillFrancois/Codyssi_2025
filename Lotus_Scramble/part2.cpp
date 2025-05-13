#include <fstream>
#include <iostream>

int main() {
  std::ifstream input("./input.txt");
  std::string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string receiver = "";
  int out = 0;

  std::getline(input, receiver);

  for (char character : receiver) {
    if (alpha.find(character) != std::string::npos) {
      out += alpha.find(character) + 1;
    }
  }

  std::cout << out << std::endl;
}
