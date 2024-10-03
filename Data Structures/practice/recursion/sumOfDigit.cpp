#include <bits/stdc++.h>

using namespace std;

int sumOfDigit(int n)
{
    if (n / 10 == 0)
    {
        return n;
    }
    else
    {
        return n % 10 + sumOfDigit(n / 10);
    }
}
int main()
{
    int number = 12345;

    cout << sumOfDigit(number);

    return 0;
}