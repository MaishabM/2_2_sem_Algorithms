#include <bits/stdc++.h>
using namespace std;

void printMatrix(const vector<vector<int>>& mat, const string& name) {
    cout << name << endl;
    for (int i = 1; i < mat.size() - 1; ++i) {
        for (int j = 2; j < mat.size(); ++j) {
            if (i >= j) 
                cout << "   -  ";
            else
                cout << setw(5) << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printOptimalParens(const vector<vector<int>>& K, int i, int j) {
    if (i == j) {
        cout << " A" << i << " ";
        return;
    }

    cout << "(";
    printOptimalParens(K, i, K[i][j]);
    printOptimalParens(K, K[i][j] + 1, j);
    cout << ")";
}

void matrixChainOrder(const vector<int>& p) {
    int n = p.size() - 1;

    vector<vector<int>> M(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> K(n + 1, vector<int>(n + 1, 0));

    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            M[i][j] = INT_MAX;

            for (int k = i; k < j; ++k) {
                int cost = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < M[i][j]) {
                    M[i][j] = cost;
                    K[i][j] = k;
                }
            }
        }
    }

    printMatrix(M, "M");
    printMatrix(K, "K");

    cout << "Optimal Parenthesization: ";
    printOptimalParens(K, 1, n);
    cout << endl;

    cout << "Minimum number of multiplications: " << M[1][n] << endl;
}

int main() {
    vector<int> dims = {10, 20, 30, 40, 50};
    matrixChainOrder(dims);
}