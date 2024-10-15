#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; ++i)
    {
        int minInd = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[minInd] > arr[j])
            {
                minInd = j;
            }
        }
        // if (i == minInd)
        //     break;
        swap(arr[i], arr[minInd]);
        cout << i << " ";
    }
}
void insertionSort(int arr[], int n)
{

    for (int i = 1; i < n; ++i)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            --j;
            cout << j << " ";
        }
        cout << endl;
    }
}
void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}
int mergeQuick(int arr[], int left, int right)
{
    int pivotInd = left;
    int i = left;
    int j = right;
    while (i < j)
    {

        while (arr[pivotInd] >= arr[i] && i <= right - 1)
        {
            ++i;
        }
        while (arr[pivotInd] < arr[j] && j >= left + 1)
        {
            --j;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[pivotInd], arr[j]);
    return j;
}
void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int partInd = mergeQuick(arr, left, right);

        quickSort(arr, left, partInd - 1);
        quickSort(arr, partInd + 1, right);
    }
}

void combineMerge(int arr[], int low, int high, int mid)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int arrLeft[n1], arrRight[n2];
    for (int i = 0; i < n1; ++i)
    {
        arrLeft[i] = arr[low + i];
    }
    for (int i = 0; i < n2; ++i)
    {
        arrRight[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (arrLeft[i] <= arrRight[j])
        {
            arr[k] = arrLeft[i++];
        }
        else
        {
            arr[k] = arrRight[j++];
        }
        ++k;
    }
    while (i < n1)
    {
        arr[k++] = arrLeft[i++];
    }
    while (j < n2)
    {
        arr[k++] = arrRight[j++];
    }
}
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + ((high - low) / 2);
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        combineMerge(arr, low, high, mid);
    }
}
int main()
{
    int n = 270;
    int arr[n] = {6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5, 6, 2, 4, 3, 9, 5};
    mergeSort(arr, 0, n - 1);

    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}