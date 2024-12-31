#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool hasCycle(int n, vector<vector<int>>& adjList) {
    vector<int> inDegree(n, 0);

    // Calculate in-degrees of all nodes
    for (int i = 0; i < n; i++) {
        for (int neighbor : adjList[i]) {
            inDegree[neighbor]++;
        }
    }

    queue<int> q;

    // Initialize the queue with all nodes having in-degree 0
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int processedNodes = 0;

    // Process nodes in queue
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        processedNodes++;

        // Reduce in-degree of each neighbor
        for (int neighbor : adjList[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If processed nodes is less than n, the graph has a cycle because for a valid topological sort, all nodes are processed. 
    return processedNodes != n;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adjList(n);

    cout << "Enter the directed edges (u v format):\n";
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