#include <bits/stdc++.h>
//WRONG ANSWER
using namespace std;

int calSumOfArr(vector<int> arr, int i , int sum = 0)
{
    if (i == 0)
    {
        return sum;
    }
    return calSumOfArr(arr, i - 1, sum + arr[i]);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 100};
    cout << calSumOfArr(arr, arr.size());

    return 0;
}