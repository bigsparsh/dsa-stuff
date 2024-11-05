#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left, *right;
} NODE;

void insert (NODE **, int);
void display (NODE *);
int countNode (NODE *);
int countLeafNode (NODE *);
int countOneNodeParents (NODE *);

int main () {
  NODE *root = NULL;
  insert (&root, 10);
  insert (&root, 20);
  insert (&root, 70);
  insert (&root, 50);
  insert (&root, 5);
  insert (&root, 100);

  display (root);
  printf("\nTotal number of nodes: %d", countNode (root));
  printf("\nTotal number of leaf nodes: %d", countLeafNode (root));
  printf("\nTotal number of nodes having one child: %d", countOneNodeParents (root));


  return 0;
}

void insert (NODE **root, int data) {
  if (*root == NULL) {
    *root = (NODE *) malloc(sizeof(NODE));
    (*root)->data = data;
    (*root)->right = NULL;
    (*root)->left = NULL;
  }
  if (data > (*root)->data) insert (&(*root)->right, data);
  if (data < (*root)->data) insert (&(*root)->left, data);
}

void display (NODE *root) {
  if (root != NULL) {
    display (root->left);
    printf(" [%d] ", root->data);
    display (root->right);
  }
}

int countNode (NODE *root) {
  static int count = 0;
  if (root != NULL) {
    countNode (root->left);
    count++;
    countNode (root->right);
  }
  return count;
}


int countLeafNode (NODE *root) {
  static int count = 0;
  if (root != NULL) {
    countLeafNode (root->left);
    if (root->left == NULL && root->right == NULL) count++;
    countLeafNode (root->right);
  }
  return count;
}


int countOneNodeParents (NODE *root) {
  static int count = 0;
  if (root != NULL) {
    countOneNodeParents (root->left);
    if ((root->left == NULL && root->right != NULL) || (root->right == NULL && root->left != NULL)) count++;
    countOneNodeParents (root->right);
  }
  return count;
}
