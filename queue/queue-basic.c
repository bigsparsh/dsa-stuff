#include <stdio.h>
#include <stdlib.h>

void enqueue(int *, int *, int *, int);
void dequeue(int *, int *, int *);
void display(int *, int, int);
void peek(int *, int, int);

int main () {
  int queue_size, *queue;
  int *front = (int *) malloc(sizeof(int)),
  *rear = (int *) malloc(sizeof(int));
  *front = -1, *rear = -1;

  system("clear");
  printf("Enter the size of the queue: ");
  scanf("%d", &queue_size);

  queue = (int *) malloc(queue_size * sizeof(int));

  int choice = 0;
  do {
    printf("Choose an operation: \n 1: Enqueue\n 2: Dequeue\n 3: Peek\n 4: Display\n 5: Exit\nSpecify your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        enqueue(queue, front, rear, queue_size);
        break;

      case 2:
        dequeue(queue, front, rear);
        break;

      case 3:
        peek(queue, *front, *rear);
        break;

      case 4:
        display(queue, *front, *rear);
        break;
    }

    printf("\n");
  } while (choice != 5);

  return 0;
}

void enqueue (int *queue, int *front, int *rear, int queue_size) {
  if (*rear == queue_size - 1) {
    printf("\nQueue overflow, can't insert value.\n");
    return;
  }
  if(*front == -1) ++*front;
 
  printf("\nEnter an element to enqueue: ");
  scanf("%d", queue + ++*rear);
}

void dequeue (int *queue, int *front, int *rear) {
  if (*front == -1) {
    printf("\nQueue underflow, can't remove value.\n");
    return;
  }
  printf("\nThe element %d has been removed from the queue.\n", *(queue + *front));
  *front += 1;
}

void display (int *queue, int front, int rear) {
  if (front == -1) {
    printf("\nQueue underflow, can't remove value.\n");
    return;
  }
  printf("\nThe contents of queue are: \n\n");
  for (int i = front ; i <= rear ; i++) {
    printf(" | %d | ", *(queue + i));
  }
  printf("\n");
}

void peek (int *queue, int front, int rear) {
  if (front == -1) {
    printf("\nQueue underflow, can't remove value.\n");
    return;
  }
  printf("\nElement at FRONT is %d and element at REAR is %d.\n", *(queue + front), *(queue + rear));
}
