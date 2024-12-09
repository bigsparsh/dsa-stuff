#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int vertex;
  struct node* next;
}Node; 

typedef struct graph {
  int vtx_count;
  Node **adj_list;
  int is_directed;
} Graph;

Node* create_node (int);
Graph* create_graph (int, int);
void create_edge (Graph *, int, int);
void display (Graph *);
void dfs (Graph *, int, int *);
void bfs (Graph *, int, int *);

int main () {
  int vtx, *visited = NULL, directed;
  printf ("How many vertices would you like?: ");
  scanf("%d", &vtx);
  printf("Is this graph directed ?: ");
  scanf("%d", &directed);
  Graph *graph = create_graph(vtx, directed); 

  int choice, src, dest;
  do {
    printf ("\n===[GRAPH]===\n 1. Create Edge\n 2. Display graph\n 3. DFS\n 4. BFS\n 5. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter your source: ");
        scanf("%d", &src);
        printf("Enter your destination: ");
        scanf("%d", &dest);
        if (src >= graph->vtx_count || dest >= graph->vtx_count || src == dest) {
          printf("Either source or destination is invalid\n");
          break;
        }
        create_edge (graph, src, dest);
        break;
      case 2:
        display (graph);
        break;
      case 3:
        visited = (int *) malloc(vtx * sizeof(int));
        for (int i = 0 ; i < vtx; i++) visited[i] = 0;
        printf("Enter your source: ");
        scanf("%d", &src);
        dfs (graph, src, visited);
        printf(" NULL\n");
        break;
      case 4:
        visited = (int *) malloc(vtx * sizeof(int));
        for (int i = 0 ; i < vtx; i++) visited[i] = 0;
        printf("Enter your source: ");
        scanf("%d", &src);
        bfs (graph, src, visited);
        printf(" NULL\n");
        break;
    }
  } while (choice != 5);
}

void bfs (Graph *grp, int src, int *visited) {
  int queue[grp->vtx_count];
  int front = 0, rear = 0;
  queue[rear++] = src;
  visited[src] = 1;
  Node *curr_node;
  while (front < rear) {
    src = queue[front];
    printf(" %d ->", src);
    front++;
    curr_node = grp->adj_list[src];
    while (curr_node) {
      if (!visited[curr_node->vertex]) {
        queue[rear] = curr_node->vertex;
        rear++;
        visited[curr_node->vertex] = 1;
      }
      curr_node = curr_node->next;
    }
  }
}

void dfs (Graph *grp, int src, int *visited) {
  if (visited[src] == 0) {
    visited[src] = 1;
    printf(" %d ->", src);
    Node *curr_node = grp->adj_list[src];
    while (curr_node != NULL) {
      if (visited[curr_node->vertex] == 0)
        dfs (grp, curr_node->vertex, visited);
      curr_node = curr_node->next;
    }
  }
}

void create_edge (Graph *grp, int src, int dest) {
  Node *newNode = create_node (dest);
  newNode->next = grp->adj_list[src];
  grp->adj_list[src] = newNode;

  if (!grp->is_directed) {
    newNode = create_node (src);
    newNode->next = grp->adj_list[dest];
    grp->adj_list[dest] = newNode;
  }

}

void display (Graph *grp) {
  for (int i = 0; i < grp->vtx_count; i++) {
    Node *curr_node = grp->adj_list[i];
    while (curr_node != NULL) {
      printf(" [%d] ->", curr_node->vertex);
      curr_node = curr_node->next;
    }
    printf (" NULL\n");
  }
}

Node* create_node (int data) {
  Node *newNode = (Node *) malloc(sizeof(Node));
  newNode->vertex = data;
  newNode->next = NULL;
  return newNode;
}

Graph* create_graph (int vtx_count, int directed) {
  Graph *graph = (Graph *) malloc(sizeof(Graph)); 
  graph->vtx_count = vtx_count;
  graph->adj_list = (Node **) malloc(vtx_count * sizeof(Node *));
  graph->is_directed = directed;

  for (int i = 0; i < vtx_count; i++)
    graph->adj_list[i] = NULL;

  return graph;
}
