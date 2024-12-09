// W.A.P. to create a binary search tree and perform the following operations:
//          1) Find a node with second highest data. 
//          2) Delete a node from the tree.
//          3) Count total number of nodes having common parent. 
//          4) Find the height of a binary search tree
//          5) Count total numbers of nodes from left hand side of the root node

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}NODE;

void insert (NODE **, int);
void display (NODE *);
int findSecondHighest (NODE *);
NODE * deleteNode (NODE *, int);
int countCommonParent (NODE *);
int findHeight (NODE *);
int countLeftNodes (NODE *);

int main() {
  NODE *root = NULL;
  int choice, data;

  while (1) {
    printf("1. Insert\n2. Display\n3. Find second highest\n4. Delete node\n5. Count common parent\n6. Find height\n7. Count left nodes\n8. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data: ");
        scanf("%d", &data);
        insert(&root, data);
        break;
      case 2:
        display(root);
        break;
      case 3:
        printf("Second highest: %d\n", findSecondHighest(root));
        break;
      case 4:
        printf("Enter data to delete: ");
        scanf("%d", &data);
        root = deleteNode(root, data);
        break;
      case 5:
        printf("Common parent count: %d\n", countCommonParent(root));
        break;
      case 6:
        printf("Height: %d\n", findHeight(root));
        break;
      case 7:
        printf("Left nodes count: %d\n", countLeftNodes(root));
        break;
      case 8:
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}

void insert (NODE **root, int data) {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  if (*root == NULL) {
    *root = newNode;
    return;
  }

  NODE *temp = *root;
  while (1) {
    if (data < temp->data) {
      if (temp->left == NULL) {
        temp->left = newNode;
        return;
      }
      temp = temp->left;
    } else {
      if (temp->right == NULL) {
        temp->right = newNode;
        return;
      }
      temp = temp->right;
    }
  }
}

void display (NODE *root) {
  if (root == NULL) {
    printf("Tree is empty\n");
    return;
  }

  if (root->left != NULL) {
    display(root->left);
  }

  printf("%d ", root->data);

  if (root->right != NULL) {
    display(root->right);
  }
}

int findSecondHighest (NODE *root) {
    if (root == NULL) return -1;
    while (root->right->right != NULL) root = root->right;
    return root->data;
}

NODE * deleteNode (NODE *root, int data) {
  if (root == NULL) return NULL;

  if (data < root->data) {
    root->left = deleteNode(root->left, data);
  } else if (data > root->data) {
    root->right = deleteNode(root->right, data);
  } else {
    if (root->left == NULL) {
      NODE *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      NODE *temp = root->left;
      free(root);
      return temp;
    }

    NODE *temp = root->right;
    while (temp->left != NULL) temp = temp->left;

    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }

  return root;
}

int countCommonParent (NODE *root) {
  if (root == NULL) return 0;

  if (root->left != NULL && root->right != NULL) 
    return 1 + countCommonParent(root->left) + countCommonParent(root->right);

  return countCommonParent(root->left) + countCommonParent(root->right);
}

int findHeight (NODE *root) {
  if (root == NULL) return 0;

  int leftHeight = findHeight(root->left);
  int rightHeight = findHeight(root->right);

  return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int countLeftNodes (NODE *root) {
  if (root == NULL) return 0;
  return 1 + countLeftNodes(root->left);
}

