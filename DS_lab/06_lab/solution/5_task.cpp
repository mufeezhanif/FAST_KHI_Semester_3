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
    // int Max;
    int curr;
    LLStack()
    {
        // this->Max = Max;
        head = NULL;
        curr = 0;
    }
    void push(T data)
    {
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
        --curr;
    }
    bool isEmpty() { return curr == 0; }
    ~LLStack()
    {
        while (head)
        {
            Node<T> *prev = head->next;
            head = head->next;
            delete prev;
        }
    }
};

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

int returnPrecedence(string c)
{
    if (c == "^")
    {
        return 3;
    }
    else if (c == "*" || c == "/")
    {
        return 2;
    }
    else if (c == "+" || c == "-")
    {
        return 1;
    }
    return -1;
}
vector<string> infixToPostfix(vector<string> &exp)
{
    int len = exp.size();
    vector<string> ans;
    LLStack<string> stack;
    ans.push_back(exp[0]);
    ans.push_back(exp[1]);
    for (int i = 2; i < len; ++i)
    {
        if ((exp[i] >= "0" && exp[i] <= "999"))
        {
            ans.push_back(exp[i]);
        }
        else if (exp[i] == "(")
        {
            stack.push(exp[i]);
        }
        else if (exp[i] == ")")
        {
            while (!stack.isEmpty() && stack.peek() != "(")
            {
                ans.push_back(stack.peek());

                stack.pop();
            }
            if (!stack.isEmpty())
                stack.pop();
        }
        else
        {
            while (!stack.isEmpty() && (returnPrecedence(stack.peek()) >= returnPrecedence(exp[i])))
            {
                ans.push_back(stack.peek());

                stack.pop();
            }
            stack.push(exp[i]);
        }
    }
    while (!stack.isEmpty())
    {
        ans.push_back(stack.peek());

        stack.pop();
    }
    return ans;
}
double evaluatePostfix(vector<string> &postfix)
{
    LLStack<double> stack;
    stack.push(stod(postfix[2]));
    stack.push(stod(postfix[3]));

    for (int i = 4; i < postfix.size(); ++i)
    {
        if (postfix[i] != "+" && postfix[i] != "-" && postfix[i] != "*" && postfix[i] != "/" && postfix[i] != "^")
        {
            stack.push(stod(postfix[i]));
        }
        else
        {
            double operand2 = stack.peek();
            stack.pop();
            double operand1 = stack.peek();
            stack.pop();
            double result = 0;

            if (postfix[i] == "+")
            {
                result = operand1 + operand2;
            }
            else if (postfix[i] == "-")
            {
                result = operand1 - operand2;
            }
            else if (postfix[i] == "*")
            {
                result = operand1 * operand2;
            }
            else if (postfix[i] == "/")
            {
                result = operand1 / operand2;
            }

            stack.push(result);
        }
    }
    return stack.peek();
}
int main()
{
    vector<string> equation = {"x", "=", "12", "+", "13", "-", "5", "*", "(", "0.5", "+", "0.5", ")", "+", "1"};

    vector<string> postfix = infixToPostfix(equation);
    for (int i = 0; i < equation.size(); ++i)
    {
        cout << postfix[i] << " ";
    }
        cout <<endl;

    cout<< postfix[0]<<" "<<postfix[1]<<" "<<evaluatePostfix(postfix);
    return 0;
};