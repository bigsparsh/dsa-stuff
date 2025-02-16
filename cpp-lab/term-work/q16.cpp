/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// Exercise 16: Merge and Sort Two Arrays Using Vectors
// Problem Statement:
// Write a C++ program that:
// 1. Accepts two integer arrays from the user and stores them in two separate std::vector objects.
// 2. Merges these vectors into a single vector.
// 3. Sorts the merged vector in ascending order using iterators.
// 4. Displays the sorted vector elements using a loop with iterators.
// Requirements:
// • Use std::vector for storing arrays and std::sort for sorting.
// • Ensure input validation for empty arrays.
// Example:
// • Input: Array1 = {5, 3, 8}, Array2 = {7, 2, 4}
// • Output: Merged and Sorted Vector = {2, 3, 4, 5, 7, 8}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<int> vec1, vec2, vec3;
  int n1, n2, num;

  cout << "Enter the number of elements in the first array: ";
  cin >> n1;

  if (n1 <= 0) {
    cout << "Array size must be greater than 0" << endl;
    return 1;
  }

  cout << "Enter elements of the first array: ";
  for (int i = 0; i < n1; i++) {
    cin >> num;
    vec1.push_back(num);
  }

  cout << "Enter the number of elements in the second array: ";
  cin >> n2;

  if (n2 <= 0) {
    cout << "Array size must be greater than 0" << endl;
    return 1;
  }

  cout << "Enter elements of the second array: ";
  for (int i = 0; i < n2; i++) {
    cin >> num;
    vec2.push_back(num);
  }

  vec3.insert(vec3.end(), vec1.begin(), vec1.end());
  vec3.insert(vec3.end(), vec2.begin(), vec2.end());

  sort(vec3.begin(), vec3.end());

  cout << "Merged and Sorted Vector = {";
  for (vector<int>::iterator it = vec3.begin(); it != vec3.end(); it++) {
    cout << *it;
    if (it != vec3.end() - 1) {
      cout << ", ";
    }
  }
  cout << "}" << endl;

  return 0;
}
