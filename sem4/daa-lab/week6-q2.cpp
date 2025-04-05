#include <iostream>
using namespace std;

typedef struct vtx {
  int data;
  struct vtx *next;
} Vertex;

typedef struct graph {
  int vtx_count;
  bool isDirected;
  Vertex **adj_list;
} Graph;

Graph* create_graph (int vtx_count, bool isDirected);
Vertex* create_vtx (int data);
void create_edge (Graph *grp, int src, int dest);
void bfs (Graph *grp, int src, int dest, int *visited);

int main () {
  int vtx_count, isDirected, *visited;
  cout << "Enter the number of nodes: ";
  cin >> vtx_count;
  cout << "Is the graph directed?: ";
  cin >> isDirected;

  Graph *grp = create_graph (vtx_count, isDirected);
  int choice, src, dest;
  
  do {
    cout << "\nWelcome to graph DFS program\n 1. Insert Edge\n 2. Check if Bipartite\n 3. Exit\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Enter the source: ";
        cin >> src;
        cout << "Enter the destination: ";
        cin >> dest;

        create_edge (grp, src, dest);
        break;
      case 2:
        visited = new int[vtx_count];
        cout << "Enter the source: ";
        cin >> src;
        cout << "Enter the destination: ";
        cin >> dest;
        bfs (grp, src, dest, visited);
        break;
      case 3:
        cout << "Exiting.." << endl;
        break;
    }

  } while (choice != 3);

}

Graph* create_graph (int vtx_count, bool isDirected) {
  Graph *newGraph = new Graph();
  newGraph->vtx_count = vtx_count;
  newGraph->isDirected = isDirected;
  newGraph->adj_list = new Vertex*[vtx_count];

  for (int i = 0; i < vtx_count; i++) 
    newGraph->adj_list[i] = nullptr;

  return newGraph;
}

Vertex* create_vtx (int data) {
  Vertex* newVtx = new Vertex();
  newVtx->data = data;
  newVtx->next = nullptr;
  return newVtx;
}

void create_edge (Graph *grp, int src, int dest) {
  Vertex *tmp = grp->adj_list[src];
  grp->adj_list[src] = create_vtx (dest);
  grp->adj_list[src]->next = tmp;

  if (!grp->isDirected) {
    tmp = grp->adj_list[dest];
    grp->adj_list[dest] = create_vtx (src);
    grp->adj_list[dest]->next = tmp;
  }
}

void bfs (Graph *grp, int src, int dest, int *visited) {
  int *queue = new int[grp->vtx_count];
  int *paint = new int[grp->vtx_count];
  int front = 0, rear = 0;
  queue[rear++] = src;
  paint[src] = 1;
  while (rear > front) {
    src = queue[front++];
    visited[src] = 1;
    Vertex *vtx = grp->adj_list[src];
    while (vtx != nullptr) {
      if (visited[vtx->data] == 0) {
        paint[vtx->data] = paint[src] ? 0 : 1;
        queue[rear++] = vtx->data;
      } else {
        if (paint[vtx->data] == (paint[src] ? 1 : 0)) {
          cout << "Not Bipartite" << endl;
          return;
        }
      }
      vtx = vtx->next;
    }
  }
  cout << "Yes Bipartite" << endl;
}
