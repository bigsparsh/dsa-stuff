// Given a sorted array of positive integers containing few duplicate elements,
// design an algorithm and implement it using a program to find whether the
// given key element is present in the array or not. If present, then also find
// the number of copies of given key. (Time Complexity = O(log n))
// In this we will find the last occurence and first occurence of the number and
// then subtract the two to get the number of copies of the number.

#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> list, int key, bool search_first) {
  int comparisons = 0;
  int left = 0;
  int right = list.size() - 1;
  int result = -1;
  while (left <= right) {
    comparisons++;
    int mid = left + (right - left) / 2;
    if (list[mid] == key) {
      result = mid;
      if (search_first)
        right = mid - 1;
      else
        left = mid + 1;
    } else if (list[mid] < key)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return result;
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

    int first = binary_search(list, key, true);
    int last = binary_search(list, key, false);

    if (first != -1) {
      cout << key << " - " << last - first + 1 << endl;
    } else {
      cout << "Key not present" << endl;
    }
  }
}
