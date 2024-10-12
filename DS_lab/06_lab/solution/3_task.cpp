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
    Node<T> *top;

public:
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
    T current()
    {
        if (!top)
            return T();
        return top->url;
    }
    ~LLStack()
    {
        while (top && top->prev)
        {
            Node<T> *prev = top->prev;
            top = top->prev;
            delete prev;
        }
    }
};

int main()
{
    LLStack<string> web1("Google.cam");
    web1.visit("Facebook.com");
    web1.visit("Twitter.com");
    web1.visit("Linkedin.com");
    web1.visit("Instagram.com");

    web1.back(2);
    cout << web1.current();
    return 0;
}