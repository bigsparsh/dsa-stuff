// Given a sorted array of positive integers, design an algorithm and implement
// it using a program to find three indices i, j, k such that arr[i] + arr[j] =
// arr[k]. Input format: The first line contains number of test cases, T. For
// each test case, there will be two input lines. First line contains n (the
// size of array). Second line contains space-separated integers describing
// array. Output: The output will have T number of lines. For each test case T,
// print the value of i, j and k, if found else print “No sequence found”.
// Sample I/O Problem II:
// Input:
// 3
// 5
// 1 5 84 209 341
// 10
// 24 28 48 71 86 89 92 120 194 201
// 15
// 64 69 82 95 99 107 113 141 171 350 369 400 511 590 666
// Output:
// No sequence found.
// 2, 7, 8
// 1, 6, 9

#include <iostream>
#include <vector>
using namespace std;
#define Max 100
int main() {
  vector<int> arr;
  int m;
  cin >> m;
  for (int j = 0; j < m; j++) {
    int n;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    for (int i = n - 1; i > 0; i--) {
      int j = 0;
      int k = i - 1;
      while (j < k) {
        if ((arr[j] + arr[k]) == arr[i]) {
          cout << j << " + " << k << " = " << i << endl;
          j++;
          k--;
        } else if ((arr[j] + arr[k]) > arr[i]) {
          k--;
        } else {
          j++;
        }
      }
    }
  }
  return 0;
}
