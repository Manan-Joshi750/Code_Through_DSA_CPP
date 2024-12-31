/*A bridge is an edge in a graph on the removal of which, the number of connnected components increases, that is graph becomes disconnected. */
#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& discovery, vector<int>& low, vector<bool>& visited, vector<pair<int, int>>& bridges, int& time) {
    visited[u] = true;
    discovery[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (!visited[v]) {  // If v is not visited
            dfs(v, u, adj, discovery, low, visited, bridges, time);
            low[u] = min(low[u], low[v]);

            if (low[v] > discovery[u]) {
                bridges.push_back({u, v});  // (u, v) is a bridge
            }
        } else if (v != parent) {  // Update low[u] if v is an ancestor
            low[u] = min(low[u], discovery[v]);
        }
    }
}

vector<pair<int, int>> findBridges(int V, vector<vector<int>>& adj) {
    vector<int> discovery(V, -1), low(V, -1);
    vector<bool> visited(V, false);
    vector<pair<int, int>> bridges;
    int time = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj, discovery, low, visited, bridges, time);
        }
    }

    return bridges;
}

int main() {
    int V = 5;  // Number of vertices
    vector<vector<int>> adj(V);

    // Graph edges
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);

    vector<pair<int, int>> bridges = findBridges(V, adj);

    cout << "Bridges in the graph:\n";
    for (auto bridge : bridges) {
        cout << bridge.first << " - " << bridge.second << "\n";
    }

    return 0;
}