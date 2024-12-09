/*
 Name: Sparsh Singh
 University Roll No: 2024329
 Section: C
  
  Q3- Write a C program to find and delete the node with second minimum data in the single link list.
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} NODE;

// Function prototypes
void insert (NODE **);
void display (NODE *);
NODE* deleteSecondMin (NODE *, NODE **);

int main() {
    NODE *head = NULL, *tail = NULL;
    int choice;

    // Menu driven program
    while (1) {
        printf("1. Insert\n2. Display\n3. Delete Second Minimum\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Insert a node at the end of the list
                insert(&tail);
                if (head == NULL) head = tail;
                break;
            case 2:
                // Display the list
                display(head);
                break;
            case 3:
                // Delete the node with second minimum data
                head = deleteSecondMin(head, &tail);
                break;
            case 4:
                // Exit the program
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// Insert a node at the end of the list
void insert (NODE **tail) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    
    // If the list is empty then head and tail will point to the new node else tail will point to the new node
    if (*tail != NULL) (*tail)->next = newNode;
    *tail = newNode;
}

// Display the list 
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

// Delete the node with second minimum data
NODE *deleteSecondMin (NODE *head, NODE **tail) {
  if (head == NULL) return NULL;
  // If the list has only one node then delete it and return NULL
  if (head->next == NULL) {
    free (head);
    return NULL;
  }
  
  // Find the minimum and second minimum data
  int min = head->data, secondMin = head->next->data;
  NODE *temp = head;

  // Traverse the list to find the minimum and second minimum data
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

  // Delete the node with second minimum data from the list and return the new head of the list 
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


