// 7. If the three sides of a triangle are entered through the keyboard, write a program to check whether the triangle is valid or not. The triangle is valid if the sum of two sides is greater than the largest of the three sides.

#include <iostream>

int main () {
  int a, b, c;
  std::cout << "Enter the three sides of a triangle: ";
  std::cin >> a >> b >> c;

  if (a + b > c && b + c > a && c + a > b) {
    std::cout << "Valid Triangle" << std::endl;
  } else {
    std::cout << "Invalid Triangle" << std::endl;
  }

  return 0;
}
