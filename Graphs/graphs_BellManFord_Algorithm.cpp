/*The Bellman-Ford Algorithm is a single-source shortest path algorithm for graphs with both positive and negative edge weights. 
Unlike Dijkstra’s algorithm, Bellman-Ford can handle graphs with negative weights and is often used to detect negative weight cycles.

Key Points of the Bellman-Ford Algorithm:
--> Initialization:
Set the distance to the source node as 0 and all other nodes to infinity (INT_MAX).
--> Relax All Edges Repeatedly:
For each edge (u, v), if the distance to v through u is shorter than the current known distance to v, update it.
This process is repeated exactly (V-1) times, where V is the number of vertices. After these repetitions, the shortest paths (if they exist) will be found.
--> Check for Negative Weight Cycles:
To detect negative weight cycles, go through all edges one more time. If we find a shorter path to any vertex during this step, 
it means there is a negative weight cycle in the graph. */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool bellmanFord(int V, vector<vector<int>>& edges, int source, vector<int>& dist) {
        // Step 1: Initialize distances
        dist[source] = 0;

        // Step 2: Relax all edges (V-1) times
        for (int i = 0; i < V - 1; i++) {
            for (const auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];
                
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // Step 3: Check for negative weight cycles
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                return false; // Negative weight cycle detected
            }
        }

        return true; // No negative weight cycle
    }
};

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
    int source = 0;

    Solution solution;
    vector<int> dist(V, INT_MAX);
    
    if (solution.bellmanFord(V, edges, source, dist)) {
        cout << "Vertex   Distance from Source" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << "\t\t" << dist[i] << endl;
        }
    } else {
        cout << "Graph contains a negative weight cycle" << endl;
    }

    return 0;
}