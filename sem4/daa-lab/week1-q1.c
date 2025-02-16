#include <stdio.h>

int linear_search(int arr[], int n, int key, int *comp) {
    for (int i = 0; i < n; i++) {
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
    
    int index = linear_search(arr, size, key, &comp);

    if (index != -1) {
        printf ("Comparisons: %d\n", comp);
        printf("Element found at index %d\n", index);
    }
    else 
        printf("Element not found\n");

    return 0;

}
