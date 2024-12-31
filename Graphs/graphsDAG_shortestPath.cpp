#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

// Function to perform DFS and find the topological order
void topologicalSort(int node, vector<vector<pair<int, int>>>& adjList, vector<bool>& visited, stack<int>& topoStack) {
    visited[node] = true;
    for (auto& neighbor : adjList[node]) {
        int nextNode = neighbor.first;
        if (!visited[nextNode]) {
            topologicalSort(nextNode, adjList, visited, topoStack);
        }
    }
    topoStack.push(node); // Push node to stack after visiting all neighbors
}

// Function to find shortest path in a DAG
vector<int> shortestPathInDAG(int n, vector<vector<pair<int, int>>>& adjList, int start) {
    vector<bool> visited(n, false);
    stack<int> topoStack;

    // Step 1: Perform topological sort
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topologicalSort(i, adjList, visited, topoStack);
        }
    }

    // Step 2: Initialize distances with infinity, except start node
    vector<int> distance(n, INT_MAX);
    distance[start] = 0;

    // Step 3: Process nodes in topological order
    while (!topoStack.empty()) {
        int node = topoStack.top();
        topoStack.pop();

        // Update distances to all neighbors if node is reachable
        if (distance[node] != INT_MAX) {
            for (auto& neighbor : adjList[node]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                if (distance[node] + weight < distance[nextNode]) {
                    distance[nextNode] = distance[node] + weight;
                }
            }
        }
    }

    return distance;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> adjList(n); // Adjacency list to store weighted edges

    cout << "Enter the edges (u v w format, where w is the weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].emplace_back(v, w);
    }

    int start;
    cout << "Enter the starting node: ";
    cin >> start;

    vector<int> distances = shortestPathInDAG(n, adjList, start);

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        if (distances[i] == INT_MAX) {
            cout << "Unreachable\n";
        } else {
            cout << distances[i] << "\n";
        }
    }

    return 0;
}