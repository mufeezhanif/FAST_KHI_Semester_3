#include <bits/stdc++.h>

using namespace std;

void giveCombinations(int n,int k, vector<vector<int>>&vect , int count =1){
    vector<int> temp;
    if(count==n){
        return;
    }
    temp.push_back(count);
    int i=1, j = count+1;
    while(i<k && j<=n){
        temp.push_back(j);
    }
    vect.push_back(temp);
    
    giveCombinations(n,k,vect,count+1);
}

int main()
{
    vector<vector<int>> vect;
    cout<<"Hello";
    giveCombinations(4, 2, vect);
    for (int i = 0; i < vect.size(); ++i)
    {
        for (int j = 0; j < vect[i].size(); ++j)
        {
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}