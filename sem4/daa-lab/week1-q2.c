#include <stdio.h>

int binary_search(int arr[], int low, int high, int key, int *comp) {
    (*comp)++;
    if (low > high) return -1;
    int mid = (low + high) / 2;

    if (arr[mid] == key) return mid;
    else if (arr[mid] > key) return binary_search(arr, low, mid - 1, key, comp);
    else return binary_search(arr, mid + 1, high, key, comp);
}

int main () {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key, comp = 0;
    
    printf("Enter the key to search: ");
    scanf("%d", &key);
    
    int result = binary_search(arr, 0, size - 1, key, &comp);
    
    if (result != -1) {
        printf ("Comparisons: %d\n", comp);
    printf("Element found at index %d\n", result);
    }
    else 
        printf("Element not found\n");
}
