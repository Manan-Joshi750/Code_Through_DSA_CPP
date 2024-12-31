#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int startNode, vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void bfsTraversal(int N, vector<vector<int>>& adjList) {
    vector<bool> visited(N, false);

    // Run BFS for each disconnected component
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            bfs(i, adjList, visited);
            cout << endl;  // Separate components with new lines
        }
    }
}

int main() {
    int N, M;
    cout << "Enter the number of nodes: ";
    cin >> N;
    cout << "Enter the number of edges: ";
    cin >> M;

    vector<vector<int>> adjList(N);

    cout << "Enter the edges (u v format):" << endl;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout << "BFS Traversal of the graph:" << endl;
    bfsTraversal(N, adjList);

    return 0;
}