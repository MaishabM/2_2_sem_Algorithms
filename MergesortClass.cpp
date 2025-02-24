#include<bits/stdc++.h>
using namespace std;

void print(int n,int a[])
{
    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
}

void sorted(int a[],int l,int m,int r)
{
    int len1 = m-l+1;
    int len2 = r-m;

    vector<int> left(len1),right(len2);

    for(int i=0; i<len1; i++)
    {
        left[i] = a[i+l];
    }
    for(int j=0; j<len2; j++)
    {
        right[j] = a[m+1+j];
    }

    int i=0,j=0,k=l;
    while(i<len1 && j<len2)
    {
        cout << "\nMerged array element: ";
        if(left[i] < right[j]) {
            a[k] = left[i];
            cout << a[k] << " ";
            i++;
        }
        else
        {
            a[k] = right[j];
            cout<< a[k] << " ";
            j++;
        }
        k++;
    }

    while(i<len1)
    {
        a[k] = left[i];
        cout << "\nMerged array element: " <<a[k] <<endl;
        i++,k++;
    }
    while(j<len2)
    {
        a[k] = right[j];
        cout << "\nMerged array element: " <<a[k] << endl;
        j++,k++;
    }
}

void merge(int n,int a[],int l,int r)
{
    if(l<r)
    {
        int m = (l+r)/2;

        cout << "\n left = " << l << " Right= " << r << " Mid= " << m;
        cout << "\n The left part: ";
        for(int i=0; i<=m; i++) {
            cout << a[i] << " ";
        }
        cout << "\n The right part: ";
        for(int i=m+1; i<=r; i++) {
            cout << a[i] << " ";
        }
        cout << endl;

        merge(n,a,l,m);
        merge(n,a,m+1,r);

        sorted(a,l,m,r);
    }
}

int main()
{
    int n;
    cout << "Enter length of array: ";
    cin >> n;

    int a[n];
    cout << "Enter array elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }

    merge(n,a,0,n-1);

    cout << "\nThe sorted array: ";
    print(n,a);
}
