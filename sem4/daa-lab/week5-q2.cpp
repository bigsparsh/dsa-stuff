// Given an unsorted array of integers, design an algorithm and implement it
// using a program to find whether two elements exist such that their sum is
// equal to the given key element. (Time Complexity = O(n log n)) Input Format:
// The first line contains number of
// test cases, T. For each test case,
// there will be two input lines. First
// line contains n (the size of array).
// Second line contains space-separated integers
// describing array. Third line contains key
// Output Format:
// The output will have T number of lines.
// For each test case, output will be the elements arr[i] and arr[j] such that
// arr[i]+arr[j] = key if exist otherwise print 'No Such Elements Exist”.

#include <algorithm>
#include <iostream>
using namespace std;

void findSum(int arr[], int n, int key) {
  sort(arr, arr + n);
  int i = 0, j = n - 1;
  while (i < j) {
    if (arr[i] + arr[j] == key) {
      cout << arr[i] << " " << arr[j] << endl;
      return;
    } else if (arr[i] + arr[j] < key) {
      i++;
    } else {
      j--;
    }
  }
  cout << "No Such Elements Exist" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int key;
    cin >> key;
    findSum(arr, n, key);
  }
  return 0;
}
