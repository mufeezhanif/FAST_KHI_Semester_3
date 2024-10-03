#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    int arr1[m];

    cout << "Enter contents for arr1: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << "Enter contents for arr2: " << endl;
    for (int i = 0; i < m; ++i)
    {
        cin >> arr1[i];
    }

    
    return 0;
}