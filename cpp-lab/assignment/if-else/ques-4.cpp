// 4. If the ages of Ramesh, Suresh, and Dinesh are input through the keyboard, write a program in C++ to determine the youngest of the three.

#include <iostream>
int main (){ 
  int ramesh, suresh, dinesh;
  std::cout << "Enter the age of Ramesh: ";
  std::cin >> ramesh;
  std::cout << "Enter the age of Suresh: ";
  std::cin >> suresh;
  std::cout << "Enter the age of Dinesh: ";
  std::cin >> dinesh;

  if (ramesh < suresh && ramesh < dinesh){
    std::cout << "Ramesh is the youngest." << std::endl;
  } else if (suresh < ramesh && suresh < dinesh){
    std::cout << "Suresh is the youngest." << std::endl;
  } else {
    std::cout << "Dinesh is the youngest." << std::endl;
  }
  return 0;
}
