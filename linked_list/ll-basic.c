#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} NODE;

NODE* insert (NODE *);
// void remove ();
void display (NODE *);


int main () {
  int size, choice = 0;

  printf("\nEnter the size of the linked list: ");
  scanf("%d", &size);

  NODE *head = NULL;

  do {
    printf("====[LINKED LIST]====\n 1. Insert node\n 2. Remove node\n 3. Display\n 4. Exit program\nEnter your choice (1/2/3/4): ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        head = insert (head);
        break;
      case 3:
        display(head);
        break;
    }
  } while (choice != 4);

  return 0;
}

NODE* insert (NODE *head) {
  if (head == NULL) {
    int data;
    printf("\nEnter the element for inserting: ");
    scanf("%d", &data);

    NODE newNode;
    newNode.data = data;
    newNode.next = NULL;
    head = &newNode;

  } else {
    NODE *h = head;
    while (h->next != NULL) {
      h = h->next;
    }
    int data;
    printf("\nEnter the element for inserting: ");
    scanf("%d", &data);

    NODE newNode;
    newNode.data = data;
    newNode.next = NULL;
    h->next = &newNode;
  }
  return head;
}

void display (NODE *head) {
  NODE *h = head;
  printf("\nThe contents of the linked list are: \n");
  while (h->next != NULL) {
    printf(" [ %d ] ", h->data);
    h = h->next;
  }
}
