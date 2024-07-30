#include <stdio.h>
#include <stdlib.h>

void push(int *stack, int *top, int n);
int pop (int *stack, int *top);
int peek (int *stack, int *top);
void display (int *stack, int *top);

int main () {
  int n, *stack;
  int *top;
  top = (int *) malloc(sizeof(int)); 
  *top = -1;

  system("clear");
  printf("Enter the size of the stack: ");
  scanf("%d", &n);
  n -= 1;
  stack = (int *) malloc(n * sizeof(int));

  int choice = 0;
  do {
    printf("Choose an operation: \n 1: Push\n 2: Pop\n 3: Peek\n 4: Display\n 5: Exit\nSpecify your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        push(stack, top, n);
        break;

      case 2:
        pop(stack, top);
        break;

      case 3:
        peek(stack, top);
        break;

      case 4:
        display(stack, top);
        break;
    }

    printf("\n");
  } while (choice != 5);

}

int pop (int *stack, int *top) {
  if(*top == -1) {
    printf("\nStack Underflow\n");
    return 0;
  }
  int pop_val = *(stack + *top);
  printf("\nThe element %d has been removed from the top of the stack.\n", pop_val);
  --*(top);
  return pop_val;

}

int peek (int *stack, int *top) {
  printf("\nThe element currently at the top is: %d\n", *(stack + *top));
  return *(stack + *top);
}

void push(int *stack, int *top, int n) {
  int num = 0;
  printf("Enter the number for pushing: ");
  scanf("%d", &num);
  if(*top >= n) {
    printf("\nStack Overflow, can't insert %d.\n", num);
    return;
  }
  *(stack + ++*(top)) = num;
  printf("\nThe number %d has been pushed to the stack.\n", num);
}

void display (int *stack, int *top) {
  if(*top == -1) {
    printf("\nStack is empty.\n");
    return;
  }
  printf("\nThe contents of the stack are: \n\n");
  for (int i = *top; i >= 0; i--) {
    printf("|\t%d\t|\n", *(stack + i));
  }
  printf("\n");
}
