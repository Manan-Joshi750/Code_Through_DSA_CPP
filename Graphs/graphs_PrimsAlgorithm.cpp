/*Prim's Algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) for a weighted, undirected graph. 
It starts from any node and continuously adds the lowest-weight edges to grow the MST until all nodes are included. 

A spanning tree and a minimum spanning tree (MST) are both important concepts in graph theory, particularly when dealing with connected, undirected graphs.

### Spanning Tree
- A spanning tree of a connected graph is a subgraph that includes all the vertices of the original graph and is a tree (i.e., it has no cycles).
- This subgraph connects all the vertices together with the minimum number of edges required to ensure connectivity.
- For a graph with \( V \) vertices, a spanning tree has exactly \( V - 1 \) edges.

> Example : For a simple connected graph with four vertices and multiple edges, 
one possible spanning tree would select the subset of edges that connects all vertices without forming any cycles.

### Minimum Spanning Tree (MST)
- A minimum spanning tree (MST) is a special type of spanning tree where the sum of the edge weights is minimized.
- In graphs where edges have weights (such as representing distances, costs, or any metric), an MST represents the minimum-cost way to connect all vertices.
- A graph can have multiple MSTs if there are edges with the same weight, but all MSTs will have the same total weight.

### Example for Clarity : 
Suppose you have a graph of four cities (A, B, C, D) with roads (edges) between them. Each road has a construction cost:

- A-B: 1
- A-C: 3
- B-C: 2
- B-D: 4
- C-D: 5

The spanning tree is any subset of these roads that connects all cities with no cycles, 
but the minimum spanning tree (MST) would specifically include the roads that minimize the total construction cost. In this example, the MST would be:

- A-B (cost 1)
- B-C (cost 2)
- B-D (cost 4)

This selection gives a minimum total cost of (1 + 2 + 4 = 7), which is the minimum cost required to connect all cities without any cycles. */
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int primsAlgorithm(int n, vector<vector<pair<int, int>>>& adj) {
    vector<int> key(n, INT_MAX);       // Minimum weight edge to each node
    vector<bool> inMST(n, false);      // Track nodes in MST
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start from node 0
    key[0] = 0;
    pq.push({0, 0});  // {weight, node}
    int mstWeight = 0;

    while (!pq.empty()) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;        // Ignore if already in MST

        inMST[u] = true;               // Include node in MST
        mstWeight += weight;           // Add edge weight to total MST weight

        // Explore neighbors of the node
        for (auto neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            // Update key for the neighbor if a lower weight edge is found
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push({w, v});
            }
        }
    }
    return mstWeight;
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    cout << "Enter each edge in the format (u, v, weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});  // Since the graph is undirected
    }

    int mstWeight = primsAlgorithm(n, adj);
    cout << "Total weight of the Minimum Spanning Tree: " << mstWeight << endl;

    return 0;
}