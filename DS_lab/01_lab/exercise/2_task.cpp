#include <iostream>

using namespace std;

class Exam
{
public:
    string name;
    string date;
    int score;

public:
    void setName(string name)
    {
        this->name = name;
    }
    void setDate(string date)
    {
        this->date = date;
    }
    void setScore(int score)
    {
        this->score = score;
    }

    void displayDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Exam Date: " << date << endl;
        cout << "Score: " << score << endl
             << endl;
    }
};
int main()
{
    Exam *ptr1 = new Exam();
    ptr1->setDate("22082024");
    ptr1->setName("Mufeez");
    ptr1->setScore(20);
    ptr1->displayDetails();

    Exam *ptr2 = ptr1;
    ptr2->displayDetails();

    ptr2->setName("Hamza");
    // THis changes value of name in both of the objects
    ptr2->displayDetails();
    ptr1->displayDetails();

    return 0;
}

//This program does shallow copy, to resolve this issue we have to do deep copy in objects