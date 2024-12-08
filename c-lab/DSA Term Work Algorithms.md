# 1- Write a menu driven program to reverse a single linked list in O(N) time with a non-recursive function.

```c
NODE *reverse (NODE *head) {
  NODE *prev = NULL, *current = head, *next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}
```

### Algorithm

1. Start
2. We get the head of the linked list as argument to the function (say head).
3. Now we initialize three pointers of node type of the linked list and set one of them to the head and the rest to NULL. (say current = head, next = prev = NULL)
4. Now iterate over following steps until the current pointer becomes null.
   - Set the next to current's next.
   - Set current's next to prev.
   - Set prev to current.
   - Set current to next.
5. After that return prev as the head of the reversed linked list.

# 2- Write a menu driven program to delete duplicate name(if any) in the single Link list. The information field of each node should contain name and roll no of students.

```c
NODE *deleteDuplicate (NODE *head, NODE **tail) {
  NODE *current = head, *temp;
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
```

### Algorithm

1. Start
2. We get the pointer pointing to the first node and double pointer pointing to the end of the linked list as arguments.
3. We initialize two pointers of the linked list node type and set one of them to head and other to NULL. (say, current = head, temp = NULL)
4. After that we iterate through following steps until the current becomes NULL.
   - Set the temp equal to current.
   - Now iterate through following steps until temp's next becomes NULL.
     1. If the current's name and temp's next node's name are equal then create a temporary pointer and set it the the temp's next after that set the temp's next to the temp's next of the next node, and then finally free the temporary node. Also if the node next to temp is found to be NULL then then set the tail to be temp. Otherwise set temp to point to it's next node.
   - Set current to point to it's next node.
5. Now return the head.
6. Stop.

# 3- Write a C program to find and delete the node with second minimum data in the single link list.

```c
NODE *deleteSecondMin (NODE *head, NODE **tail) {
  if (head == NULL) return NULL;
  if (head->next == NULL) {
    free (head);
    return NULL;
  }

  int min = head->data, secondMin = head->next->data;
  NODE *temp = head;

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


```

### Algorithm

1. Start
2. We get the pointer to the node containing the first node and double pointer to the node containing the last node in the linked list. (say head and tail)
3. Now if head is NULL then return NULL because there is nothing to delete in that case.
4. If head's next node is NULL then free the head and return NULL deleting the singular node.
5. Now initialize two integer variables set one to head's data and other to the head next's data, also initialize a pointer of linked list node type to NULL. say (min, secondMin and temp)
6. Iterate over the following steps until temp becomes NULL.
   - If temp's data is less than min then set secondMin to min and set min to the temp's data .
   - Otherwise if temp's data is less than secondMin and is not equal to min then set secondMin to temp's data.
   - Now point the temp to it's next node.
7. Now if secondMin is equal to the head's data then save the head in a temp pointer then point head to it's next node, after that free the temp pointer.
8. Otherwise iterate over the following steps
   - If temp next node's data is equal to secondMin then make a linked list node pointer (say del) and save the temp's next node and then set temp's next to the next's next node and if del is equal to the tail then set the tail to temp, then at last free del. Then Break out of the loop
   - Set temp to it's next node.
9. Return head.
10. Stop

# 4- Write a C program to create a single linked list, then find whether there exist any two nodes in the linked list whose multiplication is less than the target value.

#### Example:

Input:  Linked-List =  12->15->3->4->6, Target = 20
Output: Yes

```c
int isProductLessThanTarget (NODE *head, int target) {
  NODE *current = head;
  while (current != NULL) {
    NODE *next = current->next;
    while (next != NULL) {
      if (current->data * next->data < target) {
        return 1;
      }
      next = next->next;
    }
    current = current->next;
  }
  return 0;
}
```

### Algorithm

1. Start
2. We get the head as the pointer to the first node of the linked list and an integer which is the target. (say, head and target).
3. Initialize a linked list node pointer pointing to the head. (say, current)
4. Iterate over the following steps until current is NULL.
   - Make a linked list node pointer pointing to the current's next node. (say, next)
   - Now iterate over the following steps until next becomes NULL.
     1. if current's data multiplied by next's next is less target then return 1 indicating that the target was met and in main function print "YES".
     2. Set the next to it's next node.
   - Set current to it's next node.
