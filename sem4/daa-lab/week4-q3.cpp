#include <iostream>

using namespace std;

int partition(int arr[], int low, int high) {
  int pivotIndex = low + rand() % (high - low + 1);
  int pivot = arr[pivotIndex];

  int temp;
  temp = arr[pivotIndex];
  arr[pivotIndex] = arr[high];
  arr[high] = temp;

  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;

  return i + 1;
}

int quickSelect(int arr[], int low, int high, int k) {
  if (low <= high) {
    int pivotPos = partition(arr, low, high);
    if (pivotPos == k) {
      return arr[pivotPos];
    } else if (pivotPos > k) {
      return quickSelect(arr, low, pivotPos - 1, k);
    } else {
      return quickSelect(arr, pivotPos + 1, high, k);
    }
  }
  return -1;
}

int main() {
  int n, k;
  char choice;
  cout << "Enter size of array: ";
  cin >> n;
  int *arr = new int[n];
  cout << "Enter array elements: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << "Enter k (1 to " << n << "): ";
  cin >> k;
  cout << "Find k-th smallest (s) or largest (l)? ";
  cin >> choice;

  int result;

  if (choice == 's') {
    result = quickSelect(arr, 0, n - 1, k - 1);
  } else {
    result = quickSelect(arr, 0, n - 1, n - k);
  }

  cout << k << "-th element: " << result << endl;

  delete[] arr;
  return 0;
}
