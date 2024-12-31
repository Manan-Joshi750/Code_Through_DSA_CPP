#include <iostream>
#include <vector>
using namespace std;

void printAdjacencyList(int N, vector<pair<int, int>>& edges) {
    // Initialize adjacency list for N nodes
    vector<vector<int>> adjList(N);

    // Add edges to the adjacency list
    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    cout << endl;

    // Print the adjacency list
    cout << "Printing the adjacency list : " << endl;
    for (int i = 0; i < N; i++) {
        cout << i << " : ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    int N, M;
    cout << "Enter the number of nodes: ";
    cin >> N;
    cout << "Enter the number of edges: ";
    cin >> M;

    vector<pair<int, int>> edges(M);
    cout << "Enter the edges (u v format):" << endl;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }

    printAdjacencyList(N, edges);

    return 0;
}