5. Return 0 indicating that target was not met and in main function print "NO".
6. Stop

# 5- Write a C program to find the node in the double linked list, at which the two linked list are intersected.

```c
void findIntersection (NODE *head1, NODE *head2) {
  NODE *h1 = head1, *h2 = head2;
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
```

### Algorithm

1. Start
2. We get the pointers pointing to the first node of two linked list each. (say, head1, head2).
3. We initialize two linked list node pointers with head1 and head2. (say, h1 and h2).
4. The iterate until h1 becomes null and execute below sub steps in each iteration.
   - Set h2 to head2.
   - Iterate the following statements until h2 becomes null.
     1. If h1's data is equal to h2's data then return as the intersection is found also print the intersection node's data.
     2. Set h2 to point to it's next node.
   - Set h1 to point to it's next node.
5. If no intersection is found then print a statement stating that.
6. Stop

# 6- W.A.P. to create a binary search tree and perform the following operations:

1. Find a node with second highest data.
2. Delete a node from the tree.
3. Count total number of nodes having common parent.
4. Find the height of a binary search tree
5. Count total numbers of nodes from left hand side of the root node

```c -1
int findSecondHighest (NODE *root) {
    if (root == NULL) {
        return -1;
    }

    NODE *temp = root;
    while (temp->right->right != NULL) {
        temp = temp->right;
    }

    return temp->data;
}
```

### 1) Algorithm

1. Start
2. We get the pointer pointing to the root of the BST as argument. (say, root).
3. If root is NULL then return -1 indicating that the value was not found.
4. Initialize a BST node pointer pointing to the root. (say, temp).
5. Iterate over the following sub steps until the temp's right's right becomes NULL.
   - Set the temp to point to it's next node.
6. Return temp's data
7. Stop

```c
NODE* deleteNode (NODE *root, int data) {
    if (root == NULL) {
        return root;
    }

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
        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}
```

### 2) Algorithm

1. Start
2. We get the pointer pointing to the root node of the tree and an integer which is to be deleted. (say, root and data).
3. If root is null then return it.
4. If data is less than the root's data then set the root's left equal to the result of recursive call while passing in the root's left data and the data.
5. Otherwise If data is greater than the root's data then set root's right equal to the result of recursive call while passing in the root's right node and the data.
6. Otherwise if the data is equal to the root's data then check the following.
   - If root's left node is found to be null then free the current root and return root's right.
   - Otherwise if the root's right is found to be null then free the current root and return root's left.
   - Now after that iterate until the leftmost node is found from the right of the current node then set the data of that right node to the data of the current root right's data then set the root's right to be the result of the recursive call where we pass in the root's right and it's data.
7. Return the root node.
8. Stop

```c
int countCommonParent (NODE *root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left != NULL && root->right != NULL) {
        return 1 + countCommonParent(root->left) + countCommonParent(root->right);
    }

    return countCommonParent(root->left) + countCommonParent(root->right);
}
```

### 3) Algorithm

1. Start
2. We get the pointer pointing to the root of the tree. (say, root).
3. If root is null then we return 0.
4. If root's left is null and root's right is also null then we return one added to a binary recursion addition where one call has the root's left and other has the root's right.
5. Otherwise we return the addition of two recursion calls where one has the root's left and other has the root's right as the arguments.
6. Stop.

```c
int findHeight (NODE *root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}
```

### 4) Algorithm

1. Start
2. We get the pointer pointing to the root of the tree. (say, root).
3. If the root is null then we return 0.
4. We get the left sub-tree height in a integer variable by recursively calling the function while passing root's left as the argument, do the same for the right sub-tree and pass in the root's right instead.
5. Now return left's height added by 1 if left height is less than the right height otherwise return 1 added by right's height.
6. Stop

```c
int countLeftNodes (NODE *root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + countLeftNodes(root->left);
}
```

### 5) Algorithm

1. Start
2. We get the pointer pointing to the root of the tree. (say, root).
3. If the root is null then return 0.
4. Otherwise return 1 added by the recursive call to the function while passing in the root's left node.
5. Stop.

# 7- Write a C program to sort N names given by user in an array, using Quick sort technique.

