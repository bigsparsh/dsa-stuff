/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// Exercise 19: Element Frequency Counter
// Problem Statement:
// Write a C++ program that:
// 1. Accepts an array of integers from the user and stores it in a std::vector
// 2. Counts the frequency of each element in the vector.
// 3. Displays each unique element along with its frequency using iterators.
// Requirements:
// • Use a std::map or std::unordered_map to store element frequencies.
// • Use std::vector and iterators for input and traversal.
// Example:
// • Input: Array = {1, 2, 2, 3, 1, 4, 3}
// • Output:
// • 1: 2
// • 2: 2
// • 3: 2
// • 4: 1 

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
  vector<int> vec;
  map<int, int> freq;
  int n, num;

  cout << "Enter the number of elements in the array: ";
  cin >> n;

  if (n <= 0) {
    cout << "Array size must be greater than 0" << endl;
    return 1;
  }

  cout << "Enter elements of the array: ";
  for (int i = 0; i < n; i++) {
    cin >> num;
    vec.push_back(num);
  }

  for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
    freq[*it]++;
  }

  cout << "Element Frequencies:" << endl;
  for (map<int, int>::iterator it = freq.begin(); it != freq.end(); it++) {
    cout << it->first << ": " << it->second << endl;
  }

  return 0;
}
