// 11. Any character is entered through the keyboard, write a program to determine whether the character entered is a capital letter, a small case letter, a digit or a special symbol. The following table shows the range of ASCII values for various characters.
//
// Characters ASCII Values
// A-Z 65-90
// a-z 97-122
// 0-9 48-55
// special symbol 0-47, 58-64, 91-96, 123-127

#include <iostream>
int main () {

  char ch;
  std::cout << "Enter a character: ";
  std::cin >> ch;

  if (ch >= 65 && ch <= 90) {
    std::cout << "Capital letter" << std::endl;
  } else if (ch >= 97 && ch <= 122) {
    std::cout << "Small case letter" << std::endl;
  } else if (ch >= 48 && ch <= 57) {
    std::cout << "Digit" << std::endl;
  } else {
    std::cout << "Special symbol" << std::endl;
  }

  return 0;

}
