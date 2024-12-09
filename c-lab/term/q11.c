#include <stdio.h>
#include <stdlib.h>
// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a disjoint-set (Union-Find) data structure
struct DisjointSet {
    int *parent, *rank;
    int n;
};

// Function to create and initialize a disjoint-set
struct DisjointSet* createSet(int n) {
    struct DisjointSet* set = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    set->n = n;
    set->parent = (int*)malloc(n * sizeof(int));
    set->rank = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        set->parent[i] = i;  // Initially, each node is its own parent
        set->rank[i] = 0;     // Initially, the rank of each node is 0
    }
    return set;
}

// Find function with path compression
int find(struct DisjointSet* set, int i) {
    if (set->parent[i] != i) {
        set->parent[i] = find(set, set->parent[i]);  // Path compression
    }
    return set->parent[i];
}

// Union function by rank
void unionSets(struct DisjointSet* set, int x, int y) {
    int rootX = find(set, x);
    int rootY = find(set, y);

    if (rootX != rootY) {
        // Union by rank
        if (set->rank[rootX] > set->rank[rootY]) {
            set->parent[rootY] = rootX;
        } else if (set->rank[rootX] < set->rank[rootY]) {
            set->parent[rootX] = rootY;
        } else {
            set->parent[rootY] = rootX;
            set->rank[rootX] += 1;
        }
    }
}

// Function to compare two edges based on their weights (for sorting)
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's algorithm to find the Minimum Spanning Tree (MST)
void kruskal(struct Edge edges[], int E, int V) {
    // Step 1: Sort edges in increasing order of weights
    qsort(edges, E, sizeof(struct Edge), compareEdges);

    // Create disjoint sets
    struct DisjointSet* set = createSet(V);

    printf("\nMinimum Spanning Tree (MST):\n");

    int mstWeight = 0;  // Total weight of the MST
    int edgeCount = 0;  // Number of edges in the MST

    // Step 2: Iterate through all edges and add to MST if they don't form a cycle
    for (int i = 0; i < E && edgeCount < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;

        // Check if including this edge forms a cycle
        if (find(set, u) != find(set, v)) {
            printf("%d -- %d == %d\n", u, v, w);
            unionSets(set, u, v);
            mstWeight += w;
            edgeCount++;
        }
    }

    printf("\nTotal weight of MST: %d\n", mstWeight);
}

// Function to display the graph (edge list format)
void displayGraph(struct Edge edges[], int E) {
    printf("\nGraph (Edge list format):\n");
    for (int i = 0; i < E; i++) {
        printf("%d -- %d == %d\n", edges[i].src, edges[i].dest, edges[i].weight);
    }
}

int main() {
    int vertices, edges, choice;

    // Input the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Create an edge list to store graph edges
    struct Edge* edgesList = (struct Edge*)malloc(edges * sizeof(struct Edge));

    // Input the edges
    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (source, destination, weight): ", i + 1);
        scanf("%d %d %d", &edgesList[i].src, &edgesList[i].dest, &edgesList[i].weight);
    }

    while (1) {
        // Display the menu options
        printf("\nMenu:\n");
        printf("1. Display Graph\n");
        printf("2. Apply Kruskal's Algorithm (Find MST)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Display the graph in edge list format
                displayGraph(edgesList, edges);
                break;
            case 2:
                // Apply Kruskal's algorithm to find MST
                kruskal(edgesList, edges, vertices);
                break;
            case 3:
                // Exit the program
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