```c
void quickSort (char **names, int low, int high) {
    if (low < high) {
        int pi = partition(names, low, high);
        quickSort(names, low, pi - 1);
        quickSort(names, pi + 1, high);
    }
}

int partition (char **names, int low, int high) {
    char *pivot = names[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(names[j], pivot) < 0) {
            i++;
            char *temp = names[i];
            names[i] = names[j];
            names[j] = temp;
        }
    }

    char *temp = names[i + 1];
    names[i + 1] = names[high];
    names[high] = temp;

    return i + 1;
}
```

### Algorithm for the Quick Sort function

1. Start
2. We get the names and low and high as arguments.
3. if low is less than the high then execute the following steps.
   - Call the partition function with the names, low and high passed as argument.
   - Now do a binary recursive call where the first call takes in names, low and then the result of the above partition call - 1 while the second call takes the names, partition + 1 and high.
4. Stop

### Algorithm for the Partition function

1. Start
2. We get the names, low and high as the arguments.
3. We initialize a pivot which is set to the high index of the names array, also initialize an integer with low - 1. (say pivot and i).
4. Iterate over the following sub steps until a temporary value (initially 0) becomes less than high after incrementing it at each iteration. (say, j).
   - If names j index is equal to the pivot then we increment i, the swap the names i with names j.
5. Swap the names i+1 with names high
6. Return i + 1.

# 8- Write a C program to implement time sharing environment using circular linked list to allocate time slots of 10ns for N given processes, and then print which process will be completed in how much time.

```c
void allocateTime (NODE *head, int n) {
  int count_time = 0;
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
```

### Algorithm

1. Start
2. We get the pointer pointing to the head of the linked list as the argument.
3. Initialize an integer to keep track of the time and set it to 0. (say, count_time).
4. If head is null then list is empty and stop.
5. Otherwise initialize a temporary pointer of linked list node type and set it to the head.
6. Execute following statements in iterative manner until temp becomes null.
   - Increment the count_time by 10.
   - If temp's time is greater than 10 then decrement that time from the temp's time then set temp to it's next node, otherwise print process id and the time taken to execute this process, then delete that node.
7. Stop

# 9- Write a C program to store the details of a weighted graph.

```c
void create_edge (Vertex **head, int src, int dest, int weight) {
  Vertex *src_vertex = *head;
  Vertex *dest_vertex = *head;

  while (src_vertex != NULL && src_vertex->data != src) {
    src_vertex = src_vertex->next;
  }

  while (dest_vertex != NULL && dest_vertex->data != dest) {
    dest_vertex = dest_vertex->next;
  }

  if (src_vertex == NULL || dest_vertex == NULL) {
    printf("Invalid source or destination vertex\n");
    return;
  }

  Edge *new_edge = (Edge *) malloc(sizeof(Edge));
  new_edge->weight = weight;
  new_edge->dest = dest_vertex;
  new_edge->next = NULL;

  if (src_vertex->edge == NULL) {
    src_vertex->edge = new_edge;
  } else {
    Edge *temp = src_vertex->edge;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_edge;
  }
}
```

### Algorithm

1. Stop
2. We get the double pointer pointing to the first vertex of the graph, a source, a destination and weight. (say head, src, dest and weight)
3. Get the source vertex by iterating over all the vertices of the graph, then do the same for the destination vertex.
4. Now check if either destination or source vertex is null, if true then the source or destination is invalid so return.
5. Otherwise create a new Edge and set the weight, destination and set the next to be null.
6. If source vertex's edge is null then set it to the newly created edge, else add the edge to head of the edge list.
7. Stop.

# 10- Write a C program to implement DFS and BFS

```c
void dfs (Vertex *head) {
  if (head == NULL) {
    return;
  }

  head->visited = 1;
  printf("%d ", head->data);

  Edge *edge = head->edge;
  while (edge != NULL) {
    if (edge->dest->visited == 0) {
      dfs(edge->dest);
    }
    edge = edge->next;
  }
}
```

### Algorithm

1. Start
2. We get the pointer that points to the starting node of the graph as argument. (say, head).
3. If head is null then return.
4. Otherwise set the head visited to 1 then print the head's data.
5. Then iterate over the edges of head and if their destination is visited then call the function recursively while passing in the destination.
6. Stop

```c

```
