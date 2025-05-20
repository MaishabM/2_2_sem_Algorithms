#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int MAXW = 1000;

void knapsack(int n,int w[],int v[],int mw) {
    int dp[MAXN][MAXW] = {0};

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=mw; j++) {
            if(w[i-1] <= j)
                dp[i][j] = max(dp[i-1][j], v[i-1]+dp[i-1][j-w[i-1]]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << "The dp table: " << endl;
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=mw; j++) {
            cout << setw(3) << dp[i][j] << " ";
        }
        cout << endl;
    }

    int j=mw;
    cout << "\nTaking items: ";
    for(int i=n; i>0; --i) {
        if(dp[i][j] != dp[i-1][j]) {
            cout << i << " ";
            j -= w[i-1];
        }
    }

    cout << "\nThe maximum value: " << dp[n][mw] << endl;
}

int main() {
    int n,mw;
    cout << "Enter the number of items: ";
    cin >> n;
    int w[n],v[n];
    cout << "Enter the weights: ";
    for(int i=0; i<n; i++) {
        cin >> w[i];
    }
    cout << "Enter the values: ";
    for(int i=0; i<n; i++){
        cin>> v[i];
    }
    cout << "Enter the maximum capacity: ";
    cin >> mw;

    knapsack(n,w,v,mw);
}
