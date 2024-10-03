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
            return T();
        }
    }

    bool isEmpty()
    {
        return top <= -1;
    }
};

string posToPre(string exp)
{
    int len = exp.length();
    string ans = "";
    Stack<string> stack(len); // at max size length
    string temp;

    for (int i = 0; i < len; ++i)
    {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <= '9'))
        {
            temp += exp[i];
            stack.push(temp);
            temp = "";
        }
        else
        {
            string top1 = stack.peek();
            stack.pop();
            string top2 = stack.peek();
            stack.pop();
            temp =   exp[i] + top2 + top1;
            stack.push(temp);
            temp = "";
        }
    }
    ans = stack.peek();
    return ans;
}

int main()
{
    string str = "FD+CBA+*-";
    cout << posToPre(str);

    return 0;
}