/*
 Name: Sparsh Singh
 University Roll No: 2024329
 Section: C
  
  Q6- W.A.P. to create a binary search tree and perform the following operations:
       1) Find a node with second highest data. 
       2) Delete a node from the tree.
       3) Count total number of nodes having common parent. 
       4) Find the height of a binary search tree
       5) Count total numbers of nodes from left hand side of the root node
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}NODE;

// Function prototypes
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

  // Menu driven program
  while (1) {
    printf("1. Insert\n2. Display\n3. Find second highest\n4. Delete node\n5. Count common parent\n6. Find height\n7. Count left nodes\n8. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // Insert a node in the tree
        printf("Enter data: ");
        scanf("%d", &data);
        insert(&root, data);
        break;
      case 2:
        // Display the tree
        display(root);
        break;
      case 3:
        // Find the node with second highest data
        printf("Second highest: %d\n", findSecondHighest(root));
        break;
      case 4:
        // Delete a node from the tree
        printf("Enter data to delete: ");
        scanf("%d", &data);
        root = deleteNode(root, data);
        break;
      case 5:
        // Count total number of nodes having common parent
        printf("Common parent count: %d\n", countCommonParent(root));
        break;
      case 6:
        // Find the height of the tree
        printf("Height: %d\n", findHeight(root));
        break;
      case 7:
        // Count total numbers of nodes from left hand side of the root node
        printf("Left nodes count: %d\n", countLeftNodes(root));
        break;
      case 8:
        // Exit the program
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}

// Insert a node in the tree
void insert (NODE **root, int data) {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  // If the tree is empty then root will point to the new node
  if (*root == NULL) {
    *root = newNode;
    return;
  }

  // Traverse the tree to find the correct position to insert the new node
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

// Display the tree
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

// Find the node with second highest data
int findSecondHighest (NODE *root) {
    if (root == NULL) {
        return -1;
    }

    NODE *temp = root;
    // Traverse the tree to find the node with highest data
    while (temp->right->right != NULL) {
        temp = temp->right;
    }

    return temp->data;
}

// Delete a node from the tree
NODE * deleteNode (NODE *root, int data) {
  if (root == NULL) {
    return NULL;
  }

  if (data < root->data) {
    // Traverse the left subtree
    root->left = deleteNode(root->left, data);
  } else if (data > root->data) {
    // Traverse the right subtree
    root->right = deleteNode(root->right, data);
  } else {
    // If the node has only one child or no child then delete the node and return the child node if any else return NULL 
    if (root->left == NULL) {
      NODE *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      NODE *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children then find the inorder successor of the node
    NODE *temp = root->right;
    while (temp->left != NULL) temp = temp->left;

    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }

  return root;
}

// Count total number of nodes having common parent
int countCommonParent (NODE *root) {
  if (root == NULL) {
    return 0;
  }

  // If the node has both left and right child then it has a common parent
  if (root->left != NULL && root->right != NULL) {
    return 1 + countCommonParent(root->left) + countCommonParent(root->right);
  }

  return countCommonParent(root->left) + countCommonParent(root->right);
}

// Find the height of the tree
int findHeight (NODE *root) {
  if (root == NULL) {
    return 0;
  }

  // Find the height of the left and right subtree
  int leftHeight = findHeight(root->left);
  int rightHeight = findHeight(root->right);

  return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Count total numbers of nodes from left hand side of the root node
int countLeftNodes (NODE *root) {
  if (root == NULL) {
    return 0;
  }

  // Count the left nodes of the root node
  return 1 + countLeftNodes(root->left);
}

