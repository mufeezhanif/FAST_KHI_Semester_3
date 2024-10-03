#include <iostream>
using namespace std;

bool valid(int curri, int currj, int maze[5][5], int sol[5][5])
{
    if (curri ==4 && currj==4)
    {
        return true;
    }
    return false;
}

bool func(int maze[5][5], int sol[5][5], int curri, int currj)
{

    if (curri == 4 && currj == 4)
    {
        sol[curri][currj] = 1;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << sol[i][j];
            }
            cout << endl;
        }
        return true;
    }

    if (valid(curri, currj, maze, sol))
    {
        sol[curri][currj] = 1;

        if (func(maze, sol, curri + 1, currj))
        {
            return true;
        }

        if (func(maze, sol, curri, currj + 1))
        {
            return true;
        }

        if (func(maze, sol, curri - 1, currj))
        {
            return true;
        }

        if (func(maze, sol, curri, currj - 1))
        {
            return true;
        }

        sol[curri][currj] = 0;
        return false;
    }
    return false;
}

int main()
{
    cout << "\t\t23K3033-Uzair Haroon" << endl;
    int maze[5][5] = {
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 1, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 1}};

    int sol[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }
    cout << endl;

    if (!func(maze, sol, 0, 0))
    {
        cout << "No Possible Paths" << endl;
    }

    return 0;
}