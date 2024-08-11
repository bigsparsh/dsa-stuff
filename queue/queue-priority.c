#include <stdio.h>
#include <stdlib.h>

void enqueue (int *, int *, int *, int);
void dequeue (int *, int *, int *, int);
void display (int *, int, int, int);
void peek (int *, int);


int main () {
  int queue_size;
  printf("Enter the size of the queue: ");
  scanf("%d", &queue_size);
  queue_size *= 2;

  int *queue = (int *) malloc(queue_size * sizeof(int)),
    *head = (int *) malloc(sizeof(int)),
    *tail = (int *) malloc(sizeof(int)),
    choice = 0 ;
  *head = -1, *tail = -1;

  do {
    printf("====| PRIORITY QUEUE |====\n 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Peek\n 5. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        enqueue(queue, head, tail, queue_size);
        if (*tail != -1 && *head == -1) (*head)++;
        break;
      case 2:
        dequeue(queue, head, tail, queue_size);
        break;
      case 3:
        display(queue, *head, *tail, queue_size);
        break;
      case 4:
        peek(queue, *tail);
        break;
      case 5:
        printf("Exiting...\n");
        break;
    }

    printf("\n");

  } while (choice != 5);


}

void enqueue (int *queue, int *head, int *tail, int queue_size) {
  if (*tail == queue_size - 1) {
    printf("\nThe queue is overflowing.\n");
    return;
  }
  int element, priority;
  printf("\nEnter the element to insert: ");
  scanf("%d", &element);
  printf("\nEnter the priority of that element: ");
  scanf("%d", &priority);

  int index = -1;
  for (int i=1; i<=*tail; i+=2) {
    if (priority >= *(queue + i)) {
       index = i;
    }
  }
  if (index != -1) {
    printf("\n\nThis happened.\n\n");
    index-=1;
      for (int i=*tail; i>=index; i--) {
        *(queue + i + 2) = *(queue + i);
      }
    *(queue + index) = element;
    *(queue + index + 1) = priority;
    *tail += 2;
  } else {
    *(queue + ++*tail) = element;
    *(queue + ++*tail) = priority;
  }
}

void dequeue (int *queue, int *head, int *tail, int queue_size) {
  if (*head == -1) {
    printf("\nThe queue is underflowing can't show any elements.\n");
    return;
  }
  printf("\n%d with %d priority was removed.\n", *(queue + (*tail)--), *(queue + (*tail)--));
}

void display (int *queue, int head, int tail, int queue_size) {
  if (head == -1) {
    printf("\nThe queue is underflowing can't show any elements.\n");
    return;
  }
  printf("\nThe contents of this queue are: \n");
  for (int i = head ; i <= tail; i+=2) {
    printf(" [ %d -> %d ] ", *(queue + i), *(queue + i + 1));
  }
  for (int i = tail + 1; i < queue_size ; i+=2) {
    printf(" [ X ] ");
  }
}

void peek (int *queue, int tail) {
  if (tail == -1) {
    printf("\nThe queue is underflowing can't show any elements.\n");
    return;
  }
  printf("\nThe TAIL is %d.\n", *(queue + tail));
}
