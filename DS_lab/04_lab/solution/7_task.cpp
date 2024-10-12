#include <bits/stdc++.h>

using namespace std;
void bubbleSort(string arr[], int n)
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
void printArr(string arr[], int n)
{
    cout << "Printing array: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void linearSearch(string name, string arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == name)
        {
            cout << name << " found at index " << i << " , count is " << i + 1 << endl;
            return;
        }
    }
    cout << name << " not found in the given array, count is " << n << endl;
}

void binarySearch(string arr[], string key, int n)
{
    // array is sorted
    int left = 0, right = n - 1, i = 0;
    while (left <= right)
    {
        i++;
        int mid = left + ((right - left) / 2);
        if (arr[mid] == key)
        {

            cout << key << " found at index " << mid << " , count is " << i << endl;
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
    cout << key << " not found in the given array, count is " << i<<endl;
}

int main()

{

    int n = 10;
    string arr[] = {"Ahmed", "Ali", "Basit", "Karim", "Rizwan", "Sarwar", "Tariq", "Taufiq", "Yasin", "Zulfiqar"};
    printArr(arr, n);
    linearSearch("Aftab", arr, n);
    linearSearch("Rizwan", arr, n);
    linearSearch("Tariq", arr, n);
    bubbleSort(arr, n);
    printArr(arr, n);
    binarySearch(arr, "Aftab", n);
    binarySearch(arr, "Rizwan", n);
    binarySearch(arr, "Tariq", n);

    // After observing the output, it can be easily seen that binary search is optimized and the linear search uses more time to search a value
    return 0;
}