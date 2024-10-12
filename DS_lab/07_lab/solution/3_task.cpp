// Task 3: Take an array as input, which needs to be sorted according to the contents of the 2nd array. The user should input values for n (length of 1st array) and m (length of 2nd array) and the contents of both these arrays. The contents of the first array should be sorted according to the 2nd, without interrupting the order of the other elements. For example:
// Input:
// N = 6, arr1 = {7,13,4,7,10,4}
// M = 2, arr2 = {7,4}
// Output:
// Arr1 = {7,7,4,4,13,10}
// According to the contents of the 2nd array, all 7’s should come first. Then all 4’s.. And the order of the other elements should not be disturbed.
#include <bits/stdc++.h>

using namespace std;
void sortArr(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0, k = 0;

    while (i < n)
    {
        int key = arr2[i];
        j=0;
        while (j < m)
        {
            if (arr1[j] == key && j == k)
            {
                ++j;
                ++k;
                continue;
            }
            else if (arr1[j] != key)
            {
                ++j;
            }
            else if (arr1[j] == key)
            {
                int l = j;
                while (l != k)
                {
                    arr1[l] = arr1[l - 1];
                    l--;
                }
                arr1[k++] = key;
                ++j;
            }
        }
        ++i;
    }
}

void displayArr(int arr1[], int m)
{
    for (int i = 0; i < m; ++i)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
}
int main()
{
    int m, n;
    cin >> m >> n;
    int arr1[m];
    int arr2[n];
    for (int i = 0; i < m; ++i)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> arr2[i];
    }
    sortArr(arr1, arr2, m, n);
    displayArr(arr1, m);
    return 0;
}
/*
6 2 7 13 4 7 10 4 7 4 
*/
// 6
// 2
// 7 13 4 7 10 4
// 7 4