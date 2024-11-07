#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} NODE;

NODE* insert (NODE *);
NODE* altNodes (NODE *);
NODE* reverse (NODE *, NODE *);
void display (NODE *);
int checkPallindrome (NODE *, NODE **);
NODE *taill = NULL;

int main () {
  NODE *head = NULL, *tail = NULL, *temp = NULL;
  int choice, isPallindrome;
  
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
        NODE *taill = head;
        if (checkPallindrome(head, &taill) == 1)
            printf("\nLinked List is a Pallindrome\n");
        else
            printf("\nLinked List is not a Pallindrome\n");
        break;
      case 5:
        head = altNodes(head);
      default:
        printf("\nInvalid Choice\n");
        break;
    }
  } while (choice != 7);


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

// NODE* reverse (NODE* head, NODE *tail) {
//   NODE *h = head;
//   while (h != tail) {
//     head = head->next;
//     h->next = tail->next;
//     tail->next = h;
//     h = head;
//   }
//   return head;
// }

NODE* reverse (NODE *head, NODE *tail) {
  NODE *h = head, *c = head;
  while (c->next != NULL) {
    c = c->next;
    h->next = c->next;
    c->next = head;
    head = c;
    c = h;
  }
  return head;
}

NODE *altNodes (NODE *head) {
    NODE *temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return head;
}

int checkPallindrome(NODE* head, NODE **tail) {
    if (head == NULL) return 1;
    int isPal = checkPallindrome(head->next, tail);
    if (isPal == -1) return -1;
    int isDataEqual = ((*tail)->data == head->data ? 1 : -1);
    *tail = (*tail)->next;
    return isDataEqual;
}


void display (NODE *head) {
  printf("\nThe elements of the linked list are: ");
  while (head != NULL) {
    printf(" [ %d ] ", head->data);
    head = head->next;
  }
  printf("\n");
}
