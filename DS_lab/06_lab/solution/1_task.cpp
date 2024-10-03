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

int main()
{
    string st = "BORRORROB";
    Stack<char> st1(st.length());
    string ans;
    for(int i=0;i<st.length();++i){
        st1.push(st[i]);
    }
    
    
    
    for(int i=st.length();i>0;--i){
        ans += st1.peek();
        st1.pop();
    }    


    
    if (ans==st)
        cout << "It is a palindrome" << endl;
    else
        cout << "It is not a palindrome" << endl;
}