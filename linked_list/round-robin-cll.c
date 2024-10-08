#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int time;
  int index;
  struct node *next;
} NODE;

NODE* insert (NODE *, NODE *);
NODE* delete (NODE *, int);
void execute_process (NODE *, int);
void display (NODE *);

int main () {
  NODE *head = NULL, *tail = NULL;
  int size, ttp;

  printf("\nHow many proccess will you use?: ");
  scanf("%d", &size);

  printf("\nWhat is the amount of time that CPU gives to each process?: ");
  scanf("%d", &ttp);

  for (int i = 0; i < size; i++) {
    tail = insert (head, tail);
    if (head == NULL) head = tail;
  }

  display(head);
  execute_process (head, ttp);

}

NODE* insert (NODE *head, NODE *tail) {
  NODE *newNode = (NODE *) malloc(sizeof(NODE));

  newNode->next = (head == NULL) ? newNode : head;
  newNode->index = (head == NULL) ? 1 : tail->index + 1;

  printf("\nEnter the execution time for process %d: ", newNode->index);
  scanf("%d", &newNode->time);

  if (tail != NULL) tail->next = newNode;
  tail = newNode;
 
  return tail;
}

NODE* delete (NODE*head, int time) {
  NODE *h = head;
  if (head->next == head) {
    printf("\nProcess P%d executed in %d time.\n", h->index, time + h->time);
    free (h);
    return NULL;
  }
  while (head->next != h) head = head->next;
  head->next = h->next;
  printf("\nProcess P%d executed in %d time.\n", h->index, time + h->time);
  free (h);
  return head->next;
}

void execute_process (NODE *head, int ttp) {
  int time_counter = 0;
  NODE *temp = NULL;
  while (head != NULL) {
    head->time -= ttp;
    time_counter += ttp;
    if (head->time <= 0) head = delete (head, time_counter);
    else head = head->next;
  }
}

void display (NODE *head) {
  NODE *h = head;
  printf("\nElements: ");
  do {
    printf(" [ P%d {%d} ] ", head->index, head->time);
    head = head->next;
  } while (head != h);
  printf("\n");
}
