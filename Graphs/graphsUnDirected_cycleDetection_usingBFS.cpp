#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool hasCycleBFS(int src, vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<pair<int, int>> q;
    q.push({src, -1});
    visited[src] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, node});
            } else if (neighbor != parent) {
                return true;
            }
        }
    }

    return false;
}

bool containsCycle(int n, vector<vector<int>>& adjList) {
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycleBFS(i, adjList, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> adjList(n);
    cout << "Enter edges (u v format):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    if (containsCycle(n, adjList)) {
        cout << "The graph contains a cycle.\n";
    } else {
        cout << "The graph does not contain a cycle.\n";
    }

    return 0;
}