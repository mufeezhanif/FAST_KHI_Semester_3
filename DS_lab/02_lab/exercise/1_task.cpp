#include <bits/stdc++.h>


using namespace std;

class DynamicMatrix
{
public:
    int rows, cols;
    int **bptr;
    DynamicMatrix(int rows, int cols)
    {
        this->rows = rows;
        this->cols = cols;
        bptr = new int *[rows];

        for (int i = 0; i < rows; i++)
        {
            bptr[i] = new int[cols];
        }

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                *(*(bptr + i) + j) = i + j;
            }
        }
        printMatrix();
    }
    void resizeMatrix(int newRows, int newCols)
    {
        int **temp = new int *[newRows];
        for (int i = 0; i < newRows; i++)
        {
            temp[i] = new int[newCols];
        }
        for (int i = 0; i < min(rows, newRows); i++)
        {
            for (int j = 0; j < min(cols, newCols); j++)
            {
                temp[i][j] = bptr[i][j];
            }
        }
        for (int i = 0; i < rows; ++i)
        {
            delete[] bptr[i];
        }
        delete[] bptr;
        bptr = temp;
            for (int i = 0; i < newRows; ++i)
            {
                for (int j = 0; j < newCols; ++j)
                {
                    if (j >= cols)
                    {
                        bptr[i][j] = i + j;
                    }
                    if (i >= rows)
                    {
                        bptr[i][j] = i + j;
                    }
                }
            }
        this->rows = newRows;
        this->cols = newCols;
        printMatrix();
    }
    void printMatrix()
    {
        // printing without increment
        cout << "printing without increment" << endl;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << *(*(bptr + i) + j) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    ~DynamicMatrix()
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] bptr[i];
        }
        delete[] bptr;
    }
};

int main()
{
    DynamicMatrix * jaggerArr = new DynamicMatrix(4,5);
    jaggerArr->resizeMatrix(3,10);
    return 0;
}