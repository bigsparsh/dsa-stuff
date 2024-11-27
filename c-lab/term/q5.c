// Write a C program to find the node in the  double linked list , at which the two linked list are intersected.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}NODE;

void insert (NODE **, NODE **);
void display (NODE *);
void findIntersection (NODE *, NODE *);

int main() {
  NODE *head1 = NULL, *head2 = NULL, *tail1 = NULL, *tail2 = NULL;
  int choice;

  while (1) {
    printf("1. Insert in list 1\n2. Insert in list 2\n3. Display list 1\n4. Display list 2\n5. Check intersection\n6. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        insert(&head1, &tail2);
        break;
      case 2:
        insert(&head2, &tail2);
        break;
      case 3:
        display(head1);
        break;
      case 4:
        display(head2);
        break;
      case 5:
        findIntersection (head1, head2);
        break;
      case 6:
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}

void insert (NODE **head, NODE **tail) {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  printf("Enter data: ");
  scanf("%d", &newNode->data);
  newNode->next = NULL;
  newNode->prev = NULL;

  if (*head == NULL) {
    *head = newNode;
    *tail = newNode;
    return;
  }

  (*tail)->next = newNode;
  newNode->prev = *tail;
  *tail = newNode;
}

void display (NODE *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }

  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

void findIntersection (NODE *head1, NODE *head2) {
  NODE *h1 = head1, *h2 = head2;
  while (h1 != NULL) {
    h2 = head2;
    while (h2 != NULL) {
      if (h1->data == h2->data) {
        printf("Intersection found at %d\n", h1->data);
        return;
      }
      h2 = h2->next;
    }
    h1 = h1->next;
  }
  printf("No intersection found\n");
}
