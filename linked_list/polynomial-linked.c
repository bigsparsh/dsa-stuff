#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int exponent;
  int constant;
  struct node *next;
} NODE;

NODE* insert (NODE *, int);
NODE* addPoly (NODE *, NODE *);
void display (NODE *);

int main () {
  int choice, p1_size, p2_size;
  NODE *p1_head = NULL;
  NODE *p2_head = NULL;

  printf("\nHow long should the first expression be: ");
  scanf("%d", &p1_size);

  for (int i = 0; i < p1_size ; i++) p1_head = insert(p1_head);
  
  printf("\nHow long should the second expression be: ");
  scanf("%d", &p1_size);

  for (int i = 0; i < p2_size ; i++) p2_head = insert(p2_head);

  addPoly(p1_head, p2_head);

  return 0;
}

NODE* addPoly (NODE *p1_head, NODE *p2_head) {
  NODE *p1 = p1_head;
  NODE *p2 = p2_head;
  NODE *p3_head = NULL;

  while (p1 != NULL) {
    
    while (p2 != NULL) {
      if (p1->exponent == p2->exponent) {

      }
      p2 = p2->next;
    }
    p1 = p1->next;
  }
}

NODE* insert (NODE *head, int size) {
  NODE *h = head;
  int count = 0;
  while (h != NULL) {
    h = h->next;
    count++;
  }
  if (size <= count) {
    printf("\bBro, you said the size was %d, now don't be a hypocrite and stop inserting.\n", size);
    return head;
  }
  h = head;
  NODE *newNode = (NODE *) malloc(sizeof(NODE));
  printf("\nEnter the base for the node: ");
  scanf("%d", &newNode->base);
  printf("\nEnter the constant for the node: ");
  scanf("%d", &newNode->constant);
  newNode->next = NULL;
  if (head != NULL) {
    while (h->next != NULL) {
      h = h->next;
    }
    h->next = newNode;
  } else {
    h = newNode;
  }
  return head;
}

void display (NODE *head) {
  printf("\nThe contents of this array is: \n");
  while (head != NULL) {
    printf(" [ %d ] ", head->data);
    head = head->next;
  }
}
