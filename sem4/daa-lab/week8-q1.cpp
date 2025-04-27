#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int primMST(int V, unordered_map<int, vector<pair<int, int>>> &adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    int source = 1;

    vector<bool> inMST(V + 1, false);
    vector<int> key(V + 1, INT_MAX);
    vector<int> parent(V + 1, -1);
    int total_cost = 0;

    pq.push({0, source});
    key[source] = 0;

    while (!pq.empty()) {
      int u = pq.top().second;
      pq.pop();
      if (inMST[u])
        continue;

      inMST[u] = true;
      total_cost += key[u];

      for (const auto &neighbor : adj[u]) {
        int v = neighbor.first;
        int weight = neighbor.second;

        if (!inMST[v] && weight < key[v]) {
          parent[v] = u;
          key[v] = weight;
          pq.push({key[v], v});
        }
      }
    }

    for (int i = 1; i <= V; i++) {
      if (!inMST[i]) {
        return -1;
      }
    }

    return total_cost;
  }
};

int main() {
  int V;
  cout << "Enter number of cities: ";
  cin >> V;

  unordered_map<int, vector<pair<int, int>>> adj;

  int E;
  cout << "Enter number of possible roads: ";
  cin >> E;

  cout << "Enter the details of each road (city1 city2 cost):\n";
  for (int i = 0; i < E; ++i) {
    int city1, city2, cost;
    cin >> city1 >> city2 >> cost;
    adj[city1].push_back({city2, cost});
    adj[city2].push_back({city1, cost});
  }

  Solution sol;
  int minimum_cost = sol.primMST(V, adj);

  cout << "\nMinimum budget required for road construction:\n";
  if (minimum_cost == -1)
    cout << "It is not possible to connect all cities.\n";
  else
    cout << minimum_cost << " rupees\n";
  return 0;
}
