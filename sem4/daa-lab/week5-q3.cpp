// You have been given two sorted integer arrays of size m and n. Design an
// algorithm and implement it using a program to find list of elements which are
// common to both. (Time Complexity = O(m+n)) Input Format: First line contains
// m (the size of first array). Second line contains m space-separated integers
// describing first array. Third line contains n (the size of second array).
// Fourth line contains n space-separated integers describing second array.
// Output Format:
// Output will be the list of elements which are common to both

#include <iostream>
using namespace std;

void findCommon(int arr1[], int m, int arr2[], int n) {
  int i = 0, j = 0;
  while (i < m && j < n) {
    if (arr1[i] == arr2[j]) {
      cout << arr1[i] << " ";
      i++;
      j++;
    } else if (arr1[i] < arr2[j]) {
      i++;
    } else {
      j++;
    }
  }
  cout << endl;
}

int main() {
  int m;
  cin >> m;
  int arr1[m];
  for (int i = 0; i < m; i++) {
    cin >> arr1[i];
  }
  int n;
  cin >> n;
  int arr2[n];
  for (int i = 0; i < n; i++) {
    cin >> arr2[i];
  }
  findCommon(arr1, m, arr2, n);
  return 0;
}
