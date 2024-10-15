#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->next = NULL;
        data = 0;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    void insertElement(Node *temp, int val)
    {
        if (temp->next == NULL)
        {
            temp->next = new Node(val);
            return;
        }

        insertElement(temp->next, val);
    }

    void displayLLUsingRecursion(Node *mover)
    {
        if (mover == NULL)
        {
            return;
        }
        cout << mover->data << " ";
        if (mover->next == NULL)
        {
            return;
        }
        displayLLUsingRecursion(mover->next);
    }

    Node *findVal(Node *temp, int n)
    {
        if (!temp)
        {
            cout << "Value Not Found" << endl;
            return temp;
        }
        if (temp->data == n)
        {
            cout << "Value Found" << endl;
            return temp;
        }

        return findVal(temp->next, n);
    }
};

int main()
{
    Node *list = new Node(23);
    list->insertElement(list, 56);
    list->insertElement(list, 20);
    list->insertElement(list, 19);
    list->insertElement(list, 15);
    list->insertElement(list, 23);
    list->insertElement(list, 495);

    Node *search = list->findVal(list, 95);
    return 0;
}