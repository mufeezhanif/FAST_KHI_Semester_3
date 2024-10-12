#include <bits/stdc++.h>

using namespace std;
// I will be using jagged array sttucture to solve this question
class seatManagmentSystem
{
public:
    string **baseptr;
    int rows;
    int *columns;

    seatManagmentSystem(int rows)
    {
        this->rows = rows;
        baseptr = new string *[rows];
        columns = new int[rows];
        for (int i = 0; i < rows; ++i)
        {
            cout << "Enter number of seats in row " << i + 1 << endl;
            cin >> columns[i];
        }
        for (int i = 0; i < rows; ++i)
        {
            baseptr[i] = new string[columns[i]];
        }
    }

    void setSeatNames()
    {
        fflush(stdin);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns[i]; ++j)
            {
                cout << "Enter name for seat " << j + 1 << " in row " << i + 1 << endl;
                getline(cin, baseptr[i][j]);
            }
        }
    }
    void displaySeatChart()
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns[i]; ++j)
            {
                cout << "name for seat " << j + 1 << " in row " << i + 1 << " ";
                cout << baseptr[i][j] << endl;
            }
            cout << endl;
        }
    }
    ~seatManagmentSystem()
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] baseptr;
        }
        delete[] baseptr;
    }
};
int main()
{
    seatManagmentSystem *ptr = new seatManagmentSystem(4);
    ptr->setSeatNames();
    ptr->displaySeatChart();
    return 0;
}