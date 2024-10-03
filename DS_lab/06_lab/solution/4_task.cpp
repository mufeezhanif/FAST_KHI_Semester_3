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
            return -1;
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int returnPrecedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    return -1;
}
int main()
{
    string str = "a+b*(c^d-e)^(f+g*h)-i";
    Stack<char> st1(str.length());
    string postfix = "";

    for (int i = 0; i < str.length(); ++i)
    {
        char c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            st1.push(c);
        }
        else if (c == ')')
        {
            while (!st1.isEmpty() ){
                postfix += st1.peek();
                st1.pop();
            }
        }
        else if (returnPrecedence(st1.peek()) > returnPrecedence(str[i]))
        {
        }
    }

    return 0;
}