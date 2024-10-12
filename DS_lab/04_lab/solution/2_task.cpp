#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int n)
{

    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    int mid = floor(n / 2);
    int temp = arr[n - 1], j = n - 1;
    while (j > mid)
    {
        arr[j] = arr[j - 1];
        --j;
    }
    arr[mid] = temp;
}

void printArr(int arr[], int n)
{
    cout << "Printing array: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int n = 9;
    int arr[] = {20, 12, 15, 2, 10, 1, 13, 9, 5};
    printArr(arr, n);
    insertionSort(arr, n);
    printArr(arr, n);
    return 0;
}