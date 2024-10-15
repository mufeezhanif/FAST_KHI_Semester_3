#include <bits/stdc++.h>

using namespace std;
void countSort(int arr[], int n, int exp)
{
    int result[n];
    int i = 0;
    int count[10];

    for (int i = 0; i < 10; ++i)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; ++i)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i)
    {
        result[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; ++i)
    {
        arr[i] = result[i];
    }
}
void radixSort(int arr[], int n)
{
    int exp = 1;
    for (int i = 0; i < 2; ++i)
    {
        exp *= 10;
        countSort(arr, n, exp);
    }
}
int main()
{
    int n = 8;
    int arr[n] = {46, 13, 45, 20, 0, 15, 61, 5};

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    radixSort(arr, n);
    cout << endl
         << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    return 0;
}