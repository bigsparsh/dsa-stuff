#include <iostream>
#include <math.h>

int main () {
  int size1, size2;
  std::cout << "\nEnter the size of both arrays: ";
  std::cin >> size1 >> size2;
  
  int *arr1 = new int[size1];
  int *arr2 = new int[size2];

  std::cout << "\nEnter the elements in the first array: \n";
  for (int i=0; i<size1 ; i++ ){ 
    std::cin >> *(arr1 + i);
  }

  std::cout << "\nEnter the elements in the second array: \n";
  for (int i=0; i<size2 ; i++ ){ 
    std::cin >> *(arr2 + i);
  }

  int max = 0;
  for (int i=0; i<size1 ; i++) {
    int temp_max = 0;
    int temp1 = *(arr1 + i), size_temp1= 0;
    while (temp1 != 0) {
      size_temp1++;
      temp1/=10;
    }
    temp1 = *(arr1 + i);
    std::cout << "\nSize ARR1 of " << *(arr1+i) << " is " << size_temp1 << "\n";
    for (int j=0; j<size2; j++) {
      int temp2 = *(arr2 + j), size_temp2= 0;
      while (temp2 != 0) {
        size_temp2++;
        temp2/=10;
      }
      temp2 = *(arr2 + j);
      std::cout << "\nSize ARR2 of " << *(arr2+j) << " is " << size_temp2 << "\n";
      int m1 = pow(10, size_temp1-1), m2 = pow(10, size_temp2-1);
      
      std::cout << "\nM1: " << m1 << " M2: " << m2 << "\n";
      int ts1 = size_temp1, ts2 = size_temp2;
      while (m1!=0 && m2!=0 && size_temp1!=0 && size_temp2 != 0) {
        std::cout << "\nTEMP1 / m1 is " << temp1/m1 << " and TEMP2 / m2 is " << temp2/m2 << "\n";
          if(temp1/m1 == temp2/m2) temp_max++;
          m1/=10;
          m2/=10;
          size_temp1--;
          size_temp2--;
      }
      size_temp1 = ts1;
      size_temp2 = ts2;
      // for (int k=pow(10, size_temp1-1); k!=0; k/=10) {
      //   for (int l=pow(10, size_temp2-1); l!=0; l/=10) {
      //     if(temp1/k == temp2/l) temp_max++;
      //   } 
      // }
      std::cout << "\nTEMP max for " << *(arr1 + i) << " and " << *(arr2 + j) << " are " << temp_max << "\n";
      if(temp_max > max) max = temp_max;
      temp_max = 0;
    }

  }

  std::cout << "\n\nAnswer: "<< max << "\n\n";
}
