#include "matrix_multiply.h"

using namespace N;

void N::multiplyArray(int arr1[][3], int arr2[][3])
{
    // considering both arrays of same size
    int res[3][3];

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            res[i][j] = 0;
        }
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    std::cout << "displaying the resultant: " << std::endl;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
}