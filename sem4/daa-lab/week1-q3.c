#include <stdio.h>

int jumpSearch (int arr[], int n, int key, int *comp) {
    int step = 3;
    int prev = 0;
    while (prev + step < n && arr[prev + step - 1] < key) {
        (*comp)++;
        prev += step;
        if (prev >= n) return -1;
    }
    for (int i = prev; i < (prev + step < n ? step + prev: n); i++) {
        (*comp)++;
        if (arr[i] == key) return i;
    }
    return -1;
}

int main () {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key, comp = 0;
    
    printf("Enter the key to search: ");
    scanf("%d", &key);
    
    int result = jumpSearch(arr, size, key, &comp);
    
    if (result != -1) {
        printf ("Comparisons: %d\n", comp);
        printf("Element found at index %d\n", result);
    }
    else 
        printf("Element not found\n");
}
