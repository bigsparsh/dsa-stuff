#include <iostream>
using namespace std;

int partition(int arr[], int l, int h) {
  int i = l - 1;
  int pivot = h;
  for (int j = l; j <= h; j++)
    if (arr[j] < arr[pivot])
      swap(arr[++i], arr[j]);
  swap(arr[i + 1], arr[pivot]);
  return i + 1;
}

void quickSort(int arr[], int l, int h) {
  if (l > h)
    return;
  int pi = partition(arr, l, h);
  quickSort(arr, l, pi - 1);
  quickSort(arr, pi + 1, h);
}

int main() {
  int arr[] = {19, 13, 59, 29, 11, 832, 29, 0, 21, 5};
  quickSort(arr, 0, (sizeof(arr) / sizeof(int)) - 1);

  for (int i = 0; i < 10; i++)
    cout << "[" << arr[i] << "] ";

  return 0;
}
