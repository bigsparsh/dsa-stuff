// 9. Any year is entered through the keyboard, write a program to determine whether the year is leap or not. Use the logical operators && and ||.

#include <iostream>
int main () {

  int year;
  std::cout << "Enter the year: ";
  std::cin >> year;

  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    std::cout << "Leap year." << std::endl;
  } else {
    std::cout << "Not a leap year." << std::endl;
  }

  return 0;

}
