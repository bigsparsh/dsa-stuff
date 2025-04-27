#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
  vector<int> parent, rank;

public:
  DisjointSet(int n) {
    parent.resize(n + 1);
    rank.resize(n + 1, 0);
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) {
      return;
    }

    if (rank[rootX] < rank[rootY]) {
      parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
      parent[rootY] = rootX;
    } else {
      parent[rootY] = rootX;
      rank[rootX]++;
    }
  }
};

class Solution {
public:
  struct Edge {
    int src, dest, weight;

    bool operator<(const Edge &other) const { return weight < other.weight; }
  };

  int kruskalMST(int V, vector<Edge> &edges) {
    sort(edges.begin(), edges.end());

    DisjointSet ds(V);

    int total_cost = 0;
    int edge_count = 0;

    for (const Edge &edge : edges) {
      int srcRoot = ds.find(edge.src);
      int destRoot = ds.find(edge.dest);

      if (srcRoot != destRoot) {
        total_cost += edge.weight;
        ds.unionSets(srcRoot, destRoot);
        edge_count++;
      }

      if (edge_count == V - 1) {
        break;
      }
    }

    if (edge_count != V - 1) {
      return -1;
    }

    return total_cost;
  }
};

int main() {
  int V;
  cout << "Enter number of cities: ";
  cin >> V;

  int E;
  cout << "Enter number of possible roads: ";
  cin >> E;

  vector<Solution::Edge> edges;

  cout << "Enter the details of each road (city1 city2 cost):\n";
  for (int i = 0; i < E; ++i) {
    int city1, city2, cost;
    cin >> city1 >> city2 >> cost;
    edges.push_back({city1, city2, cost});
  }

  Solution sol;
  int minimum_cost = sol.kruskalMST(V, edges);

  cout << "\nMinimum budget required for road construction:\n";
  if (minimum_cost == -1) {
    cout << "It is not possible to connect all cities.\n";
  } else {
    cout << minimum_cost << " rupees\n";
  }

  return 0;
}
