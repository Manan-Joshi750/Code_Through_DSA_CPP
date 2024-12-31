#include <iostream>
#include <vector>
using namespace std;

bool hasCycleDFS(int node, int parent, vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            if (hasCycleDFS(neighbor, node, adjList, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

bool containsCycle(int n, vector<vector<int>>& adjList) {
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(i, -1, adjList, visited)) {
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