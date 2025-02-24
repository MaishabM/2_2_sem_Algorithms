#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter length of array: ";
    cin >> n;

    int a[n];
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int mini;
    for(int i=0; i<n-1; i++) {
            mini = i;
        for(int j=i+1; j<n; j++) {
            if(a[mini]>a[j])
                mini = j;
        }
        swap(a[i],a[mini]);
    }

    cout << "Sorted array: ";
    for(int i=0; i<n; i++) {
        cout << a[i] << " " ;
    }
}
