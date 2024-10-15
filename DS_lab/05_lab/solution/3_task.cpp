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

    int findLength(Node *temp, int count = 0)
    {
        if (temp == NULL)
        {
            return count;
        }
        return findLength(temp->next, count + 1);
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

    cout << list->findLength(list);
    return 0;
}