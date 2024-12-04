#include <bits/stdc++.h>

using namespace std;
bool isValid(char maze[6][6], char sol[6][6], int n, int &energy, int row, int col)
{
    if (row >= 0 && col >= 0 && row < n && col < n && maze[row][col] != 'D' && maze[row][col] != 'H' && sol[row][col] != 'P')
    {
        return true;
    }
    return false;
}
bool isValid1(char maze[6][6], char sol[6][6], int n, int &energy, int row, int col)
{
    if (row >= 0 && col >= 0 && row < n && col < n && maze[row][col] != 'D' && sol[row][col] != 'P')
    {
        if (maze[row][col] == 'H')
            energy -= 5;
        return true;
    }
    return false;
}
bool findPath(char maze[6][6], char sol[6][6], int n, int energy, int row = 0, int col = 0)
{
    if (row == n - 1 && col == n - 1 && maze[row][col] == 'T')
    {
        sol[row][col] = 'P';
        cout << "\n\tFound , health " << energy << endl;
        return true;
    }
    // no energy, treasurer died
    if (energy == 0)
    {
        return false;
    }
    if (isValid(maze, sol, n, energy, row, col))
    {
        sol[row][col] = 'P';
        if (findPath(maze, sol, n, energy, row, col + 1) || findPath(maze, sol, n, energy, row + 1, col) || findPath(maze, sol, n, energy, row, col - 1) || findPath(maze, sol, n, energy, row - 1, col))
        {
            return true;
        }
        sol[row][col] = '.';
    }
    else if (isValid1(maze, sol, n, energy, row, col))
    {
        sol[row][col] = 'P';
        if (findPath(maze, sol, n, energy, row, col + 1) || findPath(maze, sol, n, energy, row + 1, col) || findPath(maze, sol, n, energy, row, col - 1) || findPath(maze, sol, n, energy, row - 1, col))
        {
            return true;
        }
        sol[row][col] = '.';
    }
    else
    {
        return false;
    }
    return false;
}

int main()
{
    cout << "23k0800" << endl;
    int n = 6;
    char maze[6][6] =
        {{
             'S',
             'P',
             'P',
             'D',
             'H',
             'H',
         },
         {
             'P',
             'P',
             'P',
             'D',
             'P',
             'H',
         },
         {
             'P',
             'H',
             'P',
             'P',
             'P',
             'D',
         },
         {
             'P',
             'D',
             'P',
             'D',
             'P',
             'P',
         },
         {
             'P',
             'P',
             'P',
             'H',
             'P',
             'D',
         },
         {
             'P',
             'D',
             'P',
             'P',
             'P',
             'T',
         }};

    char sol[6][6] = {'.'};

    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            sol[i][j] = '.';
        }
    }

    int energy = 100;
    if (findPath(maze, sol, n, energy))
    {
        cout << "found";
        cout << endl;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "not found";
    }
    return 0;
}