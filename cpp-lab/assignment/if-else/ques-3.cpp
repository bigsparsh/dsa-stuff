// 3. Any year is input through the keyboard. Write a program in C++ to determine whether the year is a leap year or not.

#include <iostream>

int main () {
  int year;
  std::cout << "Enter a year: ";
  std::cin >> year;

  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        std::cout << year << " is a leap year." << std::endl;
      } else {
        std::cout << year << " is not a leap year." << std::endl;
      }
    } else {
      std::cout << year << " is a leap year." << std::endl;
    }
  } else {
    std::cout << year << " is not a leap year." << std::endl;
  }

  return 0;

}
