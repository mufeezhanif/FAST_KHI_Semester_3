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
        // updating new cells values
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
        cout << endl
             << endl;
        // incremented at odd indices
        cout << "incremented at odd indices" << endl;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (j % 2 == 1)
                    cout << (*(*(bptr + i) + j) + 2) << " ";
                else
                    cout << *(*(bptr + i) + j) << " ";
            }
            cout << endl;
        }
    }
    void TransposeMatrix()
    {
        // for a transpose matrix, rows and cols should be equal
        int minRows = min(rows, cols);
        int **temp = new int *[minRows];
        for (int i = 0; i < rows; i++)
        {
            temp[i] = new int(minRows);
        }
        cout << "Transposed matrix: " << endl;
        for (int i = 0; i < minRows; i++)
        {
            for (int j = 0; j < minRows; ++j)
            {
                temp[i][j] = bptr[j][i];
                cout << temp[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < minRows; ++i)
        {
            delete[] temp[i];
        }
        delete[] temp;
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
    DynamicMatrix *obj1 = new DynamicMatrix(3, 4);
    cout << "calling resize matrix function(small size)" << endl;
    obj1->resizeMatrix(2, 2);
    cout << "calling resize matrix function(greater size)" << endl;
    obj1->resizeMatrix(3, 5);
    cout << "Transposing the matrix" << endl;
    obj1->TransposeMatrix();
    return 0;
}