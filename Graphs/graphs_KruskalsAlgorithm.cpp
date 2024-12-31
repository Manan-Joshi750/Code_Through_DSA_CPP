/*Kruskal's Algorithm is a popular greedy algorithm used to find the Minimum Spanning Tree (MST) of a connected, undirected graph. 
It sorts edges by weight and builds the MST incrementally by adding the smallest edge that doesn't form a cycle.

Steps in Kruskal's Algorithm : 
--> Sort all edges in non-decreasing order of their weights.
--> Initialize an empty set for the MST.
--> For each edge in the sorted list:
1. If adding the edge to the MST does not create a cycle, add it to the MST.
2. If it creates a cycle, skip that edge.
--> Repeat until you have exactly V−1 edges in the MST, where V is the number of vertices.

To efficiently check for cycles, Union-Find (Disjoint Set) is commonly used, which enables quick checking and merging of connected components. */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
    Edge(int u, int v, int w) : src(u), dest(v), weight(w) {}
};

// Comparator to sort edges by weight
bool compareEdge(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Union-Find (Disjoint Set) with path compression and union by rank
class UnionFind {
public:
    vector<int> parent, rank;
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u]) parent[u] = find(parent[u]);
        return parent[u];
    }
    
    bool unionSets(int u, int v) {
        int rootU = find(u), rootV = find(v);
        if (rootU == rootV) return false;
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        return true;
    }
};

// Kruskal's Algorithm to find MST
int kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdge);
    UnionFind uf(V);
    int mstWeight = 0;

    for (Edge& edge : edges) {
        if (uf.unionSets(edge.src, edge.dest)) {
            mstWeight += edge.weight;
            cout << "Edge (" << edge.src << " - " << edge.dest << ") with weight " 
                 << edge.weight << " added to MST." << endl;
        }
    }

    return mstWeight;
}

int main() {
    int V = 4;  // Number of vertices
    vector<Edge> edges = {
        Edge(0, 1, 10),
        Edge(0, 2, 6),
        Edge(0, 3, 5),
        Edge(1, 3, 15),
        Edge(2, 3, 4)
    };

    int mstWeight = kruskalMST(V, edges);
    cout << "Total weight of MST: " << mstWeight << endl;

    return 0;
}