// 8. A library charges a fine for every book returned late. For first 5 days the fine is 50 paise, for 6-10 days fine is one rupee and above 10 days fine is 5 rupees. If you return the book after 30 days your membership will be cancelled. Write a program to accept the number of days the member is late to return the book and display the fine or the appropriate message.

#include <iostream>
int main () {
  
  int days;
  std::cout << "Enter the number of days the member is late to return the book: ";
  std::cin >> days;

  if (days <= 5) {
    std::cout << "Fine is 50 paise." << std::endl;
  } else if (days <= 10) {
    std::cout << "Fine is 1 rupee." << std::endl;
  } else if (days <= 30) {
    std::cout << "Fine is 5 rupees." << std::endl;
  } else {
    std::cout << "Membership will be cancelled." << std::endl;
  }

  return 0;

}
