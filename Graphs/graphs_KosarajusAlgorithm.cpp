/*Kosaraju’s Algorithm is an efficient algorithm for finding Strongly Connected Components (SCCs) in a directed graph. 
A strongly connected component is a maximal subgraph where every vertex is reachable from every other vertex within the subgraph.

Key Steps in Kosaraju's Algorithm : 
Kosaraju’s Algorithm works in O(V + E) time complexity, where V is the number of vertices and E is the number of edges in the graph. 

The algorithm involves the following steps:
--> Perform a DFS and store the finishing order:
1. Traverse the graph and complete a Depth-First Search (DFS) on each unvisited node.
2. Record each node's finishing time (when all its children have been fully processed) by pushing it onto a stack.
--> Transpose the Graph:
1. Reverse the direction of every edge in the graph (creating a new graph where all edges point in the opposite direction).
--> DFS in the order of the stack on the Transposed Graph:
1. Pop nodes from the stack one by one and perform DFS on each node in the transposed graph.
2. Each DFS traversal on this transposed graph will give one SCC, as nodes in an SCC in the original graph remain connected in the transposed graph. */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // Step 1: DFS to fill the stack with vertices in finishing order
    void dfs1(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& finishStack) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs1(neighbor, adj, visited, finishStack);
            }
        }
        finishStack.push(node);
    }

    // Step 3: DFS on the transposed graph to find SCC
    void dfs2(int node, vector<vector<int>>& transposedAdj, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        for (int neighbor : transposedAdj[node]) {
            if (!visited[neighbor]) {
                dfs2(neighbor, transposedAdj, visited, component);
            }
        }
    }

    vector<vector<int>> kosaraju(int V, vector<vector<int>>& adj) {
        stack<int> finishStack;
        vector<bool> visited(V, false);

        // Step 1: Populate finishStack with nodes in order of completion
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs1(i, adj, visited, finishStack);
            }
        }

        // Step 2: Transpose the graph
        vector<vector<int>> transposedAdj(V);
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                transposedAdj[v].push_back(u);
            }
        }

        // Step 3: Perform DFS on transposed graph in stack order
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> stronglyConnectedComponents;

        while (!finishStack.empty()) {
            int node = finishStack.top();
            finishStack.pop();

            if (!visited[node]) {
                vector<int> component;
                dfs2(node, transposedAdj, visited, component);
                stronglyConnectedComponents.push_back(component);
            }
        }

        return stronglyConnectedComponents;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> adj = {
        {2, 3},  // Edges from node 0
        {0},     // Edges from node 1
        {1},     // Edges from node 2
        {4},     // Edges from node 3
        {}       // Edges from node 4
    };

    Solution solution;
    vector<vector<int>> sccs = solution.kosaraju(V, adj);

    cout << "Strongly Connected Components:" << endl;
    for (const auto& scc : sccs) {
        for (int node : scc) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}