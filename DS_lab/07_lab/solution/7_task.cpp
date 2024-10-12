#include <bits/stdc++.h>

using namespace std;

void printNumbers(int n){
    if(n==0){
        return;
    }
    printNumbers(n-1);

    if(n%2==0){
        cout<<n-1<<" ";
    }
    else{

        cout<<n+1<<" ";
    }
}
int main()
{
    printNumbers(10);

    return 0;
}