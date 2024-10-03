#include <bits/stdc++.h>
using namespace std;

void displaysolved(char **array, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
void solve(int col, char **board, char **solved, int N, vector<int> row, vector<int> lowerDiagonal, vector<int> upperDiagonal)
{
    if (col == N)
    {

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                solved[i][j] = board[i][j];
            }
        }
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (
            row[i] == 0 && lowerDiagonal[i + col] == 0 && upperDiagonal[N - 1 + col - i] == 0)
        {
            board[i][col] = 'F'; //placing flag
            row[i] = 1;
            lowerDiagonal[i + col] = 1;
            upperDiagonal[N - 1 + col - i] = 1;
            solve(col + 1, board, solved, N, row, lowerDiagonal, upperDiagonal);
            board[i][col] = '-';
            row[i] = 0;
            lowerDiagonal[i + col] = 0;
            upperDiagonal[N - 1 + col - i] = 0;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    char **board = new char *[N];
    char **solved = new char *[N];

    for (int i = 0; i < N; ++i)
    {
        board[i] = new char[N];
        solved[i] = new char[N];
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            board[i][j] = '-';
            solved[i][j] = '-';
        }
    }

    vector<int> row(N, 0);
    vector<int> lowerDiagonal(N * 2 - 1, 0);
    vector<int> upperDiagonal(N * 2 - 1, 0);
    solve(0, board, solved, N, row, lowerDiagonal, upperDiagonal);
    displaysolved(solved, N);
    for (int i = 0; i < N; ++i)
    {
        delete[] board[i];
        delete[] solved[i];
    }
    delete[] board;
    delete[] solved;
    return 0;
}
