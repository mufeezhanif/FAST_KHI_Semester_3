#include <bits/stdc++.h>

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
            arr[++top]= val;
            cout << "Value added successfullly" << endl;
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
            cout << "Value deleted successfully"<<endl;
        }
    }
    bool isEmpty(){
        return top ==-1;
    }
    ~Stack(){
        delete[] arr;
    }
};

int main()
{
    Stack<int> s(4);
    s.push(23);
    s.push(23);
    s.push(23);
    s.push(23);
    s.push(43);

    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;

cout<<"char"<<endl;
    Stack<char> charwala(4);
    charwala.push('c');
    charwala.push('c');
    charwala.push('c');
    charwala.push('c');
    charwala.push('4');

    cout<<charwala.peek()<<endl;
    charwala.pop();
    cout<<charwala.peek()<<endl;
    charwala.pop();
    cout<<charwala.peek()<<endl;
    charwala.pop();
    cout<<charwala.peek()<<endl;
    charwala.pop();
    cout<<charwala.peek()<<endl;

    return 0;
}