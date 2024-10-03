#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int data;
    Node *head;
    Node *next;
    Node()
    {
        this->next = NULL;
        this->head = NULL;
    }
    Node(int data, Node *next = NULL)
    {
        this->data = data;
        this->next = next;
        this->head = NULL;
    }

    void insertElement(Node *temp, int val)
    {
        if (temp == NULL)
        {
            temp = new Node(val);
            head = temp;
            return;
        }
        if (temp->next == NULL)
        {
            temp->next = new Node(val);
            return;
        }
        insertElement(temp->next, val);
    }
    void displayReverse(Node *temp)
    {
        if (temp->next == NULL)
        {
            cout << temp->data << " ";

            return;
        }
        else if (temp == NULL)
            return;
        displayReverse(temp->next);

        cout << temp->data << " ";
    }
};
int main()
{
    Node *list = new Node(20);
    list->insertElement(list, 56);
    list->insertElement(list, 20);
    list->insertElement(list, 19);
    list->insertElement(list, 15);
    list->insertElement(list, 23);

    list->displayReverse(list);
    return 0;
}