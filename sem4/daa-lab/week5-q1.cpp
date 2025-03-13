// Given an unsorted array of alphabets containing duplicate elements. Design an
// algorithm and implement it using a program to find which alphabet has maximum
// number of occurrences andprint it. (Time Complexity = O(n)) (Hint: Use
// counting sort) Input Format: The first line contains number of test cases, T.
// For each test case, there will be two input lines. First line contains n (the
// size of array). Second line contains space-separated integers describing
// array. Output: The output will have T number of lines. For each test case,
// output will be the array element which has maximum occurrences and its total
// number of occurrences. If no duplicates are present (i.e. all the elements
// occur only once), output should be “No Duplicates Present”.

#include <iostream>
using namespace std;

void countingSort(char arr[], int n) {
  int count[26] = {0};
  for (int i = 0; i < n; i++) {
    count[arr[i] - 'a']++;
  }
  int max = 0;
  char result;
  for (int i = 0; i < 26; i++) {
    if (count[i] > max) {
      max = count[i];
      result = i + 'a';
    }
  }
  if (max == 1) {
    cout << "No Duplicates Present" << endl;
  } else {
    cout << result << " - " << max << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    countingSort(arr, n);
  }
  return 0;
}
