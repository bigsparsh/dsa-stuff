// Implement merge sort and count comparisons and inversions.

#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right, int &comp, int &inver) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int L[n1], R[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = left;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
      inver += n1 - i;
    }
    k++;
    comp++;
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

void mergeSort(int arr[], int left, int right, int &comp, int &inver) {
  if (left < right) {
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid, comp, inver);
    mergeSort(arr, mid + 1, right, comp, inver);
    merge(arr, left, mid, right, comp, inver);
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

    int comp = 0, inver = 0;
    mergeSort(arr, 0, size - 1, comp, inver);

    for (int i = 0; i < size; i++)
      cout << arr[i] << " ";

    cout << endl;

    cout << "Comparisons = " << comp << endl;
    cout << "Inversions = " << inver << endl;
  }

  return 0;
}
