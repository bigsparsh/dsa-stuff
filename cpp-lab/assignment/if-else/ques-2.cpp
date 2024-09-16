// 2. Any integer is input through the keyboard. Write a program in C++ to find out whether it is an odd number or even number.

#include <iostream>

int main () {
  int n;
  std::cout << "Enter a number: ";
  std::cin >> n;

  if (n % 2 == 0) {
    std::cout << n << " is an even number" << std::endl;
  } else {
    std::cout << n << " is an odd number" << std::endl;
  }

  return 0;
}
