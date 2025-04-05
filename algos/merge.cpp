#include <iostream>
using namespace std;
void merge(int arr[], int l, int m, int r) {
  int n1 = m - l + 1, n2 = r - m, L[n1], R[n2];
  for (int i = 0; i < n1; i++)
    L[i] = arr[i + l];
  for (int i = 0; i < n2; i++)
    R[i] = arr[i + m + 1];
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }
  while (i < n1)
    arr[k++] = L[i++];
  while (j < n2)
    arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
  if (l >= r)
    return;
  int m = l + (r - l) / 2;
  mergeSort(arr, l, m);
  mergeSort(arr, m + 1, r);
  merge(arr, l, m, r);
}

int main() {
  int arr[] = {19, 13, 59, 29, 11, 832, 29, 0, 21, 5};
  mergeSort(arr, 0, (sizeof(arr) / sizeof(int)) - 1);

  for (int i = 0; i < 10; i++)
    cout << "[" << arr[i] << "] ";

  return 0;
}
