#include <bits/stdc++.h>

using namespace std;

int findMax(int *arr, int n)
{
    int max = arr[0];

    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
void countSort(int *arr, int n, int exp)
{
    int result[n];
    int i = 0;
    int count[10] = {0};

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
int* radixSort(int *arr1, int *arr2, int n)
{
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        if (i < 10)
            arr[i] = arr1[i];
        else
            arr[i] = arr2[i - 10];
    }
    int max = findMax(arr, n);
    int exp = 1;
    for (; max / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
    return arr;
}
int main()
{
    int *arr1 = new int[10];
    int *arr2 = new int[10];

    for (int i = 0; i < 10; ++i)
    {
        cin >> arr1[i];
        cin >> arr2[i];
    }
    int *arr = radixSort(arr1, arr2, 20);
    cout << "Using radix sort: " << endl;
    for (int i = 0; i < 20; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    arr = mergeSort();
    cout << "Using Merge sort: " << endl;
    for (int i = 0; i < 20; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
/*
43 53 9 24 0 24 8 19 1 0 24 54 2 1 58 34 2 5 1 80

*/