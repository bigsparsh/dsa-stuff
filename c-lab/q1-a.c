void displayReverse (NODE *ptr) { 
  if (ptr != NULL) {
    displayReverse(prt->next);
    printf("%d ", ptr->data);
  }
}
