// Write a C program to implement time sharing environment using circular linked list to allocate time slots of 10ns for N given processes, and then print which process will be completed in how much time.
 
#include <stdio.h>
 #include <stdlib.h>

typedef struct Node {
    int processId;
    int time;
    struct Node *next;
} NODE;

void insert (NODE **, int, int);
void display (NODE *);
void allocateTime (NODE *, int);
void deleteNode (NODE **);

int main () {
  NODE *head = NULL;
  int choice, processId, time;

  while (1) {
    printf("1. Insert process\n2. Display\n3. Allocate time\n4. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter process id: ");
        scanf("%d", &processId);
        printf("Enter time slot: ");
        scanf("%d", &time);
        insert(&head, processId, time);
        break;
      case 2:
        display(head);
        break;
      case 3:
        allocateTime(head, 10);
        head = NULL;
        break;
      case 4:
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}

void insert (NODE **head, int processId, int time) {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->processId = processId;
  newNode->time = time;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
    newNode->next = *head;
    return;
  }

  NODE *temp = *head;
  while (temp->next != *head) temp = temp->next;

  temp->next = newNode;
  newNode->next = *head;
}

void display (NODE *head) {
  if (head == NULL) {
    printf("List is empty\n");
  } else {
    NODE *temp = head;
    do {
      printf("Process id: %d, Time: %d\n", temp->processId, temp->time);
      temp = temp->next;
    } while (temp != head);
  }
}

void deleteNode (NODE **node) {
  NODE *temp = *node;

  if (temp->next == temp) {
    free(temp);
    *node = NULL;
    return;
  }

  while (temp->next != *node) temp = temp->next;
  temp->next = (*node)->next;
  free(*node);
  *node = temp->next;
}

void allocateTime (NODE *head, int n) {
  int count_time = 0;
  if (head == NULL) {
    printf("List is empty\n");
  } else {
    NODE *temp = head;
    do {
      count_time += n;
      if (temp->time > n) {
        temp->time -= n;
        temp = temp->next;
      } else {
        printf("Process id: %d completed in %d ns\n", temp->processId, count_time);
        deleteNode(&temp);
      }
    } while (temp != NULL);
  }
}
