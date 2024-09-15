#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} NODE;

NODE* insert (NODE *);
NODE* reverse (NODE *, NODE *);
void display (NODE *);

int main () {
  NODE *head = NULL, *tail = NULL, *temp = NULL;
  int choice;
  
  do {
    printf("\n===[REVERSING LINKED LIST]===\n 1. Insert\n 2. Display\n 3. Reverse\n 4. Exit\nEnter choice (1-4): ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        tail = insert (tail);
        if (head == NULL) head = tail;
        break;
      case 2:
        display (head);
        break;
      case 3:
        temp = head;
        head = reverse (head, tail);
        tail = temp;
        break;
      case 4:
        break;
      default:
        printf("\nInvalid Choice\n");
        break;
    }
  } while (choice != 4);


}
NODE* insert (NODE *tail) {
  NODE *newNode = (NODE *) malloc(sizeof(NODE));
  printf("\nEnter data for the list: ");
  scanf("%d", &newNode->data);

  newNode->next = NULL;
  if (tail != NULL) tail->next = newNode;
  tail = newNode;

  return tail;
}

NODE* reverse (NODE* head, NODE *tail) {
  NODE *h = head;
  while (h != tail) {
    head = head->next;
    h->next = tail->next;
    tail->next = h;
    h = head;
  }
  return head;
}


void display (NODE *head) {
  printf("\nThe elements of the linked list are: ");
  while (head != NULL) {
    printf(" [ %d ] ", head->data);
    head = head->next;
  }
  printf("\n");
}
