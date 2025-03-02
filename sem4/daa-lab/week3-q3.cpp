#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];

  for (int i = 0; i < n2; i++)
    R[i] = arr[m + 1 + i];

  int i = 0, j = 0, k = l;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
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
  int tc, size;

  cin >> tc;

  for (int i = 0; i < tc; i++) {
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++)
      cin >> arr[i];

    mergeSort(arr, 0, size - 1);

    bool hasDuplicates = false;

    for (int i = 0; i < size - 1; i++) {
      if (arr[i] == arr[i + 1]) {
        hasDuplicates = true;
        break;
      }
    }

    if (hasDuplicates)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}
