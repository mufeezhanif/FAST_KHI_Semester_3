#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node
{
public:
    T url;
    Node *next;
    Node *prev;
    Node(T url)
    {
        this->url = url;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <typename T>
class LLStack
{
public:
    Node<T> *top;
    LLStack(T url)
    {
        top = new Node<T>(url);
    }

    void visit(T homepage)
    {
        Node<T> *newNode = new Node<T>(homepage);
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
    }

    T back(int steps)
    {
        while (steps)
        {
            if (top->prev)
                top = top->prev;
            else
                break;
            steps--;
        }
        return top->url;
    }
    T forward()
    {
        if (top->next)
            top = top->next;
        return top->url;
    }

    ~LLStack()
    {
        while (head && head->prev)
        {
            Node<T> *prev = head->prev;
            head = head->prev;
            delete prev;
        }
    }
};

int main()
{

    return 0;
}