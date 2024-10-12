#include <bits/stdc++.h>

using namespace std;

int calculateMean(int arr[], int n, int i = 0, int sum = 0)
{

    if (i < n)
    {
        i +=1;
        return calculateMean(arr, n,i , sum + arr[i-1]);
    }
    else
    {
        return sum / n;
    }
}
int main()
{
    int n = 5;
    int arr[] = {2, 4, 6, 8, 10};
    cout<<"healllo"<<endl;
    cout << calculateMean(arr, n);
    return 0;
}