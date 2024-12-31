#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);

    // Traverse all the neighbors of the current node
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited, component);
        }
    }
}

void dfsTraversal(int n, vector<vector<int>>& adjList) {
    vector<bool> visited(n, false);
    
    cout << "DFS Traversal of the graph:\n";
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, adjList, visited, component);
            
            // Print nodes in the current connected component
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    // Initialize adjacency list
    vector<vector<int>> adjList(n);

    cout << "Enter the edges (u v format):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Since the graph is undirected
    }

    // Perform DFS traversal
    dfsTraversal(n, adjList);

    return 0;
}