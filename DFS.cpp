#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> dist;

void DFS(int node,int d) {
    visited[node] = true;
    dist[node] = d;
    cout << node << " ";

        for(auto adj : graph[node]) {
            if(!visited[adj]) {
                visited[adj] = true;
                DFS(adj,d+1);
            }
        }
}

int main() {
    int v,e,m,n,source;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    graph.assign(v,vector<int>());
    visited.assign(v,false);
    dist.assign(v,-1);

    cout << "Enter the edges: " << endl;
    for(int i=0; i<e; i++) {
        cin >> m >> n;

        graph[m].push_back(n);  //directed graph
    }

    cout << "Enter the source: ";
    cin >> source;
    cout << "DFS Traversal: " << endl;
    DFS(source,0);

    cout << "\nDistance from source: " << endl;
    for(int i=0; i<v; i++) {
        cout << i << " distance -> " << dist[i] << endl;
    }
}