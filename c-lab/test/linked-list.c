#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} NODE;

void insert(NODE **);
void deleteFront(NODE **);
void display(NODE *);

int main() {
  NODE *head = NULL, *tail = NULL;

  int choice;

  do {
    printf("\n===[LINKED LIST]===\n 1. Insert\n 2. Delete\n 3. Display\n 4. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      insert(&tail);
      if (head == NULL)
        head = tail;
      break;
    case 2:
      deleteFront (&head);
      break;
    case 3:
      display (head);
      break;
      case 4:
        printf("Exiting...");
    }

  } while (choice != 4);

  return 0;
}

void insert (NODE** tail) {
  NODE *newNode = (NODE *) malloc(sizeof(NODE));
  newNode->next = NULL;
  printf("\nEnter the data of the node: ");
  scanf("%d", &newNode->data);

  if (*tail != NULL) (*tail)->next = newNode;
  *tail = newNode;
}

void deleteFront (NODE **head) {
  if (*head == NULL) {
    printf("\nNothing to delete\n");
    return;
  }
  NODE *ptr = *head;
  (*head) = (*head)->next;
  free (ptr);
}

void display (NODE *head) {
  printf ("\nContents of the list: ");
  while (head != NULL) {
    printf(" [%d] ", head->data);
    head = head->next;
  }
  printf("\n");
}
