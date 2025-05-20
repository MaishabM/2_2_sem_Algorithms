#include<bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<vector<int>> graph;
vector<int> dist;

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    dist[start] = 0;
    cout << "The BFS traversal: ";

    while(!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for(auto neighbour : graph[current]) {
            if(!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
                dist[neighbour] = dist[current] + 1;
            }
        }
    }
    cout << "\nThe distance from source: " << endl;
    for(int i=0; i<dist.size(); i++) {
        cout << start << " -> node " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int v,e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    graph.assign(v,vector<int>());
    visited.assign(v,false);
    dist.assign(v,-1);

    cout << "Enter the edges: " << endl;
    for(int i=0; i<e; i++) {
        int m,n;
        cin >> m >> n;

        graph[m].push_back(n);
        graph[n].push_back(m);
    }

    int source;
    cout << "Select the root vertex: ";
    cin >> source;
    BFS(source);
}
