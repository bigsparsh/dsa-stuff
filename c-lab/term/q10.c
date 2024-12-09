/*
 Name: Sparsh Singh
 University Roll No: 2024329
 Section: C
  
  Q10- Write a C program to implement DFS and BFS.
*/

#include <stdio.h>
#include <stdlib.h>

// Edge structure
typedef struct Edge {
  int weight;
  struct Vertex *dest;
  struct Edge *next;
} Edge;

// Vertex structure
typedef struct Vertex {
  int data;
  struct Edge *edge;
  struct Vertex *next;
  int visited;
} Vertex;

// Function prototypes
void create_edge (Vertex **, int, int, int);
void create_vertex (Vertex **, int);
void display_graph (Vertex *);
void dfs (Vertex *);
void bfs (Vertex *);
void visitReset (Vertex *);

int main () {
  // Head pointer
  Vertex *head = NULL;
  int choice;
  int vertex, edge, weight;

  // Menu driven program
  while (1) {
    printf("1. Create Vertex\n");
    printf("2. Create Edge\n");
    printf("3. Display Graph\n");
    printf("4. DFS\n");
    printf("5. BFS\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // Create a vertex
        printf("Enter the vertex: ");
        scanf("%d", &vertex);
        create_vertex(&head, vertex);
        break;
      case 2:
        // Create an edge
        printf("Enter the source: ");
        scanf("%d", &vertex);
        printf("Enter the destination: ");
        scanf("%d", &edge);
        create_edge(&head, vertex, edge, 0);
        break;
      case 3:
        // Display the graph
        display_graph(head);
        break;
      case 4:
        // DFS
        visitReset(head);
        dfs(head);
        break;
      case 5:
        // BFS
        visitReset(head);
        bfs(head);
        break;
      case 6:
        // Exit
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}

// Function to perform depth first search
void dfs (Vertex *head) {
  // Base case
  if (head == NULL) {
    return;
  }

  // Recursive case
  head->visited = 1;
  printf("%d ", head->data);

  // Traverse the edges of the vertex and call dfs on the destination vertex
  Edge *edge = head->edge;
  while (edge != NULL) {
    if (edge->dest->visited == 0) {
      dfs(edge->dest);
    }
    edge = edge->next;
  }
}

// Function to perform breadth first search
void bfs (Vertex *head) {
  // Base case
  if (head == NULL) {
    return;
  }

  // Queue to store the vertices
  Vertex *queue[100];
  int front = 0;
  int rear = 0;

  // Add the head vertex to the queue
  queue[rear++] = head;
  head->visited = 1;

  // Traverse the vertices in the queue and add the destination vertices to the queue
  while (front < rear) {
    Vertex *vertex = queue[front++];
    printf("%d ", vertex->data);

    Edge *edge = vertex->edge;
    while (edge != NULL) {
      if (edge->dest->visited == 0) {
        queue[rear++] = edge->dest;
        edge->dest->visited = 1;
      }
      edge = edge->next;
    }
  }
}

// Function to reset the visited flag of all the vertices
void visitReset (Vertex *head) {
  // Reset the visited flag of all the vertices
  while (head != NULL) {
    head->visited = 0;
    head = head->next;
  }
}

// Function to create an edge between two vertices
void create_edge (Vertex **head, int src, int dest, int weight) {
  Vertex *src_vertex = *head;
  Vertex *dest_vertex = *head;

  // Find the source and destination vertices
  while (src_vertex != NULL && src_vertex->data != src) {
    src_vertex = src_vertex->next;
  }
  while (dest_vertex != NULL && dest_vertex->data != dest) {
    dest_vertex = dest_vertex->next;
  }

  // Check if the source and destination vertices are valid
  if (src_vertex == NULL || dest_vertex == NULL) {
    printf("Invalid source or destination vertex\n");
    return;
  }

  // Create an edge between the source and destination vertices
  Edge *new_edge = (Edge *) malloc(sizeof(Edge));
  new_edge->weight = weight;
  new_edge->dest = dest_vertex;
  new_edge->next = NULL;

  if (src_vertex->edge == NULL) {
    src_vertex->edge = new_edge;
  } else {
    new_edge->next = src_vertex->edge;
    src_vertex->edge = new_edge;
  }
}

// Function to create a vertex
void create_vertex (Vertex **head, int data) {
  Vertex *new_vertex = (Vertex *) malloc(sizeof(Vertex));
  new_vertex->data = data;
  new_vertex->edge = NULL;
  new_vertex->next = NULL;
  new_vertex->visited = 0;

  // Add the vertex to the graph
  if (*head == NULL) {
    *head = new_vertex;
  } else {
    Vertex *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_vertex;
  }
}

// Function to display the graph
void display_graph (Vertex *head) {
  Vertex *temp = head;
  Edge *edge_temp;

  // Traverse the vertices and display the edges
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    edge_temp = temp->edge;
    while (edge_temp != NULL) {
      printf("%d ", edge_temp->dest->data);
      edge_temp = edge_temp->next;
    }
    printf("\n");
    temp = temp->next;
  }
}

