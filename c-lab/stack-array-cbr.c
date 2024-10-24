#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void push (int *, int *);
void pop (int *, int *);
void display (int *, int);

int main () {
  int *stack = (int *) malloc(MAX * sizeof(int));
  int top = -1, choice;

  do {
    printf("===[STACK PROGRAM]===\n 1. Push\n 2. Pop\n 3. Display\n 4. Exit\n Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        push(stack, &top);
        break;
      case 2:
        pop(stack, &top);
        break;
      case 3:
        display(stack, top);
        break;
      case 4:
        printf("Exiting program\n");
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 4);
  

}

void push (int *stack, int *top) {
  int element;
  if (*top == MAX - 1) {
    printf("Stack is full\n");
  } else {
    printf("Enter element to push: ");
    scanf("%d", &element);
    *(stack + ++*top) = element;
  }
}

void pop (int *stack, int *top ) {
  if (*top == -1) {
    printf("Stack is empty\n");
  } else {
    printf("Element popped: %d\n", *(stack + (*top)--));
  }
}

void display (int *stack, int top) {
  if (top == -1) {
    printf("Stack is empty\n");
  } else {
    for (int i = top; i >= 0; i--) {
      printf("%d\n", *(stack + i));
    }
  }
}
