#include <stdio.h>
#define MAX 10

int push (int [], int);
int pop (int [], int);
void display (int [], int);

int main () {
  int arr[10], choice, top = -1;

  do {
    printf("===[STACK PROGRAM]===\n 1. Push\n 2. Pop\n 3. Display\n 4. Exit\n Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        top = push(arr, top);
        break;
      case 2:
        top = pop(arr, top);
        break;
      case 3:
        display(arr, top);
        break;
      case 4:
        printf("Exiting program\n");
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 4);
  
}

int push (int arr[], int top) {
  int element;
  if (top == MAX - 1) {
    printf("Stack is full\n");
  } else {
    printf("Enter element to push: ");
    scanf("%d", &element);
    arr[++top] = element;
  }
  return top;
}

int pop (int arr[], int top) {
  if (top == -1) {
    printf("Stack is empty\n");
    return top;
  } else {
    printf("Element popped: %d\n", arr[top]);
  return --top;
  }
}

void display (int arr[], int top) {
  if (top == -1) {
    printf("Stack is empty\n");
  } else {
    for (int i = top; i >= 0; i--) {
      printf("%d\n", arr[i]);
    }
  }
}
