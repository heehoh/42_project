#include <iostream>

int main() {
  int *arr = new int[0];
  int *arr2 = new int[0];
  std::cout << arr << std::endl;
  std::cout << arr[0] << std::endl;

  return 0;
}