#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    int j = i - 1, tmp = arr[i];
    while (arr[j] > tmp && j >= 0) {
      arr[j] = arr[--j];
    }
    if (j == -1)
      arr[0] = tmp;
    else
      arr[j] = tmp;

    cout << j;
    cout << endl;
    for (int x = 0; x < size; x++)
      cout << "[" << arr[x] << "] ";
    cout << endl;
  }
}

int main() {
  int arr[] = {19, 13, 59, 29, 11, 832, 29, 0, 21, 5};
  int size = (sizeof(arr) / sizeof(int)) - 1;
  insertionSort(arr, size);

  for (int i = 0; i < size; i++)
    cout << "[" << arr[i] << "] ";

  return 0;
}
