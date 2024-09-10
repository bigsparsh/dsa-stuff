#include <iostream>

int makeSum (int *, int, int, int);

int main () {
  int size;
  std::cout << "\nEnter the size of the array: ";
  std::cin >> size;
  std::cout << "\nEnter the array: \n";
  int *arr = new int[size];

  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }
  int max;
  for (int i = 0; i < size; i++) {
    int  temp  = makeSum(arr, i, 1, size);
    if(i == 0) {
      max = temp;
      continue;
    }
    if (temp > max) max = temp;
  }
  std::cout << "The maximum sum is: " << max << std::endl;
}

int makeSum (int *arr, int strt, int cont, int size) {
  if (cont + strt > size) return 0;
  int sum = 0, i = 0;
  for (i = strt; i < strt + cont; i++) sum += *(arr + i); 
  return sum + makeSum(arr, i, cont + 1, size);
}
