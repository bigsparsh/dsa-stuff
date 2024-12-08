#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int vertex, weight;
  struct node *next;
} node;

typedef struct graph {
  struct node **lists;
} graph;

graph *create_graph(int num) {
  graph *gr = (graph *)malloc(sizeof(graph));
  gr->lists = (node **)malloc(num * sizeof(node *));
  for (int i = 0; i < num; i++) {
    gr->lists[i] = NULL;
  }
  return gr;
}

node *create_node(int vertex, int weight) {
  node *newNode = (node *)malloc(sizeof(node));
  newNode->vertex = vertex;
  newNode->weight = weight;
  newNode->next = NULL;
  return newNode;
}

void addEdge(graph *gr, int src, int dst, int wt) {
  node *newNode = create_node(dst, wt);
  newNode->next = gr->lists[src];
  gr->lists[src] = newNode;

  // Add edge from dst to src (since the graph is undirected)
  newNode = create_node(src, wt);
  newNode->next = gr->lists[dst];
  gr->lists[dst] = newNode;
}

void BFS(graph *gr, int start, int num) {
  int *visited = (int *)calloc(num, sizeof(int));
  int *queue = (int *)malloc(num * sizeof(int));
  int front = -1;
  int rear = -1;
  visited[start] = 1;
  queue[++rear] = start;
  while (front < rear) {
    int current = queue[++front];
    printf("%d ", current);
    node *temp = gr->lists[current];
    while (temp != NULL) {
      if (!visited[temp->vertex]) {
        visited[temp->vertex] = 1;
        queue[++rear] = temp->vertex;
      }
      temp = temp->next;
    }
  }
  printf("\n");
  free(visited);
  free(queue);
}

void DFS(graph *gr, int start, int num) {
  int *visited = (int *)calloc(num, sizeof(int));
  int *stack = (int *)malloc(num * sizeof(int));
  int top = -1;
  visited[start] = 1;
  stack[++top] = start;
  while (top != -1) {
    int current = stack[top--];
    printf("%d ", current);
    node *temp = gr->lists[current];
    while (temp != NULL) {
      if (!visited[temp->vertex]) {
        visited[temp->vertex] = 1;
        stack[++top] = temp->vertex;
      }
      temp = temp->next;
    }
  }
  printf("\n");
  free(visited);
  free(stack);
}

int main() {
  int num;
  printf("Enter number of vertices : ");
  scanf("%d", &num);
  graph *gr = create_graph(num);
  int src, dst, wt, ch, start;
  do {

    printf("1. Add edge\n2. Display BFS\n3. Display DFS\n4. Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    
    switch (ch) {
      case 1:
        printf("Enter source node, destination node and weight : ");
        scanf("%d %d %d", &src, &dst, &wt);
        if (src < num && dst < num)
          addEdge(gr, src, dst, wt);
        else
          printf("Invalid Index\n");
        break;

      case 2:
        printf("Enter vertex from where you want to start : ");
        scanf("%d", &start);
        BFS(gr, start, num);
        break;

      case 3:
        printf("Enter vertex from where you want to start : ");
        scanf("%d", &start);
        DFS(gr, start, num);
        break;

      case 4:
        return 0;
        break;
    }
  } while (ch <= 4);

  return 0;
}
