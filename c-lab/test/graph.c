#include <stdio.h>
#include <stdlib.h>

typedef struct vertex{
  int data;
  struct vertex *next;
} Vertex ;

typedef struct graph {
  int vtx_count;
  int is_directed;
  struct vertex **adj_list;
} Graph;

Graph* create_graph (int, int);
void create_edge (Graph *, int, int);
void display (Graph *);
void dfs (Graph *, int, int, int *);
void bfs (Graph *, int, int, int *);

int main () {
  int vtx_count, is_directed, *visited;
  printf("Enter the number of vertices in the graph: ");
  scanf("%d", &vtx_count);

  printf("Is the graph directed? (Yes - 1 / No - 0): ");
  scanf("%d", &is_directed);

  Graph *graph = create_graph(vtx_count, is_directed);
  int choice, source, destination;

  do {
    printf ("===[GRAPH]===\n 1. Create Edge\n 2. Display\n 3. DFS\n 4. BFS\n 5. Exit\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter the source: ");
        scanf("%d", &source);
        printf("Enter the destination: ");
        scanf("%d", &destination);
        create_edge (graph, source, destination);
        break;
      case 2:
        display (graph);
        break;
      case 3:
        visited = (int *) malloc(sizeof(int));
        printf("Enter the source: ");
        scanf("%d", &source);
        printf("Enter the destination: ");
        scanf("%d", &destination);
        dfs (graph, source, destination, visited);
        printf("NULL\n");
        free(visited);
        visited = NULL;
        break;
      case 4: 
        visited = (int *) malloc(sizeof(int));
        printf("Enter the source: ");
        scanf("%d", &source);
        printf("Enter the destination: ");
        scanf("%d", &destination);
        bfs (graph, source, destination, visited);
        printf("NULL\n");
        free(visited);
        visited = NULL;
        break;
      case 5:
        printf("Exiting...");
        break;

    }
  } while (choice != 5);
}

Graph* create_graph (int vtx_count, int is_directed) {
  Graph *newGraph = (Graph *) malloc(sizeof(Graph));
  newGraph->vtx_count = vtx_count;
  newGraph->is_directed = is_directed;
  newGraph->adj_list = (Vertex **) malloc(vtx_count * sizeof(Vertex*));

  for (int i = 0; i < vtx_count; i++)
    newGraph->adj_list[i] = NULL;

  return newGraph;
}

void display (Graph *grp) {
  for (int i = 0; i < grp->vtx_count; i++) {
    printf(" [%d] || ", i);
    Vertex *ptr = grp->adj_list[i];
    while (ptr != NULL) {
      printf(" %d -> ", ptr->data);
      ptr = ptr->next;
    }
    printf("NULL\n");
  }
}

Vertex* create_node (int data) {
  Vertex *newNode = (Vertex *) malloc(sizeof(Vertex));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void create_edge (Graph *grp, int src, int dest) {
  Vertex *newNode = create_node(dest);
  newNode->next = grp->adj_list[src];
  grp->adj_list[src] = newNode;
  
  if (grp->is_directed) {
    newNode = create_node(src);
    newNode->next = grp->adj_list[dest];
    grp->adj_list[dest] = newNode;
  }
}

void dfs (Graph *grp, int src, int dest, int *visited) {
  if (visited[src] == 0) {
    visited[src] = 1;
    printf(" [%d] -> ", src);
    Vertex *ptr = grp->adj_list[src];
    while (ptr != NULL) {
      src = ptr->data;
      dfs (grp, src, dest, visited);
      ptr = ptr->next;
    }
  }
}

void bfs (Graph *grp, int src, int dest, int *visited) {
  int queue[grp->vtx_count];
  int front = 0, rear = 0;
  visited[src] = 1;
  queue[rear++] = src;
  while (front < rear) {
    src = queue[front++];
    printf(" %d -> ", src);
    Vertex *ptr = grp->adj_list[src];
    while (ptr != NULL) {
      if (visited[ptr->data] == 0) {
        queue[rear++] = ptr->data;
        visited[ptr->data] = 1;
      }
      ptr = ptr->next;
    }
  }
}

