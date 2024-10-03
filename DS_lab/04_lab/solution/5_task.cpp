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

    int n = 6;
    int arr[] = {2022, 2023, 2024, 2022, 2023, 2024};
    printArr(arr, n);
    bubbleSort(arr, n);
    printArr(arr, n);
    return 0;
}