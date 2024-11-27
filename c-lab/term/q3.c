// Write a C program to find and delete the node with second minimum data in the single link list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

void insert (NODE **);
void display (NODE *);
NODE* deleteSecondMin (NODE *, NODE **);

int main() {
    NODE *head = NULL, *tail = NULL;
    int choice;
    while (1) {
        printf("1. Insert\n2. Display\n3. Delete Second Minimum\n4. Exit\nEnter your choice: ");
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
                head = deleteSecondMin(head, &tail);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void insert (NODE **tail) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    
    if (*tail != NULL) (*tail)->next = newNode;
    *tail = newNode;
}

void display (NODE *head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        NODE *temp = head;
        while (temp != NULL) {
            printf(" %d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

NODE *deleteSecondMin (NODE *head, NODE **tail) {
  if (head == NULL) return NULL;
  if (head->next == NULL) {
    free (head);
    return NULL;
  }
  
  int min = head->data, secondMin = head->next->data;
  NODE *temp = head;

  while (temp != NULL) {
    if (temp->data < min) {
      secondMin = min;
      min = temp->data;
    } else if (temp->data < secondMin && temp->data != min) {
      secondMin = temp->data;
    }
    temp = temp->next;
  }
  temp = head;

  if (head->data == secondMin) {
    head = head->next;
    free (temp);
  } else {
    while (temp->next != NULL) {
      if (temp->next->data == secondMin) {
        NODE *del = temp->next;
        temp->next = temp->next->next;
        if (del == *tail) {
          *tail = temp;
        }
        free (del);
        break;
      }
      temp = temp->next;
    }
  }

  return head;
}


