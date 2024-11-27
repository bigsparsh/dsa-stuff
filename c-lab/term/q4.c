// Write a C program to   create a single linked list, then find whether there exist any two nodes in the    
//        linked list whose multiplication is less than the target value.
//        Example:
//        Input:  Linked-List =  12->15->3->4->6, Target = 20
//        Output: Yes 

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} NODE;

void insert (NODE **);
void display (NODE *);
int isProductLessThanTarget (NODE *, int);

int main() {
    NODE *head = NULL, *tail = NULL;
    int choice, target;
    while (1) {
        printf("1. Insert\n2. Display\n3. Check if product of any two nodes is less than target\n4. Exit\nEnter your choice: ");
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
                printf("Enter the target value: ");
                scanf("%d", &target);
                if (isProductLessThanTarget(head, target)) {
                    printf("Yes\n");
                } else {
                    printf("No\n");
                }
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

int isProductLessThanTarget (NODE *head, int target) {
  NODE *current = head;
  while (current != NULL) {
    NODE *next = current->next;
    while (next != NULL) {
      if (current->data * next->data < target) {
        return 1;
      }
      next = next->next;
    }
    current = current->next;
  }
  return 0;
}


