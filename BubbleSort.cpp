#include <iostream>
#include <vector>
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
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j + 1] < a[j])
            {
                // Swap elements using a temporary variable
                int temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }

    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
