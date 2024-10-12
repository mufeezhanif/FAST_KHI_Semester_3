#include <bits/stdc++.h>

using namespace std;

int decimalToBinary(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    else
    {

        return ((n % 2) ) + decimalToBinary(n / 2 ) *10;
    }
}
int main()
{
    int n = 46;
    cout << decimalToBinary(n);

    return 0;
}