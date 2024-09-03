#include <stdio.h>
#include <stdlib.h>

int main () {

  int nos;
  scanf("%d", &nos);
  char **statements = (char **) malloc(nos * sizeof(char *));
  for (int i=0; i<nos; i++) {
    *(statements+i) = (char *) malloc(3 * sizeof(char *));
    scanf("%s", statements + i);
  }
  for (int i=0; i<nos; i++) {
    int operator = -1;
    for (int j=0; j<2; j++) {
      if (*(*(statements + i) + j) == '+') {
        if(operator == -1) {
          operator = 1;
        }
      }
      else if(*(*(statements + i) + j) == '-') {
        if(operator == -1) {
          operator = 2;
        }
      }
    }
    printf("%d\n", operator);
  }

  return 0;
}
