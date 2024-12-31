/*Kahn's algorithm is a BFS-based approach for performing a topological sort on a Directed Acyclic Graph (DAG). 
This algorithm uses in-degree counts to ensure that each node appears before its dependents in the sorted order.

Kahn’s Algorithm Steps : 
--> Calculate in-degrees for each node in the graph. The in-degree of a node is the number of incoming edges.
--> Initialize a queue and add all nodes with in-degree = 0 (these nodes have no dependencies).
--> Process nodes from the queue :
1. Remove a node from the queue, add it to the topological order, and reduce the in-degree of its neighbors by 1.
2. If any neighbor’s in-degree becomes 0 after decrementing, add it to the queue.
--> Repeat this process until the queue is empty.

If all nodes are added to the topological order, then the graph has no cycles, and the sort is complete. If not, the graph contains a cycle. */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSort(int n, vector<vector<int>>& adjList) {
    vector<int> inDegree(n, 0);
    
    // Calculate in-degrees of all nodes
    for (int i = 0; i < n; i++) {
        for (int neighbor : adjList[i]) {
            inDegree[neighbor]++;
        }
    }

    queue<int> q;
    vector<int> topoOrder;

    // Initialize the queue with all nodes having in-degree 0
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Process nodes in queue
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        // Reduce in-degree of each neighbor
        for (int neighbor : adjList[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If topoOrder size is less than n, there is a cycle in the graph
    if (topoOrder.size() != n) {
        cout << "The graph has a cycle and therefore no topological ordering exists.\n";
        return {};
    }
    
    return topoOrder;
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

    vector<int> result = topologicalSort(n, adjList);

    if (!result.empty()) {
        cout << "Topological Sort Order: ";
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}