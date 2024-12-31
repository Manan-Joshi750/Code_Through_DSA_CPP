#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, adjList, visited, recStack)) {
                return true;
            }
        } else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = false;
    return false;
}

bool hasCycle(int n, vector<vector<int>>& adjList) {
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adjList, visited, recStack)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> adjList(n);
    cout << "Enter the edges (u v format for directed edges):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    if (hasCycle(n, adjList)) {
        cout << "The graph contains a cycle.\n";
    } else {
        cout << "The graph does not contain a cycle.\n";
    }

    return 0;
}