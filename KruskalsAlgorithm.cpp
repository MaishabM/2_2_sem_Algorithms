#include <iostream>
using namespace std;

const int inf = 999999;
int n = 5, ne = 1;  // n = number of nodes
int mincost = 0;
int cost[5][5] = {
    {0, 2, 0, 6, 0}, 
    {2, 0, 3, 8, 5}, 
    {0, 3, 0, 0, 7}, 
    {6, 8, 0, 0, 9}, 
    {0, 5, 7, 9, 0} 
};
int p[5] = {0};  // Parent array for union-find

int applyfind(int i) {
    if (p[i] == 0) return i;
    return p[i] = applyfind(p[i]);  // Path compression
}

bool applyunion(int i, int j) {
    int root_i = applyfind(i);
    int root_j = applyfind(j);
    if (root_i != root_j) {
        p[root_j] = root_i;  // Union by rank not implemented (simplified)
        return true;
    }
    return false;
}

int main() {
    // Replace 0s with infinity, except for diagonal elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && cost[i][j] == 0) {
                cost[i][j] = inf;
            }
        }
    }

    cout << "Minimum Cost Spanning Tree:\n";

    while (ne < n) {
        int min_val = inf, a = -1, b = -1;
        
        // Find the smallest edge
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min_val) {
                    min_val = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if (a == -1 || b == -1) break;  // No valid edges left

        // Find the roots of nodes a and b
        int root_a = applyfind(a);
        int root_b = applyfind(b);

        if (applyunion(root_a, root_b)) {  // If no cycle is formed
            cout << a << " -> " << b << " (Cost: " << min_val << ")\n";
            mincost += min_val;
            ne++;
        }

        // Remove selected edge from consideration
        cost[a][b] = cost[b][a] = inf;
    }

    cout << "Minimum cost = " << mincost << endl;
    return 0;
}