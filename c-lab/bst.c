#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *rightNode, *leftNode;
}NODE;

void insert (NODE **, int);
void infixDisplay (NODE *root);
void postfixDisplay (NODE *root);
void prefixDisplay (NODE *root);

int main () {

  NODE *root = NULL;
  insert (&root, 23);
  insert (&root, 49);
  insert (&root, 10);
  insert (&root, 100);
  insert (&root, 20);
  insert (&root, 200);
  infixDisplay (root);
  printf("\n");
  postfixDisplay (root);
  printf("\n");
  prefixDisplay (root);

}

void insert (NODE **root, int val) {
  if (*root == NULL) {
    *root = (NODE *) malloc(sizeof(NODE));
    (*root)->data = val;
    (*root)->leftNode = NULL;
    (*root)->rightNode = NULL;
  }
  if (val < (*root)->data) 
    insert (&(*root)->leftNode, val);
  if (val > (*root)->data) 
    insert (&(*root)->rightNode, val);
}

void infixDisplay (NODE *root) {
  if (root != NULL) {
    infixDisplay(root->leftNode);
    printf(" [%d] ", root->data);
    infixDisplay(root->rightNode);
  }
}

void postfixDisplay (NODE *root) {
  if (root != NULL) {
    printf(" [%d] ", root->data);
    postfixDisplay(root->leftNode);
    postfixDisplay(root->rightNode);
  }
}
void prefixDisplay (NODE *root) {
  if (root != NULL) {
    prefixDisplay(root->leftNode);
    prefixDisplay(root->rightNode);
    printf(" [%d] ", root->data);
  }
}
