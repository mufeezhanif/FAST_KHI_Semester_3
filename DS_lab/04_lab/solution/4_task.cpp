#include <bits/stdc++.h>

using namespace std;
void checkDuplicate(int arr[], int n)
{
    bool flag = false;
    for (int i = 0; i < n && !flag; ++i)
    {
        for (int j = 0; j < n && !flag; ++j)
        {
            if (j == i)
                continue;
            if (arr[i] == arr[j])
            {
                flag = true;
            }
        }
    }
    if (flag)
        cout << "Array contains duplicate" << endl;
    else
        cout << "Array does not contain duplicate" << endl;
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

    int n = 5;
    int arr[] = {1,2,3,4,5};
    printArr(arr, n);
    checkDuplicate(arr, n);
    return 0;
}