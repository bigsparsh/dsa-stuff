// Write a C program to store the details of a weighted graph.

#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
  int weight;
  struct Vertex *dest;
  struct Edge *next;
} Edge;

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

  while (1) {
    printf("1. Create Vertex\n");
    printf("2. Create Edge\n");
    printf("3. Display Graph\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the vertex: ");
        scanf("%d", &vertex);
        create_vertex(&head, vertex);
        break;
      case 2:
        printf("Enter the source: ");
        scanf("%d", &vertex);
        printf("Enter the destination: ");
        scanf("%d", &edge);
        printf("Enter the weight: ");
        scanf("%d", &weight);
        create_edge(&head, vertex, edge, weight);
        break;
      case 3:
        display_graph(head);
        break;
      case 4:
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}

void create_edge (Vertex **head, int src, int dest, int weight) {
  Vertex *src_vertex = *head;
  Vertex *dest_vertex = *head;

  while (src_vertex != NULL && src_vertex->data != src) {
    src_vertex = src_vertex->next;
  }

  while (dest_vertex != NULL && dest_vertex->data != dest) {
    dest_vertex = dest_vertex->next;
  }

  if (src_vertex == NULL || dest_vertex == NULL) {
    printf("Invalid source or destination vertex\n");
    return;
  }

  Edge *new_edge = (Edge *) malloc(sizeof(Edge));
  new_edge->weight = weight;
  new_edge->dest = dest_vertex;
  new_edge->next = NULL;

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

void create_vertex (Vertex **head, int data) {
  Vertex *new_vertex = (Vertex *) malloc(sizeof(Vertex));
  new_vertex->data = data;
  new_vertex->edge = NULL;
  new_vertex->next = NULL;

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

void display_graph (Vertex *head) {
  Vertex *temp = head;
  Edge *edge_temp;

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
