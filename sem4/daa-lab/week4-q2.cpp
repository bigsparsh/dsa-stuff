// Implement quick sort and count the comparisons and swapsc with out using swap
// function.

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high, int &comp, int &swap) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      swap++;
    }
    comp++;
  }

  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;
  swap++;

  return i + 1;
}

void quickSort(int arr[], int low, int high, int &comp, int &swap) {
  if (low < high) {
    int pi = partition(arr, low, high, comp, swap);

    quickSort(arr, low, pi - 1, comp, swap);
    quickSort(arr, pi + 1, high, comp, swap);
  }
}

int main() {
  int tc, size;

  cin >> tc;

  for (int x = 0; x < tc; x++) {
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++)
      cin >> arr[i];

    int comp = 0, swap = 0;

    quickSort(arr, 0, size - 1, comp, swap);

    for (int i = 0; i < size; i++)
      cout << arr[i] << " ";
    cout << endl;

    cout << "Comparisons: " << comp << endl;
    cout << "Swaps: " << swap << endl;
  }

  return 0;
}
