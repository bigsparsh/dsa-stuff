// credits to anirudh
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int dfs(int u, int dest, int k,
        unordered_map<int, vector<pair<int, int>>> &adj) {
  if (k == 0)
    return (u == dest) ? 0 : INF;

  int minCost = INF;
  for (auto &[v, wt] : adj[u]) {
    int cost = dfs(v, dest, k - 1, adj);
    if (cost != INF)
      minCost = min(minCost, wt + cost);
  }

  return minCost;
}

int main() {
  int V, E;
  cout << "Enter number of vertices and edges: ";
  cin >> V >> E;

  unordered_map<int, vector<pair<int, int>>> adj;
  cout << "Enter edges (u v w):\n";
  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
  }

  int src, dest, k;
  cout << "Enter source, destination, and k (edges): ";
  cin >> src >> dest >> k;

  int result = dfs(src, dest, k, adj);
  if (result == INF)
    cout << "No path from " << src << " to " << dest << " with exactly " << k
         << " edges.\n";
  else
    cout << "Shortest path cost from " << src << " to " << dest
         << " with exactly " << k << " edges: " << result << '\n';

  return 0;
}
