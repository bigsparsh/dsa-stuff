#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int time;
  int index;
  struct node *next;
} NODE;

NODE* insert (NODE *);
NODE* delete (NODE *, NODE *, int);
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
    tail = insert (tail);
    if (head == NULL) head = tail;
  }

  execute_process (head, ttp);

}

NODE* insert (NODE *tail) {
  NODE *newNode = (NODE *) malloc(sizeof(NODE));
  newNode->next = NULL;
  printf("\nEnter the index of the process: ");
  scanf("%d", &newNode->index);

  printf("\nEnter the execution time for process: ");
  scanf("%d", &newNode->time);

  if (tail != NULL) tail->next = newNode;
  tail = newNode;
  
  return tail;
}

NODE* delete (NODE* head, NODE* ptr, int time) {
  if (head == ptr) head = head->next;
  else {
    while (head->next != ptr) head = head->next;
    if (ptr->next == NULL) head->next = NULL;
    else head->next = ptr->next;
  }
  printf("\nProcess P%d took %d time to get executed\n", ptr->index, time);
  free(ptr);
  return head;
}

void execute_process (NODE *head, int ttp) {
  NODE *h_ptr = head, *temp = NULL;
  int time_counter = 0;
  while (head != NULL) {
    while (h_ptr != NULL) {
      temp = h_ptr->next;
      h_ptr->time -= ttp;
      time_counter += ttp;
      if (h_ptr->time <= 0) head = delete(head, h_ptr, time_counter);
      h_ptr = temp;
      temp = NULL;
    }
    h_ptr = head;
  }
}

void display (NODE *head) {
  printf("\nELements:\n");
  while (head != NULL) {
    printf(" [ P%d {%d} ] ", head->index, head->time);
    head = head->next;
  }
  printf("\n");
}
