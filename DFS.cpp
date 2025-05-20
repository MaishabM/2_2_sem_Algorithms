#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
vector<int> disc;
vector<int> fin;
int t = 0;

void DFS(int node){
    visited[node] = true;
    disc[node] = ++t;
    cout << node << " ";

    for(auto neighbour: graph[node]) {
        if(visited[neighbour] == false) {
            DFS(neighbour);
        }
    }

    fin[node] = ++t;
}

int main() {
    int v,e;
    cout << "Enter the number of vertice: ";
    cin>> v;
    cout<< "Enter the number of edges: ";
    cin>> e;

    graph.assign(v,vector<int>());
    visited.assign(v,false);
    disc.assign(v,-1);
    fin.assign(v,-1);

    int m,n,source;
    cout << "Enter the edges: " << endl;
    for(int i=0; i<e; i++) {
        cin >> m >> n;
        graph[m].push_back(n);
    }

    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "The DFS Traversal: ";
    DFS(source);

    cout << "\nThe discovery and finished time: " << endl;
    for(int i=0; i<disc.size(); i++) {
        cout << i << " discovery: " << disc[i] << " finish: " << fin[i] << endl;
    }
}
