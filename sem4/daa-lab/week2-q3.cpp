// Given an array of nonnegative integers, design an algorithm and a program to
// count the number of pairs of integers such that their difference is equal to
// a given key, K. Input format: The first line contains number of test cases,
// T. For each test case, there will be three input lines. First line contains n
// (the size of array). Second line contains space-separated integers describing
// array. Third line contains the key element. Output format: The output will
// have T number of lines. For each test case T, output will be the total count
// i.e. number of times such pair exists.

#include <iostream>
using namespace std;

int main() {

  int tc, size, key;
  cin >> tc;

  for (int x = 0; x < tc; x++) {
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
      cin >> arr[i];

    cin >> key;

    int temp;
    for (int i = 0; i < size - 1; i++) {
      for (int j = 0; j < size - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }

    int count = 0;
    int i = 0, j = i + 1;
    while (j < size) {
      if (arr[j] - arr[i] == key) {
        count++, i++, j++;
      } else if (arr[j] - arr[i] > key)
        i++;
      else
        j++;
    }

    if (count == 0)
      cout << "No such pair found" << endl;
    else
      cout << count << endl;
  }
}
