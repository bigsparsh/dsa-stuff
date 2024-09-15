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
  NODE *head1 = NULL, *head2 = NULL, *tail1 = NULL, *tail2 = NULL, *head3 = NULL;

  printf ("\nEnter the size of first expression: ");
  scanf("%d", &size1);

  for (int i = 0; i < size1; i++) {
    tail1 = insert (tail1);
    if (head1 == NULL) head1 = tail1;
  }
  display(head1);

  printf ("\nEnter the size of second expression: ");
  scanf("%d", &size2);

  for (int i = 0; i < size2; i++) {
    tail2 = insert (tail2);
    if (head2 == NULL) head2 = tail2;
  }
  display(head2);

  head3 = addExp (head1, head2);
  display (head3);

  return 0;

}

NODE* insert (NODE *tail) {
  NODE *newNode = (NODE *) malloc(sizeof(NODE));
  printf("\nConstant: ");
  scanf("%d", &newNode->cnst);
  printf("Exponent: ");
  scanf("%d", &newNode->epo);
  newNode->next = NULL;

  if (tail != NULL) tail->next = newNode;
  tail = newNode;

  return tail;
}

NODE* addExp (NODE *head1, NODE *head2) {
  NODE *h2 = head2, *h1 = head1;
  while (h1 != NULL) {
    while (h2 !=  NULL) {
      if (h1->epo == h2->epo) {
        h1->cnst += h2->cnst;
        break;
      } 
      h2 = h2->next;
    }
    h2 = head2;
    h1 = h1->next;
  }
  return head1;
}

void display (NODE *head) {
  printf("\nThe elements of the linked list are: ");
  while (head != NULL) {
    printf(" %da^%d ", head->cnst, head->epo);
    head = head->next;
  }
  printf("\n");
}
