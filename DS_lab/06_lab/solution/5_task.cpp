#include <bits/stdc++.h>

using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class LLStack
{
public:
    Node<T> *head;
    int Max;
    int curr;
    LLStack(int Max)
    {
        this->Max = Max;
        curr = 0;
    }
    void push(T data)
    {
        if (Max - curr == 0)
        {
            cout << "stack full" << endl;
            return;
        }
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
        ++curr;
    }
    T peek()
    {
        if (curr == 0)
        {
            cout << "Stack is empty" << endl;
            return T();
        }
        return head->data;
    }
    void pop()
    {
        if (curr == 0)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        head = head->next;
    }
    ~LLStack()
    {
        while (head && head->next)
        {
            Node<T> *prev = head->next;
            head = head->next;
            delete prev;
        }
    }
};

template <class T>
int calc(Stack<T> s, char c, int val)
{
    if (c == '+')
    {
        return s.peek() + val;
    }
    else if (c == '-')
    {
        return s.peek() - val;
    }
    else if (c == '*')
    {
        return s.peek() * val;
    }
    else if (c == '/')
    {
        return s.peek() / val;
    }
    else if (c == '^')
    {
        return pow(s.peek(), val);
    }
}

int main()
{
    string equation = "x=12+13-5(0.5+0.5)+1";
    LLStack<char> *stack = new LLStack<char>(equation.length());
    for (int i = 0; i < equation.length(); i++)
    {
        stack.push(equation[i]);
        if (equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/' || equation[i] == '^')
        {
            stack.push(calc(stack, equation[i], equation[i + 1]));
        }
    }
    cout << stack.peek();
    return 0;
};