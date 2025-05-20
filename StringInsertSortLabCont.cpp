#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of inputs: ";
    cin >> n;

    string c;
    cout << "Enter the characters of n length: ";
    cin >> c;

    int j;
    char key;
    for(int i=1; i<n; i++) {
        key = c[i];
        j = i-1;
        while (c[j]>key && j>=0) {
            c[j+1] = c[j];
            --j;
        }
        c[j+1] = key;
    }

    cout << "The sorted array: ";
    for(int i=0; i<n; i++) {
        cout << c[i] << " ";
    }
}
