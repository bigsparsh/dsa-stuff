#include <iostream>
using namespace std;

int main() {

  int size, tc;
  cin >> tc;

  for (int i = 0; i < tc; i++) {
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++)
      cin >> arr[i];

    int comparisons = 0, swaps = 0;

    for (int i = 0; i < size - 1; i++) {
      int minIndex = i;
      for (int j = i + 1; j < size; j++) {
        comparisons++;
        if (arr[j] < arr[minIndex])
          minIndex = j;
      }

      if (minIndex != i) {
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        swaps++;
      }
    }

    for (int i = 0; i < size; i++)
      cout << arr[i] << " ";

    cout << "\n" << comparisons << "\n" << swaps << endl;
  }

  return 0;
}
