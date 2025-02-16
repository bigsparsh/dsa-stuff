#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int vertex;
  struct node *next;
} Node;

typedef struct graph {
  Node **adj_list;
  int vtx_count;
  int is_directed;
} Graph;

Node* create_node (int);
void create_edge (Graph *, int , int);
Graph* create_graph (int, int);
void display (Graph *);
void dfs (Graph *, int, int *);
void bfs (Graph *, int, int *);

int main () {
  int vtx_count, is_directed, *visited;
  printf ("How many nodes in graph you want?: ");
  scanf ("%d", &vtx_count);

  printf ("Is your graph directed?: ");
  scanf ("%d", &is_directed);

  Graph *graph = create_graph (vtx_count, is_directed);
  int choice, src, dest;

  do {
    printf ("===[GRAPH]===\n 1. Insert edge\n 2. Display\n 3. BFS\n 4. DFS\n 5. exit\n Enter your choice: ");
    scanf ("%d", &choice);

    switch (choice) {
      case 1:
        printf ("Enter the source: ");
        scanf ("%d", &src);
        printf ("Enter the destination: ");
        scanf ("%d", &dest);
        create_edge(graph, src, dest);
        break;
      case 2:
        display (graph);
        break;
      case 3:
        visited = (int *) malloc(vtx_count * sizeof(int));
        printf ("Enter the source: ");
        scanf ("%d", &src);
        bfs (graph, src, visited);
        break;
      case 4:
        visited = (int *) malloc(vtx_count * sizeof(int));
        printf ("Enter the source: ");
        scanf ("%d", &src);
        dfs (graph, src, visited);
        break;
      case 5:
        printf ("Exiting....");
        break;
    }
  } while (choice != 5);

  return 0;
}

Graph* create_graph (int vtx_count, int is_directed) {
  Graph *newGraph = (Graph *) malloc(sizeof(Graph));
  newGraph->vtx_count = vtx_count;
  newGraph->is_directed = is_directed;
  newGraph->adj_list = (Node **) malloc(vtx_count * sizeof(Node *));
  for (int i = 0; i < vtx_count; i++) newGraph->adj_list[i] = NULL;
  return newGraph;
}

Node* create_node (int data) {
  Node *newNode = (Node *) malloc(sizeof(Node));
  newNode->next = NULL;
  newNode->vertex = data;
  return newNode;
}

void create_edge (Graph *grp, int src, int dest) {
  Node *newNode = create_node (dest);
  newNode->next = grp->adj_list[src];
  grp->adj_list[src] = newNode;

  if (grp->is_directed == 0) {
    newNode = create_node(src);
    newNode->next = grp->adj_list[dest];
    grp->adj_list[dest] = newNode;
  }
}

void display (Graph *grp) {
  Node *curr_node = NULL;
  for (int i = 0; i < grp->vtx_count; i++) {
    curr_node = grp->adj_list[i];
    while (curr_node != NULL) {
      if (curr_node != NULL) 
        printf(" %d ->", curr_node->vertex);
      curr_node = curr_node->next;
    }
    printf(" NULL\n");
  }
}

void bfs (Graph *grp, int src, int *visited) {
  int queue[grp->vtx_count];
  int front = 0, rear = 0;
  Node *curr_node = NULL;

  visited[src] =  1;
  queue[rear++] = src;

  while (front < rear) {
    src = queue[front++];
    printf (" %d ->", src);
    curr_node = grp->adj_list[src];
    while (curr_node != NULL) {
      if (visited[curr_node->vertex] == 0) {
        queue[rear++] = curr_node->vertex;
        visited[curr_node->vertex] = 1;
      }
      curr_node = curr_node->next;
    }
  }
}

void dfs (Graph *grp, int src, int *visited) {
  Node *curr_node = NULL;
  if (visited[src] == 0) {
    visited[src] = 1;
    printf (" %d ->", src);
    curr_node = grp->adj_list[src];
    while (curr_node != NULL) {
      if (visited[curr_node->vertex] == 0) 
        dfs (grp, curr_node->vertex, visited);
      curr_node = curr_node->next;
    }
  }
}
