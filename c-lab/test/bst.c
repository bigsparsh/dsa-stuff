#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* left, *right;
} NODE;

void insert (NODE **, int);
void delete (NODE **, int);
void display (NODE *);

int main () {
  NODE *root = NULL;
  int choice, data;

  do {
    printf("\n===[B S T]===\n 1. Insert\n 2. Delete\n 3. Display\n 4. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf ("\nEnter a node to insert: ");
        scanf("%d", &data);
        insert (&root, data);
        break;
      case 2:
        printf ("\nEnter a node to delete: ");
        scanf("%d", &data);
        delete(&root, data);
        break;
      case 3:
        display(root);
        break;
      case 4:
        printf("...Exiting");
        break;
    }

  } while (choice != 4);

  return 0;
}

void insert (NODE **root, int data) {
  if (*root == NULL) {
    *root = (NODE *) malloc(sizeof(NODE));
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->data = data;
  } else {
    if ((*root)->data > data) 
      insert (&(*root)->left, data);
    if ((*root)->data < data)
      insert (&(*root)->right, data);
  }
}

void delete (NODE **root, int data) {
  if (*root == NULL) return;

  if (data < (*root)->data) 
    delete (&(*root)->left, data);
  else if (data > (*root)->data)
    delete (&(*root)->right, data);
  else {
    if ((*root)->left == NULL) {
      NODE *ptr = *root;
      (*root) = (*root)->right;
      free(ptr);
    } else if ((*root)->right == NULL) {
      NODE *ptr = *root;
      (*root) = (*root)->left;
      free(ptr);
    } else {
      NODE *ptr = ((*root)->right);
      while (ptr->left != NULL) ptr = ptr->left;
      (*root)->data = ptr->data;
      delete(&(*root)->right, ptr->data);
    }
  }
}

void display (NODE *root) {
  if (root != NULL) {
    display (root->left);
    printf(" [%d] ", root->data);
    display(root->right);
  }
}
