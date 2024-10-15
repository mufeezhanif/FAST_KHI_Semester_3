#include <bits/stdc++.h>

using namespace std;
int findMax(int *arr, int cols)
{
    int max = arr[0];
    for (int i = 1; i < cols; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
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

void radixSort(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        int max = findMax(arr[i], cols);
        for (int exp = 1; max / exp > 0; exp *= 10)
        {
            countSort(arr[i], cols, exp );
        }
    }
}
int main()
{
    int rows = 4;
    int cols = 11;
    int **arr = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
        arr[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {

            cin >> arr[i][j];
        }
    }
    radixSort(arr, rows, cols);
    cout << endl
         << endl
         << "Displaying sorted: " << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {

            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
/*
36 987 654 2 20 99 456 957 555 420 66 3
20 420 2 3 654 555 36 456  66 987 957 99
2 3 20 420 36 654 555 456 957 66 987 99
2 3 20 36 99 420 456 555 654 957 987
*/