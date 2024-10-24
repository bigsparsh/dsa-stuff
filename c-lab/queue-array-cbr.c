#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void enqueue (int *, int *, int *);
void dequeue (int *, int *, int *);
void display (int *, int, int);

int main () {
  int *queue = (int *) malloc(MAX * sizeof(int));
  int front = -1, rear = -1, choice;

  do {
    printf("===[QUEUE PROGRAM]===\n 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\n Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        enqueue(queue, &front, &rear);
        break;
      case 2:
        dequeue(queue, &front, &rear);
        break;
      case 3:
        display(queue, front, rear);
        break;
      case 4:
        printf("Exiting program\n");
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 4);
  

}

void enqueue (int *queue, int *front, int *rear) {
  int element;
  if (*rear == MAX - 1) {
    printf("Queue is full\n");
  } else {
    printf("Enter element to enqueue: ");
    scanf("%d", &element);
    if (*front == -1) *front = 0;
    *(queue + ++*rear) = element;
  }
}

void dequeue (int *queue, int *front, int *rear) {
  if (*front == -1) {
    printf("Queue is empty\n");
  } else {
    printf("Element dequeued: %d\n", *(queue + *front));
    if (*front == *rear) {
      *front = *rear = -1;
    } else {
      ++*front;
    }
  }
}

void display (int *queue, int front, int rear) {
  if (front == -1) {
    printf("Queue is empty\n");
  } else {
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
      printf("%d ", *(queue + i));
    }
    printf("\n");
  }
}
