#include <iostream>
int main () {
  int size, asc_swap = 0, desc_swap = 0, temp = 0;
  std::cin >> size;
  int arr[size], newArr[size];

  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
    newArr[i] = arr[i];
  }

  for (int i = 0; i < size; i++ ) {
    for (int j = 0; j < size - i; j++ ) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
        asc_swap++;
      }
    }
  }
  if (size/2 > asc_swap) {
    if (desc_swap < asc_swap) 
    std::cout << desc_swap;
    else
    std::cout << asc_swap;
    return 0;
  }

  for (int i = 0; i < size; i++ ) {
    for (int j = i; j < size; j++ ) {
      if (newArr[j] < newArr[j+1]) {
        temp = newArr[j+1];
        newArr[j+1] = newArr[j];
        newArr[j] = temp;
        desc_swap++;
      }
    }
  }

  if (desc_swap < asc_swap) 
  std::cout << desc_swap;
  else
  std::cout << asc_swap;
  return 0;

}
