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
  int step = sqrt(n);
  int prev = 0;

  while (list[min(step, n) - 1] < key) {
    comparisons++;
    prev = step;
    step += sqrt(n);
    if (prev >= n) {
      cout << "Not Present ";
      return comparisons;
    }
  }

  while (list[prev] < key) {
    comparisons++;
    prev++;
    if (prev == min(step, n)) {
      cout << "Not Present ";
      return comparisons;
    }
  }

  if (list[prev] == key) {
    cout << "Present ";
    return comparisons;
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
