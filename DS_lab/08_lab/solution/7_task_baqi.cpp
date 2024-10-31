#include <iostream>
using namespace std;
void printArr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
        cout<<endl;
}
int partition(int a[], int start, int end, int selection, int &count)
{
    int pivot;
    if (selection == 0)
        pivot = a[start];
    else if (selection == 1)
        pivot = a[end];
    else if (selection == 2)
    {
        srand(time(0));
        int r = start + (rand() % (end - start + 1));
        pivot = a[r];
    }
    else if (selection == 3)
    {
        pivot = a[((end - start) / 2) + start];
    }
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            ++count;
        }
    }
    int t = a[i + 1];
    a[i + 1] = a[end];
    a[end] = t;
    ++count;
    return i + 1;
}

void quick(int a[], int start, int end, int selection, int &count)
{
    if (start < end)
    {
        int p = partition(a, start, end, selection, count);
        quick(a, start, p - 1, selection, count);
        quick(a, p + 1, end, selection, count);
    }
}
void quickSort(int arr[], int selection, int n)
{
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        a[i] = arr[i];
    }
    int count = 0;
    quick(a, 0, n - 1, selection, count);
    cout << "Comparisions: " << count << endl;
    printArr(a, n);
}


int main()
{
    int n = 10;
    int arrRandom[n] = {34, 54, 76, 54, 24, 87, 1, 6, 8, 45};
    int arrSorted[n] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int arrReverse[n] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    cout << "First Element selected as pivot" << endl;
    cout << "Random array" << endl;
    quickSort(arrRandom, 0, n);
    cout << "Sorted array" << endl;
    quickSort(arrSorted, 0, n);
    cout << "Reverse array" << endl;
    quickSort(arrReverse, 0, n);

    cout << "Last Element selected as pivot" << endl;
    cout << "Random array" << endl;
    quickSort(arrRandom, 0, n);
    cout << "Sorted array" << endl;
    quickSort(arrSorted, 0, n);
    cout << "Reverse array" << endl;
    quickSort(arrReverse, 0, n);

    cout << "Random Element selected as pivot" << endl;
    cout << "Random array" << endl;
    quickSort(arrRandom, 0, n);
    cout << "Sorted array" << endl;
    quickSort(arrSorted, 0, n);
    cout << "Reverse array" << endl;
    quickSort(arrReverse, 0, n);

    cout << "Median selected as pivot" << endl;
    cout << "Random array" << endl;
    quickSort(arrRandom, 0, n);
    cout << "Sorted array" << endl;
    quickSort(arrSorted, 0, n);
    cout << "Reverse array" << endl;
    quickSort(arrReverse, 0, n);

    return 0;
}