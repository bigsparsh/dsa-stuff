#include <iostream>

int main() {
  std::string str1;
  std::string str2;
  char rem;

  std::cout << "Enter a string: ";
  std::cin >> str1;

  std::cout << "Enter a character to remove: ";
  std::cin >> rem;

  for (char c : str1) {
    if (c != rem) {
      str2 += c;
    }
  }

  std::cout << "The new string is: " << str2 << std::endl;
}
