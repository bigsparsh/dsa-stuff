// 1. If cost price and selling price of an item is input through the keyboard, write a program in C++ to determine whether the seller has made profit or incurred loss. Also determine how much profit he made or loss he incurred.

#include <iostream>

int main () {
  int cp, sp;
  std::cout << "Enter cost price: ";
  std::cin >> cp;
  std::cout << "Enter selling price: ";
  std::cin >> sp;

  if (cp < sp) {
    std::cout << "Seller made profit of " << sp - cp << std::endl;
  } else if (cp > sp) {
    std::cout << "Seller incurred loss of " << cp - sp << std::endl;
  } else {
    std::cout << "No profit, no loss" << std::endl;
  }

  return 0;
}
