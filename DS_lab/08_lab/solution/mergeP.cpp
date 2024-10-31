#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int s1 = m - l + 1;
    int s2 = r - m;

    int left[s1], right[s2];
    for (int i = 0; i < s1; ++i)
    {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < s2; ++i)
    {
        right[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < s1 && j < s2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
            arr[k++] = right[j++];
    }
    while (i < s1)
    {
        arr[k++] = left[i++];
    }
    while (j < s2)
    {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = ((high - low) / 2) + low;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int n = 8;
    int arr[n] = {46, 13, 45, 20, 0, 15, 61, -5};

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    mergeSort(arr, 0, n - 1);
    cout << endl
         << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}