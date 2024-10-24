void insertBefore (NODE **head) {
  NODE *newNode = (NODE *) malloc(sizeof(NODE));
  printf("Enter the data for the node: ");
  scanf("%d", &newNode->data);
  newNode->next = *head;
  if (*head == NULL) { 
    *head = newNode->next = newNode;
  }
  else {
    NODE *tail = *head;
    while (tail->next != *head) tail = tail->next;
    newNode->next = *head;
    tail->next = newNode;
    *head = newNode;
  }
}

NODE* splitList (NODE *ptr, int key) {
  while (ptr->next->data != key) {
    ptr = ptr->next;
  }
  NODE *ptr2 = ptr->next;
  ptr->next = NULL;
  return ptr2;
}
