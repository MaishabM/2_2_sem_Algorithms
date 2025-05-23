#include<bits/stdc++.h>
using namespace std;

void findSCS(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();

    int dp[n1+1][n2+1];
   // char dir[n1+1][n2+1];

    for(int i=0; i<=n1; i++) dp[i][0] = 0;
    for(int i=0; i<=n2; i++) dp[0][i] = 0;

   // for(int i=0; i<=n1; i++) dir[i][0] = '0';
   // for(int i=0; i<=n2; i++) dir[0][i] = '0';

    for(int i=1; i<=n1; i++) {
        for(int j=1; j<=n2; j++) {
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
              //  dir[i][j] = 'D';
            }
            else {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    int i = n1, j = n2;
    string ans = "";
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            ans += s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            ans += s1[i-1];
            i--;
        }
        else {
            ans += s2[j-1];
            j--;
        }
    }

    while(i > 0) {
        ans+= s1[i-1];
        i--;
    }

    while(j > 0) {
        ans+= s2[j-1];
        j--;
    }

    reverse(ans.begin(),ans.end());
    cout << "The SCS: " << ans << endl;
    cout << "The length of SCS: " << ans.size() << endl;
   // cout << "The shortest common super sequence length: " << n1+n2-ans.size() << endl;
}

int main() {
    string s1,s2;
    cout << "Enter two strings: " << endl;
    cin >> s1 >> s2;

    findSCS(s1,s2);
}
