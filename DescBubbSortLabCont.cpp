#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of input: ";
    cin >> n;

    if (n<=10) {
        int a[n];
        cout << "Enter the elements: ";
        for (int i=0; i<n; i++){
            cin >> a[i];
        }

        for (int i=0; i<n; i++) {
            bool flag = false;
            cout << "Pass " << i+1 << ": " << endl;
            for (int j=0; j<n-i-1; j++) {
                cout << "Before swap: " << a[j] << ", " << a[j+1] << endl;
                if(a[j]<a[j+1]) {
                    swap(a[j],a[j+1]);
                    flag = true;
                }
                cout << "After swap: " << a[j] << ", " << a[j+1]<< endl;
            }
            if (flag == false) break;
        }
        cout << "The sorted array (descending): ";
        for (int i=0; i<n; i++) {
            cout << a[i] << " ";
        }
    }
}
