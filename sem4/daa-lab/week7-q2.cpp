// credits to anirudh
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> bellman_ford(int V,
                           unordered_map<int, vector<pair<int, int>>> &adj,
                           int src) {
    vector<int> dist(V, 1e9);
    dist[src] = 0;

    for (int i = 0; i < V - 1; ++i) {
      for (auto &[u, nbrs] : adj) {
        for (auto &[v, wt] : nbrs) {
          if (dist[u] != 1e9 && dist[u] + wt < dist[v])
            dist[v] = dist[u] + wt;
        }
      }
    }

    for (auto &[u, nbrs] : adj) {
      for (auto &[v, wt] : nbrs) {
        if (dist[u] != 1e9 && dist[u] + wt < dist[v])
          return {-1};
      }
    }
    return dist;
  }
};

int main() {
  int V, E;
  cout << "Enter number of vertices and edges: ";
  cin >> V >> E;

  unordered_map<int, vector<pair<int, int>>> adj;
  cout << "Enter edges in the format: u v w (u to v with weight w)\n";
  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
  }

  int src;
  cout << "Enter source vertex: ";
  cin >> src;

  Solution sol;
  vector<int> res = sol.bellman_ford(V, adj, src);

  if (res.size() == 1 && res[0] == -1)
    cout << "The graph contains a negative cycle.\n";
  else {
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; ++i)
      cout << "To vertex " << i << ": " << res[i] << "\n";
  }

  return 0;
}
