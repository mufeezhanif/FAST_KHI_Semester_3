#include <bits/stdc++.h>

using namespace std;
bool isSafe(vector<vector<string>> &solution, vector<int> &rows,
            vector<int> &cols, int row, int col, int n)
{
    if (row < n && col < n && rows[row] == 0 && cols[col] == 0 &&
        solution[row][col] == ".")
    {
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (solution[i][j] == "Q")
                return false;
        }
        for (int i = row, j = col; i < n && j >= 0; i++, j--)
        {
            if (solution[i][j] == "Q")
                return false;
        }
        return true;
    }
    return false;
}
bool solveQueens(int n, vector<vector<string>> &solution, vector<int> &rows,
                 vector<int> &cols, int col = 0)
{
    if (col == n - 1)
    {
        return true;
    }
    for (int i = 0; i < n; ++i)
    {
        if (isSafe(solution, rows, cols, i, col, n))
        {
            solution[i][col] = "Q";
            rows[i] = 1;
            cols[col] = 1;
            if (solveQueens(n, solution, rows, cols, col + 1))
            {
                return true;
            }
            rows[i] = 0;
            cols[col] = 0;
            solution[i][col] = ".";
        }
    }
    return false;
}
vector<vector<string>> solveNQueens(int n)
{
    string str = "";
    for (int i = 0; i < n; ++i)
    {
        str += ".";
    }
    vector<vector<string>> solution(n, (vector<string>(1, str)));
    vector<int> rows(n, 0);
    vector<int> cols(n, 0);
    solveQueens(n, solution, rows, cols);
    return solution;
}
}
;