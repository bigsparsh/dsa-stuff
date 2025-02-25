/*
 Name: Sparsh Singh
 University Roll No: 2024329
 Section: C

  Q2- Write a menu driven  program to delete duplicate name(if any) in the single Link list. The information  field of  each node should contain name and noll no of students. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of a node
typedef struct node {
    char name[50];
    int roll;
    struct node *next;
} NODE;

// Function prototypes
void insert (NODE **);
void display (NODE *);
NODE* deleteDuplicate (NODE *, NODE **);

int main() {
    NODE *head = NULL, *tail = NULL;
    int choice;

    // Menu driven program
    while (1) {
        printf("1. Insert\n2. Display\n3. Delete Duplicate\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Insert a new node
                insert(&tail);
                if (head == NULL) head = tail;
                break;
            case 2:
                // Display the list
                display(head);
                break;
            case 3:
                // Delete duplicate nodes
                head = deleteDuplicate(head, &tail);
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

// Function to delete duplicate nodes
NODE *deleteDuplicate (NODE *head, NODE **tail) {
  NODE *current = head, *temp;

  // Traverse the list and delete duplicate nodes if found 
  while (current != NULL) {
    temp = current;
    while (temp->next != NULL) {
      if (strcmp (current->name, temp->next->name) == 0) {
        NODE *duplicate = temp->next;
        temp->next = temp->next->next;
        free (duplicate);
        if (temp->next == NULL) *tail = temp;
      } else temp = temp->next;
    }
    current = current->next;
  }
  return head;
}

// Function to insert a new node
void insert (NODE **tail) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    printf("Enter the name: ");
    scanf("%s", newNode->name);
    printf("Enter the roll: ");
    scanf("%d", &newNode->roll);
    newNode->next = NULL;
    
    // Insert the new node at the end of the list
    if (*tail != NULL) (*tail)->next = newNode;
    *tail = newNode;
}

// Function to display the list
void display (NODE *head) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        NODE *temp = head;
        while (temp != NULL) {
            printf("Name: %s, Roll: %d\n", temp->name, temp->roll);
            temp = temp->next;
        }
    }
}


