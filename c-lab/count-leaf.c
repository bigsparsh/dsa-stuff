#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NODE;

void insert (NODE **, int);
void display (NODE *);
int count_leaf_node (NODE *);
void delete (NODE **, int);

int main () {
  NODE *root = NULL;
  int choice, n;

  
  do {
    printf("\n\n===[BINARY SEARCH TREE]===\n 1. Insert\n 2. Count Leaf Nodes\n 3. Delete Nodes\n 4. Display\n 5. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf ("Enter your data: ");
        scanf("%d", &n);
        insert (&root, n);
        break;
      case 2:
        printf("\nThe total number of leaf nodes are: %d\n", count_leaf_node (root));
        break;
      case 3:
        printf ("Enter your data to delete: ");
        scanf("%d", &n);
        delete (&root, n);
        break;
      case 4:
        display (root);
    }

  } while (choice != 5);

  return 0;
}

int count_leaf_node (NODE *root) {
  if (root == NULL) return 0;
  if (root->left == NULL && root->right == NULL) return 1;
  return count_leaf_node(root->left) + count_leaf_node(root->right);
}

void display (NODE *rt) {
  if (rt != NULL) {
    display(rt->left);
    printf (" [%d] ", rt->data);
    display (rt->right);
  }
}

void insert (NODE **root, int data) {
  if (*root == NULL) {
    *root = (NODE *) malloc(sizeof(NODE));
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->data = data;
    return;
  }
  if ((*root)->data < data) {
    insert (&(*root)->right, data);
  } else {
    insert (&(*root)->left, data);
  }
}
 
void delete (NODE **root, int data) {
  if (*root == NULL) {
    printf ("\nThe root is empty, can't delete further.\n");
    return;
  }
  if ((*root)->data > data) {
    delete (&(*root)->left, data);
  } else if ((*root)->data < data) {
    delete (&(*root)->right, data);
  } else {
    if ((*root)->left == NULL) {
      NODE *temp = *root;
      *root = (*root)->right;
      free (temp);
    } else if ((*root)->right == NULL) {
      NODE *temp = *root;
      *root = (*root)->left;
      free (temp);
    } else {
      NODE *in = (*root)->right;
      while (in->left != NULL) in = in->left;
      (*root)->data = in->data;
      delete (&(*root)->right, in->data);
    }
  }
}
