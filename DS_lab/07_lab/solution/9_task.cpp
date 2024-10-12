#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i < n / 2; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
        return true;
    }
    return true;
}
void printCompositePrime(int m, int n , vector<int> &prime, vector<int> &composite)
{
    if (m == n + 1)
    {
        return;
    }
    if (isPrime(m))
    {
        prime.push_back(m);
    }
    else{
        composite.push_back(m);
    }
    printCompositePrime(m+1, n, prime, composite);
}
int main()
{
    vector<int> prime, composite;
    printCompositePrime(5, 15, prime, composite);
    cout<<"Prime: ";
    for(int i=0;i<prime.size();++i){
        cout<<prime[i]<<" ";
    }
    cout<<"\nComposite: ";
    for(int i=0;i<composite.size();++i){
        cout<<composite[i]<<" ";
    }
    return 0;
}