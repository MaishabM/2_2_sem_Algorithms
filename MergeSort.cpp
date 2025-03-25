#include<bits/stdc++.h>
using namespace std;

void print(int n,int a[]) {
    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merging(int a[],int l,int m,int r) {
    int len1 = m-l+1;
    int len2 = r-m;

    vector<int> left(len1),right(len2);

    // copying values of array a into left and right arrays
    for(int i=0; i<len1; i++) {
        left[i] = a[l+i];
    }

    for(int j=0; j<len2; j++) {
        right[j] = a[m+1+j];
    }

    int i=0,j=0,k=l;
    //cout << "l = " << l << endl;

    while(i<len1 && j<len2) {
        if(left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        }
        else {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    //any remaining elements
    while(i<len1) {
        a[k] = left[i];
        i++,k++;
    }

    while(j<len2) {
        a[k] = right[j];
        j++,k++;
    }
}

void mergesort(int a[],int l, int r) {
    if(l<r) {
        int mid = (l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);

        merging(a,l,mid,r);
    }
}

int main() {
     int n;
     cout << "Enter number of elements: ";
     cin>> n;

     int a[n];
     cout << "Enter array elements: ";

     for(int i=0; i<n; i++) {
        cin>> a[i];
     }

    //  cout << "The unsorted array: " << endl;
    //  print(n,a);

     mergesort(a,0,n-1);

     cout << "The sorted array: " << endl;
     print(n,a);
}
