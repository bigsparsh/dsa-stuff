// Write a C program to sort N names given by user in an array, using Quick sort technique. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quickSort(char **, int, int);
int partition(char **, int, int);

int main() {
  int n;
  printf("Enter number of names: ");
  scanf("%d", &n);

  char **names = (char **)malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++) {
    names[i] = (char *)malloc(100 * sizeof(char));
    printf("Enter name %d: ", i + 1);
    scanf("%s", names[i]);
  }

  quickSort(names, 0, n - 1);

  printf("Sorted names:\n");
  for (int i = 0; i < n; i++) {
    printf("%s\n", names[i]);
  }

  return 0;
}

void quickSort(char **names, int low, int high) {
  if (low < high) {
    int pi = partition(names, low, high);

    quickSort(names, low, pi - 1);
    quickSort(names, pi + 1, high);
  }
}

int partition(char **names, int low, int high) {
  char *pivot = names[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (strcmp(names[j], pivot) < 0) {
      i++;
      char *temp = names[i];
      names[i] = names[j];
      names[j] = temp;
    }
  }

  char *temp = names[i + 1];
  names[i + 1] = names[high];
  names[high] = temp;

  return i + 1;
}

