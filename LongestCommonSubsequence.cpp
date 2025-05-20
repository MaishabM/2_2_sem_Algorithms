#include <bits/stdc++.h>
using namespace std;

void findLCS(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    
    int dp[n+1][m+1];
    char dir[n+1][m+1];
    
    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int i=0; i<=m; i++) dp[0][i] = 0;
    for(int i=0; i<=n; i++) dir[i][0] = '0';
    for(int i=0; i<=m; i++) dir[0][i] = '0';

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                dir[i][j] = 'D';  // Diagonal
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                dir[i][j] = 'U';  // Up
            }
            else{
                dp[i][j] = dp[i][j-1];
                dir[i][j] = 'L';  // Left
            }
        }
    }

    string ans = "";
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(dir[i][j] == 'D'){
            ans += s1[i-1];
            i--; j--;
        }
        else if(dir[i][j] == 'U') i--;
        else j--;
    }
    
    reverse(ans.begin(), ans.end());

    cout << "Longest Common Subsequence: " << ans << endl;
    cout << "LCS Length: " << ans.size() << endl;
}

int main() {
    string s1, s2;
    cout << "Enter two strings: " << endl;
    cin >> s1 >> s2;
    findLCS(s1, s2);
    return 0;
}
