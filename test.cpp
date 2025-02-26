#include <bits/stdc++.h>
using namespace std;

void print(int n, int a[]) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void sorted(int a[], int l, int m, int r) {
    int len1 = m - l + 1;
    int len2 = r - m;

    vector<int> left(len1), right(len2);

    // Copying elements into left and right arrays
    for (int i = 0; i < len1; i++) {
        left[i] = a[i + l];
    }
    for (int j = 0; j < len2; j++) {
        right[j] = a[m + 1 + j];
    }

    // Printing the subarrays being merged
    cout << "\nMerging Left [" << l << "," << m << "]: ";
    for (int i : left) cout << i << " ";
    cout << "\nMerging Right [" << m + 1 << "," << r << "]: ";
    for (int i : right) cout << i << " ";
    cout << endl;

    // Merge process
    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i] < right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        cout << "Merged element: " << a[k] << endl;
        k++;
    }

    // Copy remaining elements from left
    while (i < len1) {
        a[k] = left[i];
        cout << "Merged element: " << a[k] << endl;
        i++, k++;
    }

    // Copy remaining elements from right
    while (j < len2) {
        a[k] = right[j];
        cout << "Merged element: " << a[k] << endl;
        j++, k++;
    }

    // Print array after merging
    cout << "Array after merging [" << l << "," << r << "]: ";
    for (int i = l; i <= r; i++) cout << a[i] << " ";
    cout << endl;
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        cout << "\nDividing array: Left=" << l << " Right=" << r << " Mid=" << m;
        cout << "\nLeft part: ";
        for (int i = l; i <= m; i++) cout << a[i] << " ";
        cout << "\nRight part: ";
        for (int i = m + 1; i <= r; i++) cout << a[i] << " ";
        cout << endl;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        sorted(a, l, m, r);
    }
}

int main() {
    int n;
    cout << "Enter length of array: ";
    cin >> n;

    int a[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    mergeSort(a, 0, n - 1);

    cout << "\nThe sorted array: ";
    print(n, a);

    return 0;
}
