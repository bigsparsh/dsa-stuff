// 6. If the three sides of a triangle are entered through the keyboard, write a program to check whether the triangle is isosceles, equilateral, scalene or right angled triangle.

#include <iostream>

int main () {
  int a, b, c;
  std::cout << "Enter the three sides of a triangle: ";
  std::cin >> a >> b >> c;

  if (a == b && b == c) {
    std::cout << "Equilateral Triangle" << std::endl;
  } else if (a == b || b == c || c == a) {
    std::cout << "Isosceles Triangle" << std::endl;
  } else if (a*a + b*b == c*c || b*b + c*c == a*a || c*c + a*a == b*b) {
    std::cout << "Right Angled Triangle" << std::endl;
  } else {
    std::cout << "Scalene Triangle" << std::endl;
  }

  return 0;
}
