#include<bits/stdc++.h>
using namespace std;

#define rep(n) for(int i=0;i<n;++i)
#define print(n) cout<<n
#define N 10

class Hash{
    vector<int> map;
    int numElements;
    float loadFactor;
    public:
    Hash() : numElements(0),loadFactor(0.6)
    {
        map.resize(N,-1);
    }

    int hashFunc(int key)
    {
        return key%map.size();
    }

    void insert(int val)
    {
        if(float(numElements)/map.size()>=loadFactor)
        {
            vector<int> oldMap=map;

            map.resize(2*map.size(),-1);

            rep(oldMap.size())
            {
                if(oldMap[i]!=-1)
                {
                    int index=hashFunc(oldMap[i]);
                    int n=0;
                    index=(index+n*n)%map.size();
                    while(map[index]!=-1)
                    {
                        index=(index+n*n)%map.size();
                    }
                    map[index]=oldMap[i];
                }
            } 
        }
        
        int index=hashFunc(val);
        int n=0;
        index=(index+n*n)%map.size();
        while(map[index]!=-1)
        {
            ++n;
            index=(index+n*n)%map.size();
        }
        map[index]=val;
    }

    void deleteVal(int val)
    {
        int index=hashFunc(val);
        int n=0;
        index=(index+n*n)%map.size();
        while(map[index]!=-1)
        {
            if(map[index]==val)
            {
                map[index]=-1,--numElements;
                break;
            }
            ++n;
            index=(index+n*n)%map.size();
        }

        n=1;
        int newIndex=(index+n*n)%map.size();
        while(map[newIndex]!=-1)
        {
            if(map[newIndex]%map.size()==index)
            {
                map[index]=map[newIndex];
                map[newIndex]=-1;
            }
            ++n;
            newIndex=(index+n*n)%map.size();
        }
    }

    void displayMap()
    {
        rep(map.size())
        {
            print(i)<<" : ";
            print(map[i])<<endl;
        }
    }
};

signed main()
{
    Hash map;
    map.insert(1);
    map.insert(2);
    map.insert(22);
    map.insert(20);
    map.insert(32);
    map.displayMap();
    map.deleteVal(2);
    map.displayMap();
    return 0;
}