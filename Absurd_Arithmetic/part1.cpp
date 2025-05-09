#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

#define B 63
#define A 509

long long c(long long quality) { return quality * quality * quality; }
long long b(long long quality) { return quality * B; }
long long a(long long quality) { return quality + A; }

int main() {
  std::ifstream input("input.txt");
  std::string receiver;
  std::vector<long long> qualities;

  while (!input.eof()) {
    std::getline(input, receiver);
    try {
      long long quality = std::stoll(receiver);
      qualities.push_back(quality);
    } catch (std::exception) {
    }
  }
  std::sort(qualities.begin(), qualities.end());

  long long median = qualities[qualities.size() / 2];
  median = c(median);
  median = b(median);
  median = a(median);

  std::cout << median << std::endl;

  return 0;
}
