/*Graph is a data structure which is a combination of both nodes and the edges connecting those nodes. 
A graph showing or having the direction of edges is known as a directed graph and a graph not having the directions is known as a undirected graph. 
Node : It is an entity in which we can store any type of data. 
Edge : connection between the nodes. 
Degree of a vertex : number of edges connected with a vertex in an undirected graph. 
InDegree of a vertex : number of edges coming towards this particular vertex in an directed graph. 
OutDegree of a vertex : number of edges going away from this particular vertex in a directed graph. 
A graph consisting of weighted edges (i.e... there are some values assigned to the edges of a graph) is known as a weighted graph. 
IMP : If we aren't given the weights over the edges, then it is safe to consider them as 1 over each edge for the algorithms which require them. 
A graph consisting of cycles is known as a cyclic graph and the other one is known as a acyclic graph. */

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction){
        //direction -> 0 means undirected and 1 means directed

        //create an edge from u to v
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i : adj){
            cout << i.first << " -> ";
            for(auto j : i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main(){
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    int m;
    cout << "Enter the number of edges : ";
    cin >> m;

    graph g;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        //creating an undirected graph
        g.addEdge(u,v,0);
    }

    g.printAdjList();
    return 0;
}