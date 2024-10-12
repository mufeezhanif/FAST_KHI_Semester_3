#include <bits/stdc++.h>

using namespace std;

struct Runner
{
    string name;
    int time;
};
void merge(Runner arr[], int l, int m, int r)
{
    int s1 = m - l + 1;
    int s2 = r - m;

    Runner left[s1], right[s2];
    for (int i = 0; i < s1; ++i)
    {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < s2; ++i)
    {
        right[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < s1 && j < s2)
    {
        if (left[i].time <= right[j].time)
        {
            arr[k++] = left[i++];
        }
        else
            arr[k++] = right[j++];
    }
    while (i < s1)
    {
        arr[k++] = left[i++];
    }
    while (j < s2)
    {
        arr[k++] = right[j++];
    }
}

void mergeSort(Runner arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = ((high - low) / 2) + low;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int n = 10;
    Runner arr[n];

    for (int i = 0; i < n; ++i)
    {
        cout << "Enter name and time of runner " << i << " ";
        cin >> arr[i].name;
        cin >> arr[i].time;
    }
    mergeSort(arr, 0, n - 1);
    cout << endl
         << endl;
    for (int i = 0; i < 5; ++i)
    {
        cout <<i<< ". " <<arr[i].name << " - " << arr[i].time <<" seconds"<< endl;
    }
    return 0;
}
/*
Mufeez 10
Ahsan 2
 Harroon 4
Someone 20
None 0
Any 10
Koi 1
Hamza 32
Aon 10
Muz 2
*/
