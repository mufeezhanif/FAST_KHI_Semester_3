#include <bits/stdc++.h>
using namespace std;

int sum(int i, int cols, int *arr)
{
    if (cols == i)
        return 0;

    return arr[i] + sum(i + 1, cols, arr);
}

int rows;
int recursiveArraySum(int *arr[], int sizes[], int dim)
{
    int sumOfRow = sum(0, sizes[dim], arr[dim]);
    if (dim == rows)
    {
        return sumOfRow;
    }

    return sumOfRow + recursiveArraySum(arr, sizes, dim + 1);
}

int main()
{
    cin >> rows;
    int **array = new int *[rows];
    int *sizes = new int[rows];

    for (int i = 0; i < rows; i++)
    {
        cin >> sizes[i];
        array[i] = new int[sizes[i]];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < sizes[i]; j++)
        {
            cin >> array[i][j];
        }
    }

    cout << "Total Sum: " << recursiveArraySum(array, sizes, 0) << endl;
    return 0;
}

/*
input values
4
4 3 1 5
2 3 5 6
3 2 1
1 
4 5 6 2 1

output : 41
*/