#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 10

typedef struct vertex {
  int data;
  int visited;
} Vtx;

typedef struct graph {
  int vertex_count;
  Vtx *vertices;
  int **adj_matrix;
} Graph;

void add_vertex(Graph *);
void add_edge(Graph *);
void display(Graph *);
void dfs(Graph *);
void bfs(Graph *);

int main() {
  Graph g;
  int choice;
  g.vertex_count = 0;
  g.vertices = (Vtx *)malloc(MAX_VERTICES * sizeof(Vtx));
  g.adj_matrix = (int **)malloc(MAX_VERTICES * sizeof(int *));
  for (int i = 0; i < MAX_VERTICES; i++)
    g.adj_matrix[i] = (int *)malloc(MAX_VERTICES * sizeof(int));

  do {
    printf("1. Add vertex\n");
    printf("2. Add edge\n");
    printf("3. Display\n");
    printf("4. DFS\n");
    printf("5. BFS\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      add_vertex(&g);
      break;
    case 2:
      add_edge(&g);
      break;
    case 3:
      display(&g);
      break;
    case 4:
      dfs(&g);
      break;
    case 5:
      bfs(&g);
      break;
    case 6:
      exit(0);
    default:
      printf("Invalid choice.\n");
    }
  } while (1);
}

void dfs(Graph *grp) {
}

void add_vertex(Graph *grp) {
  if (grp->vertex_count == MAX_VERTICES) {
    printf("Maximum number of vertices reached.\n");
    return;
  }
  Vtx *vtx = (Vtx *)malloc(sizeof(Vtx));
  printf("Enter the data for the vertex: ");
  scanf("%d", &vtx->data);

  grp->vertices[grp->vertex_count++] = *vtx;
}

void add_edge(Graph *grp) {
  int src, dest;
  printf("Enter the source vertex: ");
  scanf("%d", &src);
  printf("Enter the destination vertex: ");
  scanf("%d", &dest);

  if (src > grp->vertex_count || dest > grp->vertex_count) {
    printf("Invalid source or destination vertex.\n");
    return;
  }

  grp->adj_matrix[src][dest] = 1;
  grp->adj_matrix[dest][src] = 1;
}

void display(Graph *grp) {
  printf("Vertices: ");
  for (int i = 0; i < grp->vertex_count; i++) {
    printf("%d ", grp->vertices[i].data);
  }
  printf("\n");

  printf("Adjacency Matrix:\n");
  for (int i = 0; i < grp->vertex_count; i++) {
    for (int j = 0; j < grp->vertex_count; j++) {
      printf("%d ", grp->adj_matrix[i][j]);
    }
    printf("\n");
  }
}
