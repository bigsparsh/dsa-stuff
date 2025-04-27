// credits to anirudh
#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int dijkstra(int V, unordered_map<int, vector<pair<int, int>>> &adj,
               int source, int destination) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    vector<int> distance(V + 1, INT_MAX);
    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
      int current_distance = pq.top().first;
      int current_vertex = pq.top().second;
      pq.pop();

      if (current_vertex == destination) {
        return current_distance;
      }

      for (const auto &neighbor : adj[current_vertex]) {
        int neighbor_vertex = neighbor.first;
        int edge_weight = neighbor.second;

        if (current_distance + edge_weight < distance[neighbor_vertex]) {
          distance[neighbor_vertex] = current_distance + edge_weight;
          pq.push({distance[neighbor_vertex], neighbor_vertex});
        }
      }
    }

    return -1;
  }
};

int main() {
  int V;
  cout << "Enter number of vertices: ";
  cin >> V;

  unordered_map<int, vector<pair<int, int>>> adj;

  for (int i = 1; i <= V; ++i) {
    int edges;
    cout << "Enter the number of edges from vertex " << i << ": ";
    cin >> edges;

    for (int j = 0; j < edges; ++j) {
      int destination, weight;
      cout << "Enter destination vertex and weight for edge " << j + 1 << ": ";
      cin >> destination >> weight;
      adj[i].push_back({destination, weight});
      adj[destination].push_back({i, weight});
    }
    cout << "\n";
  }

  int source, destination;
  cout << "Enter source vertex: ";
  cin >> source;
  cout << "Enter destination vertex: ";
  cin >> destination;

  Solution sol;
  int shortest_distance = sol.dijkstra(V, adj, source, destination);

  cout << "\nShortest distance from vertex " << source << " to vertex "
       << destination << ":\n";
  if (shortest_distance == -1) {
    cout << "Destination is unreachable.\n";
  } else {
    cout << shortest_distance << "\n";
  }

  return 0;
}
