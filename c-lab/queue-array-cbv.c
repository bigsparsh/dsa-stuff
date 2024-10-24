#include <stdio.h>
#define MAX 10

int enqueue (int [], int);
int dequeue (int [], int);
void display (int [], int, int);

int main () {
  int queue[MAX], choice, front = -1, rear = -1;

  do {
    printf("===[QUEUE PROGRAM]===\n 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\n Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        rear = enqueue(queue, rear);
        if (front == -1) front = 0;
        break;
      case 2:
        front = dequeue(queue, front);
        if (front > rear) front = rear = -1;
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

int enqueue (int queue[], int rear) {
  int element;
  if (rear == MAX - 1) {
    printf("Queue is full\n");
  } else {
    printf("Enter element to enqueue: ");
    scanf("%d", &element);
    queue[++rear] = element;
  }
  return rear;
}

int dequeue (int queue[], int front) {
  if (front == -1) {
    printf("Queue is empty\n");
    return front;
  } else {
    printf("Element dequeued: %d\n", queue[front]);
    return ++front;
  }
}

void display (int queue[], int front, int rear) {
  if (front == -1) {
    printf("Queue is empty\n");
  } else {
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
      printf("%d ", queue[i]);
    }
    printf("\n");
  }
}
