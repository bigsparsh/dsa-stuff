// 10. Given the length and breadth of a rectangle, write a program to find whether the area of the rectangle is greater than its perimeter. For example, the area of the rectangle with length = 5 and breadth = 4 is greater than its perimeter.

#include <iostream>
int main () {

  int length, breadth;
  std::cout << "Enter the length of the rectangle: ";
  std::cin >> length;
  std::cout << "Enter the breadth of the rectangle: ";
  std::cin >> breadth;

  int area = length * breadth;
  int perimeter = 2 * (length + breadth);

  if (area > perimeter) {
    std::cout << "Area of the rectangle is greater than its perimeter." << std::endl;
  } else {
    std::cout << "Area of the rectangle is not greater than its perimeter." << std::endl;
  }

  return 0;

}
