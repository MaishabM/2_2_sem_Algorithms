#include <bits/stdc++.h>
using namespace std;
void knapsack(int n,int w[],int v[],int mw) {
    vector<int> dp(mw+1,0);
    for(int i=0; i<n; i++) {
      for(int j=mw; j>=w[i];j--)
      {
        dp[j]= max(dp[j], v[i]+ dp[j- w[i]]);
      }
    }
    cout << "Maximum value: " << dp[mw];
}

int main() {
    int n,mw;
    cout << "Enter the number of items: ";
    cin >> n;
    int w[n],v[n];
    cout << "Enter weights: ";
    for(int i=0; i<n; i++) {
        cin >> w[i];
    }
    cout << "Enter values: ";
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    cout << "Enter maximum capacity: ";
    cin >> mw;
    knapsack(n,w,v,mw);
}
