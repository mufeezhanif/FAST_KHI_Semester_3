// C++ Program to implement a queue using array
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Queue
{
public:
    int start;
    int end;
    int size;
    int max;
    T *arr;

    Queue(int max)
    {
        this->max = max;
        start = end = -1;
        size = 0;
        arr = new T[max];
    }

    void push(T data)
    {
        if (size == max - 1)
        {
            cout << "Queue fulled " << endl;
        }
        else if (start == -1 && end == -1)
        {
            start = end = 0;
            arr[end] = data;
            ++size;
        }
        else
        {
            end++;
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
        start++;
        --size;
    }

    T top()
    {
        if (start != -1)
            return arr[start];
        return T();
    }
    int getSize(){ return size;}
};

int main()
{
    Queue<int> cashier(7); // max size of queue
    cashier.push(13);
    cashier.push(7);
    cashier.push(4);
    cashier.push(1);
    cashier.push(6);
    cashier.push(8);
    cashier.push(10);
    // above are enqueue operations, below are dequeue

    cashier.pop();
    cashier.pop();
    cashier.pop();
    cashier.pop();
    cashier.pop();
    cashier.pop();
    cashier.pop();
    return 0;
}
