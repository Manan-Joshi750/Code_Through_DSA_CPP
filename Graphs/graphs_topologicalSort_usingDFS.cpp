/*Topological Sorting is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge 
u→v, vertex 𝑢 comes before v in the ordering. This sorting technique is commonly used in scenarios such as task scheduling, dependency resolution, 
and compilation order where each task depends on the completion of other tasks.

How the Code Works :
--> DFS Traversal:
For each unvisited node, perform DFS.
After exploring all neighbors of a node, the node is pushed onto a stack (topoStack). This stack represents the topological order in reverse.
--> Constructing Topological Order:
After DFS finishes, pop elements from the stack, creating the sorted order where dependencies appear before dependents.
--> Output:
The topologicalSort function returns the topologically sorted list of nodes, which is then printed in main. */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& topoStack) {
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited, topoStack);
        }
    }

    topoStack.push(node);
}

vector<int> topologicalSort(int n, vector<vector<int>>& adjList) {
    vector<bool> visited(n, false);
    stack<int> topoStack;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adjList, visited, topoStack);
        }
    }

    vector<int> topoOrder;
    while (!topoStack.empty()) {
        topoOrder.push_back(topoStack.top());
        topoStack.pop();
    }
    
    return topoOrder;
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

    vector<int> topoOrder = topologicalSort(n, adjList);

    cout << "Topological Sort Order: ";
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}