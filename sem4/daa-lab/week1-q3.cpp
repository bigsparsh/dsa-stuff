// Given an already sorted array of positive integers, design an algorithm and
// implement it using a program to find whether a given key element is present
// in the sorted array or not. For an array arr[n], search at the indexes
// arr[0], arr[2], arr[4],.....,arr[2k ] and so on. Once the interval (arr[2k ]
// < key < arr[ 2k+1] ) is found, perform a linear search operation from the
// index 2k
//  to find the element
// key. (Complexity < O(n), where n is the number of elements need to be scanned
// for searching): Jump Search

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int jump_search(vector<int> list, int key) {
  int comparisons = 0;
  int n = list.size();
  int jump = sqrt(n);
  int left = 0;
  int right = jump;
  while (right < n && list[right] <= key) {
    comparisons++;
    left = right;
    right += jump;
    if (right > n - 1)
      right = n;
  }
  for (int i = left; i < right; i++) {
    comparisons++;
    if (list[i] == key) {
      cout << "Present ";
      return comparisons;
    }
  }
  cout << "Not Present ";
  return comparisons;
}

int main() {
  vector<int> list;
  int test_cases, size;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++) {
    cin >> size;
    list.resize(size);
    for (int j = 0; j < size; j++) {
      cin >> list[j];
    }

    int key;
    cin >> key;

    cout << jump_search(list, key) << endl;
  }
}
