#include<bits/stdc++.h>
using namespace std;

vector<int> merge2array(int a[],int b[],int m,int n) {
    vector<int> res;

    int i = 0, j = 0;
    while (i < m && j < n) {
        if(a[i] <= b[j]) {
          res.push_back(a[i]);
          i++;
        }
        else {
          res.push_back(b[j]);
          j++;
        }

    }
    while (i < m) {
        res.push_back(a[i]);
        i++;
    }
    while (j < n) {
        res.push_back(b[j]);
        j++;
    }
    return res;
}

int main() {
    int m,n;
    cout << "Enter the length of first array: ";
    cin>> m;
    cout << "Enter the length of second array: ";
    cin>> n;

    int a[m],b[n];
    cout << "Enter the first sorted array: ";
    for(int i=0; i<m; i++) {
        cin >> a[i];
    }
    cout << "Enter the second sorted array: ";
    for(int i=0; i<n; i++) {
        cin >> b[i];
    }

    vector<int> res = merge2array(a,b,m,n);

    cout << "The final sorted array: ";
    for(int x : res) {
        cout << x << " ";
    }
}
