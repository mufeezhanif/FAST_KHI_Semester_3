#include <bits/stdc++.h>

using namespace std;
template <typename T>
class Stack
{
    T *arr;
    int size;
    int top;

public:
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new T[size];
    }

    void push(T c)
    {
        if (top < size - 1)
        {
            arr[++top] = c;
        }
        else
        {
            cout << "Stack OverFlow" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack is Empty" << endl;
        }
    }

    T peek()
    {
        if (top >= 0 && top < size)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is Empty" << endl;
            return T();
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack<string> stack1(5);

    stack1.push("Water the plants");
    stack1.push("something");
    stack1.push("kick aqib kumar");

    cout<<stack1.peek();
}