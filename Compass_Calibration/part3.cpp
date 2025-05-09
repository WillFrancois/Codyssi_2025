#include <fstream>
#include <iostream>
#include <vector>

int calculate(int num1, int num2, char operation) {
  switch (operation) {
  case '+':
    return num1 + num2;
    break;
  case '-':
    return num1 - num2;
    break;
  }
  return 0;
}

int main() {
  std::fstream str("input.txt", std::ios::in);
  std::string receiver;
  std::vector<int> nums = std::vector<int>();
  std::vector<char> operations = std::vector<char>();

  int output = 0;

  do {
    str >> receiver;
    std::cout << receiver << std::endl;

    try {
      int result = std::stoi(receiver);
      nums.push_back(result);
    } catch (std::exception) {
      for (char character : receiver) {
        operations.push_back(character);
      }
      break;
    }
  } while (true);

  output = nums[0] * 10 + nums[1];

  for (int i = 3; i < nums.size(); i += 2) {
    output = calculate(output, nums[i - 1] * 10 + nums[i],
                       operations[operations.size() - (i / 2)]);
  }

  std::cout << output << std::endl;
}
