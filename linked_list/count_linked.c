void display (node* top) {
  node* next = top->next;
  if (head != NULL) {
    display (next);
    printf ("%d\n", top->data);
  }
}
