#include <iostream>

using namespace std;
template <typename T>
class Stack
{
    T *arr;
    int top;
    int max;

public:
    Stack(int max)
    {
        this->max = max;
        arr = new T[max];
        top = -1;
    }

    T peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            return arr[top];
        }
        return -1;
    }

    void push(T val)
    {
        if (top == max - 1)
        {
            cout << "Stack is already full" << endl;
        }
        else
        {
            arr[++top] = val;
            // cout << "Value added successfullly" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            --top;
            // cout << "Value deleted successfully" << endl;
        }
    }
    bool isEmpty()
    {
        return top == -1;
    }
    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    Stack<int> stack1(5);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);

    int count = 0;
    Stack<int> stack2(5);
    while (!stack1.isEmpty())
    {
        stack2.push(stack1.peek());

        stack1.pop();
        ++count;
    }
    int mid = count / 2;
    count = 1;
    while (!stack2.isEmpty())
    {
        if (count != mid)
        {
            stack1.push(stack2.peek());
        }
        stack2.pop();
        ++count;
    }

    // displaying stack
    while (!stack1.isEmpty())
    {
        cout << stack1.peek() << " ";
        stack1.pop();
    }
    return 0;
}