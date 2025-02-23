// Given an already sorted array of positive integers, design an algorithm and
// implement it using a program to find whether given key element is present in
// the array or not. Also, find total number of comparisons for each input case.
// (Time Complexity = O(nlogn), where n is the size of input)

#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> list, int key) {
  int comparisons = 0;
  int left = 0;
  int right = list.size() - 1;
  while (left <= right) {
    comparisons++;
    int mid = left + right / 2;
    if (list[mid] == key) {
      cout << "Present ";
      return comparisons;
    } else if (list[mid] < key)
      left = mid + 1;
    else
      right = mid - 1;
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

    cout << binary_search(list, key) << endl;
  }
}
