#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> shortestPath(int n, vector<vector<int>>& adjList, int start) {
    vector<int> distance(n, INT_MAX); // Initialize distances with "infinity"
    distance[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Visit all adjacent nodes of the current node
        for (int neighbor : adjList[node]) {
            // If a shorter path to neighbor is found
            if (distance[node] + 1 < distance[neighbor]) {
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return distance;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adjList(n);

    cout << "Enter the edges (u v format):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Since it's an undirected graph
    }

    int start;
    cout << "Enter the starting node: ";
    cin >> start;

    vector<int> distances = shortestPath(n, adjList, start);

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