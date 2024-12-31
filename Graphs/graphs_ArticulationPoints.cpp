/*The nodes which on removing results in the splitting of graph into two or more components are known as articulation points. 
Articulation Points (also called cut vertices) in a graph are nodes that, if removed along with their edges, 
increase the number of connected components in the graph. 
These points are critical in network design because their failure would disrupt connectivity in the network.

Key Concept:
In an undirected graph, a node u is an articulation point if:
--> It’s the root node of the DFS tree with at least two independent children.
--> Or, it has a child v such that no vertex in the subtree rooted at v has a back edge to one of u's ancestors.

Algorithm (Using DFS):
To find articulation points, we use Depth-First Search (DFS) with the following key properties:
--> Discovery Time: The time when a node is first visited.
--> Low-Link Value: The smallest discovery time reachable from the node, including itself and its descendants.

Conditions for Articulation Points:
If the node is the root of DFS and has two or more children in the DFS tree, it is an articulation point.
For a non-root node u, if there exists a child v such that low[v] >= discovery[u], then u is an articulation point. */
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& discovery, vector<int>& low, vector<bool>& visited, set<int>& articulationPoints, int& time, int rootChildren) {
    visited[u] = true;
    discovery[u] = low[u] = ++time;
    int children = 0;

    for (int v : adj[u]) {
        if (!visited[v]) {
            if (u == 0) rootChildren++;  // Track root children separately
            children++;
            dfs(v, u, adj, discovery, low, visited, articulationPoints, time, rootChildren);
            low[u] = min(low[u], low[v]);

            if (parent != -1 && low[v] >= discovery[u]) {
                articulationPoints.insert(u);
            }

            if (parent == -1 && children > 1) {
                articulationPoints.insert(u);
            }
        } else if (v != parent) {
            low[u] = min(low[u], discovery[v]);
        }
    }
}

set<int> findArticulationPoints(int V, vector<vector<int>>& adj) {
    vector<int> discovery(V, -1), low(V, -1);
    vector<bool> visited(V, false);
    set<int> articulationPoints;
    int time = 0;
    int rootChildren = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj, discovery, low, visited, articulationPoints, time, rootChildren);
        }
    }

    return articulationPoints;
}

int main() {
    int V = 5;  // Number of vertices
    vector<vector<int>> adj(V);

    // Graph edges
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);

    set<int> articulationPoints = findArticulationPoints(V, adj);

    cout << "Articulation points in the graph:\n";
    for (int point : articulationPoints) {
        cout << point << " ";
    }
    cout << endl;

    return 0;
}