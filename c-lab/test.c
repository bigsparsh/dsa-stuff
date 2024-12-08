#include <stdio.h>
#include <stdlib.h>

int main (){
  int *x = (int*) malloc(sizeof(int));
  x[0] = 10;

  for (int i = 0; i < sizeof(x); i++) {
    printf(" %d ", x[i]);
  }

  return 0;
}
