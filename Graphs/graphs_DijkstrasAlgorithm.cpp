#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(int n, int start, vector<vector<pair<int, int>>>& adj) {
    vector<int> distance(n, INT_MAX);
    distance[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); // {distance, node}
    
    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        // If we find a distance longer than the recorded one, we skip it
        if (dist > distance[node]) continue;
        
        for (auto neighbor : adj[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;
            
            if (distance[node] + weight < distance[nextNode]) {
                distance[nextNode] = distance[node] + weight;
                pq.push({distance[nextNode], nextNode});
            }
        }
    }
    
    return distance;
}

int main() {
    int n, m, start;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(n);
    cout << "Enter each edge in the format (u, v, weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // Comment this line if the graph is directed
    }
    
    cout << "Enter the starting node: ";
    cin >> start;
    
    vector<int> shortestDistances = dijkstra(n, start, adj);
    
    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << ": " << shortestDistances[i] << endl;
    }
    
    return 0;
}