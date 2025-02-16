/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// Exercise 20: Merging Two Lists
// Problem Statement:
// Write a C++ program that:
// 1. Accepts two lists of integers from the user.
// 2. Merges the two lists into a single list.
// 3. Sorts the merged list in ascending order.
// 4. Displays the merged and sorted list using iterators.
// Requirements:
// • Use std::list for storing the integers.
// • Utilize iterators to traverse and display the list.
// Example:
// • Input: List1 = {3, 1, 4}, List2 = {2, 5}
// • Output: Merged and Sorted List = {1, 2, 3, 4, 5}

#include <iostream>
#include <list>
using namespace std;

int main() {
  list<int> list1, list2, mergedList;
  int n1, n2, num;

  cout << "Enter the number of elements in the first list: ";
  cin >> n1;

  if (n1 <= 0) {
    cout << "List size must be greater than 0" << endl;
    return 1;
  }

  cout << "Enter elements of the first list: ";
  for (int i = 0; i < n1; i++) {
    cin >> num;
    list1.push_back(num);
  }

  cout << "Enter the number of elements in the second list: ";
  cin >> n2;

  if (n2 <= 0) {
    cout << "List size must be greater than 0" << endl;
    return 1;
  }

  cout << "Enter elements of the second list: ";
  for (int i = 0; i < n2; i++) {
    cin >> num;
    list2.push_back(num);
  }

  mergedList.merge(list1);
  mergedList.merge(list2);

  mergedList.sort();

  cout << "Merged and Sorted List = {";
  for (list<int>::iterator it = mergedList.begin(); it != mergedList.end(); it++) {
    cout << *it;
    if (it != --mergedList.end()) {
      cout << ", ";
    }
  }
  cout << "}" << endl;

  return 0;
}
