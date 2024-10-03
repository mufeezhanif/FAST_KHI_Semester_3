#include <bits/stdc++.h>
#include "matrix_multiply.cpp"
using namespace std;

int main()
{
    int arr1[][3] = {
        {2, 3, 4},
        {5, 6, 7},
        {9, 5, 3}};
    int arr2[][3] = {
        {2, 2, 4},
        {6, 6, 7},
        {2, 6, 3}};
    cout << "Printing arr1: "
         << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << "Printing arr2: " << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    };
    multiplyArray(arr1, arr2);
    return 0;
}