// Write a menu driven  program to reverse a single linked list in O(N) time with a non-recursive function

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

void insert (NODE **);
void display (NODE *);
NODE* reverse (NODE *);

int main() {
    NODE *head = NULL, *tail = NULL;
    int choice;
    while (1) {
        printf("1. Insert\n2. Display\n3. Reverse\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert(&tail);
                if (head == NULL) head = tail;
                break;
            case 2:
                display(head);
                break;
            case 3:
                NODE *temp = head;
                head = reverse(head);
                tail = temp;
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

NODE *reverse (NODE *head) {
  NODE *prev = NULL, *current = head, *next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

void insert (NODE **tail) {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  printf("Enter data: ");
  scanf("%d", &newNode->data);
  newNode->next = NULL;
  if (*tail != NULL)
    (*tail)->next = newNode;
  *tail = newNode;
}

void display (NODE *head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        NODE *temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
