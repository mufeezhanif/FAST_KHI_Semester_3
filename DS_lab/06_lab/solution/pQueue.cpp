// C++ Program to implement a queue using array
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class CircularQueueArray
{
public:
    int start;
    int end;
    int size;
    int max;
    T *arr;

    CircularQueueArray(int max)
    {
        this->max = max;
        start = end = -1;
        size = 0;
        arr = new T[max];
    }

    void push(T data)
    {
        if (start == -1 && end == -1)
        {
            start = end = 0;
            arr[end] = data;
            ++size;
        }
        else
        {
            end = (end + 1) % max;
            arr[end] = data;
            ++size;
        }
    }

    void pop()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        start = (start + 1) % max;
        --size;
    }

    T top()
    {
        if (start != -1)
            return arr[start];
        return T();
    }
};

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
    int getSize() { return size; }
};

int main()
{
    QueueLL<int> q1;
    q1.push(25);
    q1.pop();
    q1.pop();
    q1.push(2);
    cout << q1.top() << endl;
    q1.push(5);
    q1.push(46);
    cout << q1.top() << endl;
    q1.pop();
    q1.pop();
    q1.push(10);
    cout << q1.top() << endl;
    cout << q1.getSize() << endl;
    return 0;
}
