// 5. Using conditional operators determine: (1) Whether the character entered through the keyboard is a lower-case alphabet or not. (2) Whether a character entered through the keyboard is a special symbol or not.

#include <iostream>

int main (){
  char c;
  std::cout << "Enter a character: ";
  std::cin >> c;

  if (c >= 'a' && c <= 'z'){
    std::cout << "The character is a lower-case alphabet." << std::endl;
  } else {
    std::cout << "The character is not a lower-case alphabet." << std::endl;
  }

  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
    std::cout << "The character is not a special symbol." << std::endl;
  } else {
    std::cout << "The character is a special symbol." << std::endl;
  }

  return 0;
}
