/*
 Name: Sparsh Singh
 University Roll No: 2024329
 Section: C
  
  Q5- Write a C program to find the node in the  double linked list , at which the two linked list are intersected.
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}NODE;

// Function prototypes
void insert (NODE **, NODE **);
void display (NODE *);
void findIntersection (NODE *, NODE *);

int main() {
  NODE *head1 = NULL, *head2 = NULL, *tail1 = NULL, *tail2 = NULL;
  int choice;

  // Menu driven program
  while (1) {
    printf("1. Insert in list 1\n2. Insert in list 2\n3. Display list 1\n4. Display list 2\n5. Check intersection\n6. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // Insert a node at the end of the list 1
        insert(&head1, &tail2);
        break;
      case 2:
        // Insert a node at the end of the list 2
        insert(&head2, &tail2);
        break;
      case 3:
        // Display the list 1
        display(head1);
        break;
      case 4:
        // Display the list 2
        display(head2);
        break;
      case 5:
        // Check if the two lists intersect
        findIntersection (head1, head2);
        break;
      case 6:
        // Exit the program
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}

// Insert a node at the end of the list
void insert (NODE **head, NODE **tail) {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  printf("Enter data: ");
  scanf("%d", &newNode->data);
  newNode->next = NULL;
  newNode->prev = NULL;

  // If the list is empty then head and tail will point to the new node else tail will point to the new node
  if (*head == NULL) {
    *head = newNode;
    *tail = newNode;
    return;
  }

  (*tail)->next = newNode;
  newNode->prev = *tail;
  *tail = newNode;
}

// Display the list
void display (NODE *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }

  // Print the list
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

// Check if the two lists intersect
void findIntersection (NODE *head1, NODE *head2) {
  NODE *h1 = head1, *h2 = head2;
  // Traverse the two lists and check if any node is common in both the lists
  while (h1 != NULL) {
    h2 = head2;
    while (h2 != NULL) {
      if (h1->data == h2->data) {
        printf("Intersection found at %d\n", h1->data);
        return;
      }
      h2 = h2->next;
    }
    h1 = h1->next;
  }
  printf("No intersection found\n");
}
