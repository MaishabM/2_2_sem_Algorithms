#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of inputs: ";
    cin >> n;

    string c;
    cout << "Enter the characters of length n: ";
    cin >> c;

    for (int i=0; i<n; i++) {
        //cout << "Pass " << i << ": ";
        for(int j=0; j<n-i-1; j++) {
           // cout << "Before swap: " << c[j] << ", " << c[j+1] << endl;
            if (c[j] > c[j+1]) {
                swap(c[j],c[j+1]);
            }
           // cout << "After swap: " << c[j] << ", " << c[j+1] << endl;
        }
    }
    cout << "The sorted string: ";
    for (int i=0; i<n; i++) {
        cout << c[i] << " ";
    }
}
