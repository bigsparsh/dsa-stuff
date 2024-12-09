/*
 Name: Sparsh Singh
 University Roll No: 2024329
 Section: C
  
  Q8- Write a C program to implement time sharing environment using circular linked list to allocate time slots of 10ns for N given processes, and then print which process will be completed in how much time.
*/
 
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int processId;
    int time;
    struct Node *next;
} NODE;

// Function prototypes
void insert (NODE **, int, int);
void display (NODE *);
void allocateTime (NODE *, int);
void deleteNode (NODE **);

int main () {
  NODE *head = NULL;
  int choice, processId, time;

  // Menu driven program
  while (1) {
    printf("1. Insert process\n2. Display\n3. Allocate time\n4. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // Insert a process in the list
        printf("Enter process id: ");
        scanf("%d", &processId);
        printf("Enter time slot: ");
        scanf("%d", &time);
        insert(&head, processId, time);
        break;
      case 2:
        // Display the list
        display(head);
        break;
      case 3:
        // Allocate time to the processes in the list
        allocateTime(head, 10);
        head = NULL;
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

// Insert a process in the list
void insert (NODE **head, int processId, int time) {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->processId = processId;
  newNode->time = time;
  newNode->next = NULL;

  // If the list is empty then head will point to the new node else the new node will be inserted at the end of the list
  if (*head == NULL) {
    *head = newNode;
    newNode->next = *head;
    return;
  }

  // Insert the new node at the end of the list
  NODE *temp = *head;
  while (temp->next != *head) temp = temp->next;

  // Insert the new node at the end of the list
  temp->next = newNode;
  newNode->next = *head;
}

// Display the list
void display (NODE *head) {
  if (head == NULL) {
    printf("List is empty\n");
  } else {
    NODE *temp = head;
    do {
      printf("Process id: %d, Time: %d\n", temp->processId, temp->time);
      temp = temp->next;
    } while (temp != head);
  }
}

// Delete a node from the list
void deleteNode (NODE **node) {
  NODE *temp = *node;

  // If the list has only one node then delete it and set head to NULL
  if (temp->next == temp) {
    free(temp);
    *node = NULL;
    return;
  }

  // Delete the node from the list
  while (temp->next != *node) temp = temp->next;
  temp->next = (*node)->next;
  free(*node);
  *node = temp->next;
}

// Allocate time to the processes in the list
void allocateTime (NODE *head, int n) {
  int count_time = 0;
  // If the list is empty then print "List is empty" else allocate time to the processes in the list
  if (head == NULL) {
    printf("List is empty\n");
  } else {
    NODE *temp = head;
    do {
      count_time += n;
      if (temp->time > n) {
        temp->time -= n;
        temp = temp->next;
      } else {
        printf("Process id: %d completed in %d ns\n", temp->processId, count_time);
        deleteNode(&temp);
      }
    } while (temp != NULL);
  }
}
