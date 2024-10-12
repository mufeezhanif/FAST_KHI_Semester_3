#include <iostream>

using namespace std;
template <typename T>
class Stack
{
public:
    T *arr;
    int top;
    int max;
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
    Stack<int> stack1(4);
    stack1.push(40);
    stack1.push(30);
    stack1.push(20);
    stack1.push(10);

    QueueLL<int> q1;
    q1.push(stack1.peek());
    stack1.pop();
    q1.push(stack1.peek());
    stack1.pop();
    q1.push(stack1.peek());
    stack1.pop();
    q1.push(stack1.peek());
    stack1.pop();

    stack1.push(q1.top());
    q1.pop();
    stack1.push(q1.top());
    q1.pop();
    stack1.push(q1.top());
    q1.pop();
    stack1.push(q1.top());
    q1.pop();

    while(!stack1.isEmpty()){
        cout<<stack1.peek()<<" ";
        stack1.pop();
    }
    return 0;
}