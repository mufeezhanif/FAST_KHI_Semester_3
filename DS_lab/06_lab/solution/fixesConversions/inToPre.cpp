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

void reverse(string &str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; ++i)
    {
        swap(str[i], str[n - i - 1]);
    }
}
string infixToPrefix(string exp)
{
    int len = exp.length();
    reverse(exp);
    for (int i = 0; i < len; ++i)
    {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
    string ans = "";
    Stack<char> stack(len);

    for (int i = 0; i < len; ++i)
    {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <= '9'))
        {
            ans += exp[i];
        }
        else if (exp[i] == '(')
        {
            stack.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!stack.isEmpty() && stack.peek() != '(')
            {
                ans += stack.peek();
                stack.pop();
            }
            if (!stack.isEmpty())
                stack.pop();
        }
        else
        {
             while ((returnPrecedence(stack.peek()) >= returnPrecedence(exp[i])) && !stack.isEmpty())
            {
                ans += stack.peek();
                stack.pop();
            }
            stack.push(exp[i]);
            // if (exp[i] == '^')
            // {
            //     while ((returnPrecedence(stack.peek()) >= returnPrecedence(exp[i])) && !stack.isEmpty())
            //     {
            //         ans += stack.peek();
            //         stack.pop();
            //     }
            // }
            // else
            // {
            //     while (!stack.isEmpty() && returnPrecedence(exp[i]) < returnPrecedence(stack.peek()))
            //     {
            //         ans += stack.peek();
            //         stack.pop(); 
            //     }
            // }
            // stack.push(exp[i]);
        }
    }
    while (!stack.isEmpty())
    {
        ans += stack.peek();
        stack.pop();
    }
    reverse(ans);
    return ans;
}

int main()
{
    string str = "F+D-C*(B+A)";
    cout << infixToPrefix(str);

    return 0;
}