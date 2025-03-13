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
// use heap sort

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < n && arr[l] > arr[largest])
    largest = l;

  if (r < n && arr[r] > arr[largest])
    largest = r;

  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }

  for (int i = n - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

void findPair(int arr[], int n, int key) {
  heapSort(arr, n);

  int low = 0;
  int high = n - 1;

  while (low < high) {
    if (arr[low] + arr[high] == key) {
      cout << arr[low] << " " << arr[high] << endl;
      return;
    } else if (arr[low] + arr[high] < key) {
      low++;
    } else {
      high--;
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

    findPair(arr, n, key);
  }

  return 0;
}
