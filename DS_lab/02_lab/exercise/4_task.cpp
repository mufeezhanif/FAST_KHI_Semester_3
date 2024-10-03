#include <bits/stdc++.h>

using namespace std;

class GPAdata
{
public:
    double **baseptr;
    int courses[4] = {3, 4, 2, 1};
    string coursesName[4] = {"Software Engineering (SE) ", "Artificial Intelligence (AI)", "Computer Science (CS), Data Science (DS)"};
    GPAdata()
    {
        baseptr = new double *[4];
        for (int i = 0; i < 4; ++i)
        {
            baseptr[i] = new double[courses[i]];
        }
    }
    void setData()
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < courses[i]; ++j)
            {
                cout << "Enter Data for " << coursesName[i] << " dep; course no " << j << endl;
                cin >> baseptr[i][j];
            }
        }
    }
    void showData()
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < courses[i]; ++j)
            {
                cout << baseptr[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~GPAdata()
    {
        for (int i = 0; i < 4; ++i)
        {
            delete[] baseptr[i];
        }
        delete[] baseptr;
    }
};
int main()
{
    GPAdata *GPA1 = new GPAdata();
    GPA1->setData();
    GPA1->showData();
    return 0;
}