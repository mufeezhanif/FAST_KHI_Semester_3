#include <bits/stdc++.h>

using namespace std;
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j + 1], arr[j]);
            }
        }
    }
}

void binarySearch(int arr[], int key, int n)
{
    // array is sorted
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + ((right - left) / 2);
        if (arr[mid] == key)
        {
            cout << "Key found at index " << mid << endl;
            return;
        }
        if (arr[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << "Value not found" << endl;
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

    int n = 11;
    int arr[] = {1, 3, 12, 0, 14, 23, 34, 5, 65, 75, 78};
    printArr(arr, n);
    bubbleSort(arr, n);
    printArr(arr, n);
    binarySearch(arr, 0, n); // mine id is 0800
    return 0;
}