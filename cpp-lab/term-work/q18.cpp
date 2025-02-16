/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// Exercise 18: String Length Filter
// Problem Statement:
// Write a C++ program that:
// 1. Accepts a list of strings from the user and stores them in a std::vector.
// 2. Filters strings with a length greater than a specified value.
// 3. Displays the filtered strings using iterators.
// Requirements:
// • Use std::vector for dynamic string storage.
// • Validate input to ensure the list is not empty.
// Example:
// • Input: Strings = {"apple", "cat", "elephant", "dog"}, Length = 3
// • Output: Filtered Strings = {"apple", "elephant"}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  vector<string> vec;
  string str;
  int n, len;

  cout << "Enter the number of strings: ";
  cin >> n;

  if (n <= 0) {
    cout << "List must contain at least one string" << endl;
    return 1;
  }

  cout << "Enter the strings: ";
  for (int i = 0; i < n; i++) {
    cin >> str;
    vec.push_back(str);
  }

  cout << "Enter the length filter: ";
  cin >> len;

  cout << "Filtered Strings = {";
  for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
    if ((*it).length() > len) {
      cout << *it;
      if (it != vec.end() - 1) {
        cout << ", ";
      }
    }
  }
  cout << "}" << endl;

  return 0;
}
