#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &adj, int source) {
    int size = adj.size();
    stack<int> st;
    vector<bool> visited(size,false);
    vector<int> parent(size,-1);

    st.push(source);
    visited[source] = true;

    cout << "DFS traversal: ";
    while(st.empty() == false) {
        int node = st.top();
        st.pop();
        cout << node << " ";

        for(auto neighbour : adj[node]) {
            if(visited[neighbour] == true) continue;

            visited[neighbour] = true;
            st.push(neighbour);
            parent[neighbour] = node;
        }
        }

        cout << "\nThe parent of each node: " << endl;
        for(int i = 0; i<size; i++) {
            cout << "Node " << i << " parent : " << parent[i] << endl;
    }
}

void addedge(vector<vector<int>> &adj, int s,int p) {
    adj[s].push_back(p);
    adj[p].push_back(s);
}

int main() {
    int numOfVertex = 6;
    vector<vector<int>> adj(numOfVertex);

    vector<vector<int>> graph = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}};

    for(auto &g : graph) {
        addedge(adj,g[0],g[1]);
    }

    int source = 0;
    cout << "The graph traversal from source: " << source << endl;
    DFS(adj,source);
}