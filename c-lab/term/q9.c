/*
 Name: Sparsh Singh
 University Roll No: 2024329
 Section: C
  
  Q9- Write a C program to store the details of a weighted graph.
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
} Vertex;

void create_edge (Vertex **, int, int, int);
void create_vertex (Vertex **, int);
void display_graph (Vertex *);

int main () {
  Vertex *head = NULL;
  int choice;
  int vertex, edge, weight;

  // Menu driven program
  while (1) {
    printf("1. Create Vertex\n");
    printf("2. Create Edge\n");
    printf("3. Display Graph\n");
    printf("4. Exit\n");
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
        printf("Enter the weight: ");
        scanf("%d", &weight);
        create_edge(&head, vertex, edge, weight);
        break;
      case 3:
        // Display the graph
        display_graph(head);
        break;
      case 4:
        // Exit the program
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}

// Create an edge
void create_edge (Vertex **head, int src, int dest, int weight) {
  Vertex *src_vertex = *head;
  Vertex *dest_vertex = *head;

  // Find the source and destination vertex
  while (src_vertex != NULL && src_vertex->data != src) {
    src_vertex = src_vertex->next;
  }
  while (dest_vertex != NULL && dest_vertex->data != dest) {
    dest_vertex = dest_vertex->next;
  }

  // If source or destination vertex is not found
  if (src_vertex == NULL || dest_vertex == NULL) {
    printf("Invalid source or destination vertex\n");
    return;
  }

  // Create a new edge
  Edge *new_edge = (Edge *) malloc(sizeof(Edge));
  new_edge->weight = weight;
  new_edge->dest = dest_vertex;
  new_edge->next = NULL;

  // If the source vertex has no edge then add the new edge else add the new edge at the end of the edge list
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

// Create a vertex
void create_vertex (Vertex **head, int data) {
  Vertex *new_vertex = (Vertex *) malloc(sizeof(Vertex));
  new_vertex->data = data;
  new_vertex->edge = NULL;
  new_vertex->next = NULL;

  // If the graph is empty then add the new vertex else add the new vertex at the end of the vertex list
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

// Display the graph
void display_graph (Vertex *head) {
  Vertex *temp = head;
  Edge *edge_temp;

  // Print the graph
  while (temp != NULL) {
    printf("%d -> ", temp->data);
    edge_temp = temp->edge;
    while (edge_temp != NULL) {
      printf("%d(%d) ", edge_temp->dest->data, edge_temp->weight);
      edge_temp = edge_temp->next;
    }
    printf("\n");
    temp = temp->next;
  }
}
