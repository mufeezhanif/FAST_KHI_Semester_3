#include <bits/stdc++.h>

using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data) : data(data)
    {
        next = NULL;
    }
};
template <typename T>
class QueueLL
{
public:
    int size;
    Node<T> *start;
    Node<T> *end;

    QueueLL()
    {
        size = 0;
        start = NULL;
        end = NULL;
    }

    void push(T data)
    {
        if (start == NULL)
        {
            start = new Node<T>(data);
            end = start;
            ++size;
        }
        else
        {
            Node<T> *temp = new Node<T>(data);
            end->next = temp;
            end = end->next;
            ++size;
        }
    }

    void pop()
    {
        if (start)
        {
            Node<T> *temp = start;
            start = start->next;
            --size;
            delete temp;
            return;
        }
        cout << "Queue is empty" << endl;
    }

    T top()
    {
        if (start)
        {
            return start->data;
        }
        cout << "Queue is empty" << endl;
        return T();
    }

    void ProvideService()
    {
        if (!start)
            return;
        cout << "Hello Mr, " << start->data << endl;
        cout << "Enter name of book you want to borrow or return: " << endl;
        string str;
        getline(cin, str);
        cout << "Patron serviced" << endl;
        pop();
    }
    int getSize() { return size; }
};
int main()
{
    QueueLL<string> Library;
    // adding new patron
    Library.push("Ahmed");
    Library.push("Ali");
    Library.push("Hafeez");
    Library.push("Mubeen");
    Library.ProvideService();
    cout<<Library.getSize()<<endl;
    Library.ProvideService();
    cout<<Library.getSize()<<endl;
    return 0;
};