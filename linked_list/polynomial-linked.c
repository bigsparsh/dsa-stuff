#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int epo;
  int cnst;
  struct node *next;
} NODE;

NODE* addExp (NODE *, NODE *);
NODE* insert (NODE *);
void display (NODE *);

int main () {
  int size1, size2;
  NODE *head1 = NULL, *head2 = NULL, *tail1 = NULL, *tail2 = NULL, *head3;

  printf ("Enter the size of first expression: ");
  scanf("%d", &size1);

  for (int i = 0; i < size1; i++) {
    tail1 = insert (tail1);
    if (head1 == NULL) head1 = tail1;
  }

  printf ("Enter the size of second expression: ");
  scanf("%d", &size2);

  for (int i = 0; i < size2; i++) {
    tail2 = insert (tail2);
    if (head2 == NULL) head2 = tail2;
  }

  head3 = addExp (head1, head2);
  display (head3);

  return 0;

}

NODE* insert (NODE *tail) {
  NODE *newNode = (NODE *) malloc(sizeof(NODE));
  printf("\nEnter the constant for the node: ");
  scanf("%d", &newNode->cnst);
  printf("\nEnter the exponent for the node: ");
  scanf("%d", &newNode->epo);
  newNode->next = NULL;

  if (tail != NULL) tail->next = newNode;
  tail = newNode;

  return tail;
}

NODE* addExp (NODE *head1, NODE *head2) {
  NODE *head3 = NULL, *h2 = head2, *tail3 = NULL;
  while (head1 != NULL) {
    while (h2 != NULL) {
      if (head1->epo == h2->epo) {
        NODE *newNode = (NODE *) malloc(sizeof(NODE));
        newNode->epo = head1->epo;
        newNode->cnst = head1->epo + h2->epo;
        newNode->next = NULL;
        if (tail3 != NULL) tail3->next = newNode;
        tail3 = newNode;
        if (head3 == NULL) head3 == tail3;
      }
      h2 = h2->next;
    }
    h2 = head2;
    head1 = head1->next;
  }
  return head3;
}

void display (NODE *head) {
  printf("\nThe elements of the linked list are: ");
  while (head != NULL) {
    printf(" %d^%d ", head->cnst, head->epo);
    head = head->next;
  }
  printf("\n");
}
