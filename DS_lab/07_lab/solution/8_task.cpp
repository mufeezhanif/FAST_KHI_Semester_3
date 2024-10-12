#include <bits/stdc++.h>

using namespace std;

int retTerm(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return retTerm(n - 1) + n;
}

void printSeq(int n)
{
    for (int i = 1; i < n; ++i)
    {
        cout << retTerm(i) << " ";
    }
}
int retFibonacci(int n)
{
    if (n < 2)
    {
        return n;
    }

    return retFibonacci(n - 1) + retFibonacci(n - 2);
}
void printfibonacci(int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << retFibonacci(i) << " ";
    }
}
int main()
{
    printSeq(7);
    cout << endl
         << endl;
    printfibonacci(13);
    return 0;
}