/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// Exercise 21: Removing Duplicates from a List
// Problem Statement:
// Write a C++ program that:
// 1. Accepts a list of integers from the user.
// 2. Removes any duplicate values from the list.
// 3. Displays the updated list using iterators.
// Requirements:
// • Use std::list for storing the integers.
// • Use the unique() function to remove consecutive duplicate elements.
// • Ensure the list is sorted before removing duplicates.
// Example:
// • Input: List = {1, 2, 2, 3, 3, 3, 4}
// • Output: List after Removing Duplicates = {1, 2, 3, 4}

#include <iostream>
#include <list>
using namespace std;

int main() {
  list<int> list;
  int n, num;

  cout << "Enter the number of elements in the list: ";
  cin >> n;

  if (n <= 0) {
    cout << "List size must be greater than 0" << endl;
    return 1;
  }

  cout << "Enter elements of the list: ";
  for (int i = 0; i < n; i++) {
    cin >> num;
    list.push_back(num);
  }

  list.sort();
  list.unique();

  cout << "List after Removing Duplicates = {";
  for (std::list<int>::iterator it = list.begin(); it != list.end(); it++) {
    cout << *it;
    if (it != --list.end()) {
      cout << ", ";
    }
  }
  cout << "}" << endl;

  return 0;
}
