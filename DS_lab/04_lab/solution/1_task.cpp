#include <bits/stdc++.h>

using namespace std;

void selectionSort(int arr[], int n, int a, int b)
{
    if (a == b)
        return;
    else if (b > a)
    {
        for (int i = a; i < b; ++i)
        {
            int min = i;

            for (int j = i + 1; j < b + 1; ++j)
            {
                if (arr[j] < arr[min])
                {
                    min = j;
                }
            }
            swap(arr[i], arr[min]);
        }
    }
    else
    {
        // sorting from 0 to b
        for (int i = 0; i < b; ++i)
        {
            int min = i;

            for (int j = i + 1; j < b + 1; ++j)
            {
                if (arr[j] < arr[min])
                {
                    min = j;
                }
            }
            swap(arr[i], arr[min]);
        }
        // sorting from a to n

        for (int i = a; i < n - 1; ++i)
        {
            int min = i;

            for (int j = i + 1; j < n; ++j)
            {
                if (arr[j] < arr[min])
                {
                    min = j;
                }
            }
            swap(arr[i], arr[min]);
        }
    }
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

    int n = 8;
    int arr[] = {9, 8, 4, 5, 23, 154, 32, 2};
    int a = 5, b = 2;
    printArr(arr, n);
    selectionSort(arr, n, a, b);
    printArr(arr, n);
    return 0;
}