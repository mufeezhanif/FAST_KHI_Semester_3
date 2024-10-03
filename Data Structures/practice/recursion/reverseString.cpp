#include <bits/stdc++.h>

using namespace std;

void reverseString(string name, int i = 0)
{
    if (i < name.length())
    {
        reverseString(name, i+1);
    }
    cout << name[i];
}
int main()
{
    string name = "Mufeez";
    int n = 5;
    reverseString(name);

    return 0;
}