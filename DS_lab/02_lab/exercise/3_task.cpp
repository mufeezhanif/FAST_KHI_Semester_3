#include <bits/stdc++.h>

using namespace std;

class friendsArr
{
public:
    bool **basePtr;
    // implementing 3 rule
    friendsArr()
    {
        basePtr = new bool *[5];
        for (int i = 0; i < 5; ++i)
        {
            basePtr[i] = new bool[5];
        }
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                basePtr[i][j] = false;
            }
        }
        basePtr[0][1] = true;
        basePtr[0][3] = true;
        basePtr[0][4] = true;
        basePtr[1][0] = true;
        basePtr[1][2] = true;
        basePtr[1][4] = true;
        basePtr[2][1] = true;
        basePtr[3][0] = true;
        basePtr[3][4] = true;
        basePtr[4][0] = true;
        basePtr[4][1] = true;
        basePtr[4][3] = true;
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                cout << *(*(basePtr + i) + j) << " ";
            }
            cout << endl;
        }
    }

    void checkFriends(int a, int b)
    {
        bool flag = false;
        for (int k = 0; k < 5; ++k)
        {
            if (basePtr[a][k] == true && basePtr[b][k] == true)
            {

                cout << a << " and " << b << " have a common friend at " << k << endl;
                flag = true;
            }
        }
        if (!flag)
            cout << "They do not have any common friends" << endl;
    }

    ~friendsArr()
    {
        for (int i = 0; i < 5; ++i)
        {
            delete[] basePtr[i];
        }
        delete[] basePtr;
    }
};
int main()
{
    friendsArr *ptr = new friendsArr();
    ptr->checkFriends(0, 4);
    // please enter your desired number to check all the cases
    ptr->checkFriends(1, 2);
    ptr->checkFriends(1, 3);
    return 0;
}
