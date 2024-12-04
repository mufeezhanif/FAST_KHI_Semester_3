#include <bits/stdc++.h>

using namespace std;
void sortDesc(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j + 1] > arr[j])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void sortAccToArr(int arr1[], int arr2[], int n1, int n2)
{
    int j = 0, k = 0;
    while (j < n2)
    {

        for (int l = 0; l < n1; ++l)
        {
            if (arr1[l] == arr2[j])
            {
                int ind = l;
                while (ind > k)
                {
                    int temp = arr1[ind - 1];
                    arr1[ind - 1] = arr1[ind];
                    arr1[ind] = temp;
                    --ind;
                }
                arr1[k] = arr2[j];
                ++k;
            }
        }
        ++j;
    }
}
int main()
{
    cout << "23k0800" << endl;
    int n1 = 7, n2 = 2;
    int arr1[n1] = {5, 3, 5, 2, 3, 4, 2};
    int arr2[n2] = {5, 2};
    sortDesc(arr2, n2);
    sortAccToArr(arr1, arr2, n1, n2);
    for (int i = 0; i < n1; ++i)
    {
        cout << arr1[i] << " ";
    }
    return 0;
}