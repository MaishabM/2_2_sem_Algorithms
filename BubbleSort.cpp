#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter length of array: ";
    cin >> n;

    vector<int> a(n); // Use vector for dynamic arrays
    cout << "Enter unsorted array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        cout << "Pass " << i+1 << endl;
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "Before swap: " << a[j] << " " << a[j+1] << endl;
            if (a[j + 1] < a[j])
            {
                swap(a[j],a[j+1]);
                flag = true;
            }
            cout << "After swap: " << a[j] << " " << a[j+1] << endl;
        }
        cout << "\nArray: ";
        for(int k=0; k<n; k++) {
            cout << a[k] << " ";
        }
        cout << endl;

        if(flag == false) break;
    }

    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
