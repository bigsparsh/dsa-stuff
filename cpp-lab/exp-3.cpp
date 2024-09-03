#include <iostream>

int main () {
  std::string str1;
  std::string str2;

  std::cout << "Enter a string: ";
  std::cin >> str1;

  std::cout << "The non-repeating elements are \n" ;

  for (int i =0; i < str1.length(); i++) {
    bool same = false;
    for (int j = 0; j < str1.length(); j++) {
      if (i != j && str1[i] == str1[j]) {
        same = true;
        break;
      }
    }
    if (!same) {
      std::cout << str1[i] << " ";
    }
  }

}
