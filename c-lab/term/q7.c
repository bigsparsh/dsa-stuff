/*
 Name: Sparsh Singh
 University Roll No: 2024329
 Section: C
  
  Q7- Write a C program to sort N names given by user in an array, using Quick sort technique. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void quickSort(char **, int, int);
int partition(char **, int, int);

int main() {
  int n;
  printf("Enter number of names: ");
  scanf("%d", &n);

  // Allocate memory for names
  char **names = (char **)malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++) {
    names[i] = (char *)malloc(100 * sizeof(char));
    printf("Enter name %d: ", i + 1);
    scanf("%s", names[i]);
  }

  // Sort the names using quick sort
  quickSort(names, 0, n - 1);

  // Display the sorted names
  printf("Sorted names:\n");
  for (int i = 0; i < n; i++) {
    printf("%s\n", names[i]);
  }

  return 0;
}

// Sort the names using quick sort
void quickSort(char **names, int low, int high) {
  // If there are more than one elements in the array then sort it
  if (low < high) {
    int pi = partition(names, low, high);

    // Recursively sort the elements before and after partition index
    quickSort(names, low, pi - 1);
    quickSort(names, pi + 1, high);
  }
}

// Partition the array
int partition(char **names, int low, int high) {
  char *pivot = names[high];
  int i = low - 1;

  // Compare all the elements with pivot and place the elements less than pivot on left side and greater than pivot on right side
  for (int j = low; j < high; j++) {
    if (strcmp(names[j], pivot) < 0) {
      i++;
      char *temp = names[i];
      names[i] = names[j];
      names[j] = temp;
    }
  }

  // Place the pivot element at its correct position in the array
  char *temp = names[i + 1];
  names[i + 1] = names[high];
  names[high] = temp;

  return i + 1;
}

