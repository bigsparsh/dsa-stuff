#include <iostream>

int area (int length, int width) {
  return length * width;
}
int area (int side) {
  return side * side;
}
double area (double base, double height) {
  return base * height * 0.5;
}

int main () {
  int a, b;
  double c, d;
  std::cout << "\nEnter the side for the square: ";
  std::cin >> a;
  std::cout << "\nArea of square is: " << area (a);

  std::cout << "\nEnter the length and width for the rectangle: ";
  std::cin >> a >> b;
  std::cout << "\nArea of rectangle is: " << area (a, b);

  std::cout << "\nEnter the base and height for the triangle: ";
  std::cin >> c >> d;
  std::cout << "\nArea of triangle is: " << area (c, d);
}

