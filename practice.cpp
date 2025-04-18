#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter the length of array: ";
    cin>>n;

    int a[n];
    cout << "Enter the array inputs: ";
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    int c = 0;

    for(int i=0; i<n; i++) {
        bool flag = false;
        cout << "Pass " << i+1 << ": " << endl;
        for(int j=0; j<n-i-1; j++) {
            cout << "Before swap: " << a[j] << " , " << a[j+1] << endl;
            if(a[j+1] < a[j]) {
                swap(a[j+1],a[j]);
                flag = true;
            }
            cout << "After swap: " << a[j] << " , " << a[j+1] << endl;
            c++;
        }
        if(flag == false) break;
        cout << endl;
    }

    cout << "\nThe sorted array: ";
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << "\nThe minimum number of swaps: " << c << endl;
}
