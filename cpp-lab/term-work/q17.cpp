/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// Exercise 17: Array Rotation Using Vectors
// Problem Statement:
// Write a C++ program to rotate the elements of an array stored in a std::vector.
// 1. Accept an integer array from the user and store it in a vector.
// 2. Accept the number of positions to rotate the array.
// 3. Rotate the vector elements to the left by the specified positions.
// 4. Display the rotated vector using iterators.
// Requirements:
// • Use std::vector for the array and iterators for traversal.
// • Validate inputs to ensure the number of rotations does not exceed the array size.
// Example:
// • Input: Array = {1, 2, 3, 4, 5}, Positions = 2
// • Output: Rotated Vector = {3, 4, 5, 1, 2}

#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> vec;
  int n, num, pos;

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

  cout << "Enter the number of positions to rotate the array: ";
  cin >> pos;

  if (pos < 0 || pos >= n) {
    cout << "Invalid number of positions" << endl;
    return 1;
  }

  vector<int> rotatedVec;
  rotatedVec.insert(rotatedVec.end(), vec.begin() + pos, vec.end());
  rotatedVec.insert(rotatedVec.end(), vec.begin(), vec.begin() + pos);

  cout << "Rotated Vector = {";
  for (vector<int>::iterator it = rotatedVec.begin(); it != rotatedVec.end(); it++) {
    cout << *it;
    if (it != rotatedVec.end() - 1) {
      cout << ", ";
    }
  }
  cout << "}" << endl;

  return 0;
}
