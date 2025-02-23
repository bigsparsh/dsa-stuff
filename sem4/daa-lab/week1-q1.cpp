// I. Given an array of nonnegative integers, design a linear algorithm and
// implement it using a program to find whether given key element is present in
// the array or not. Also, find total number of comparisons for each input case.
// (Time Complexity = O(n), where n is the size of input)

#include <iostream>
#include <vector>
using namespace std;

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

    int key, comparisons = 0;
    cin >> key;

    bool found = false;
    for (int j = 0; j < size; j++) {
      comparisons++;
      if (list[j] == key) {
        found = true;
        break;
      }
    }

    if (found) {
      cout << "Present " << comparisons << endl;
    } else {
      cout << "Not Present " << comparisons << endl;
    }
  }
}
