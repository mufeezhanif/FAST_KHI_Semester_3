#include <iostream>

using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

public:
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }

    void setNext(Node<T> *next)
    {
        this->next = next;
    }
    Node<T> *getNext()
    {
        return next;
    }
    T getData()
    {
        return data;
    }
    void setData(T data)
    {
        this->data = data;
    }
};
template <typename T>
class SinglyLinkedList
{
public:
    Node<T> *head;
    Node<T> *tail;

public:
    SinglyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void setHead(Node<T> *head)
    {
        this->head = head;
    }
    void setTail(Node<T> *tail)
    {
        this->tail = tail;
    }
    Node<T> *getHead()
    {
        return head;
    }
    Node<T> *getTail()
    {
        return tail;
    }
    void turnArrToLL(int arr[], int size)
    {
        head = new Node<T>(arr[0]);
        Node<T> *temp = head;
        for (int i = 1; i < size; ++i)
        {
            Node<T> *n = new Node<T>(arr[i]);
            temp->setNext(n);
            temp = temp->getNext();
        }
        tail = temp;
    }
    void displayLinkedList()
    {
        Node<T> *temp = head;
        cout << "Displaying linkedList: " << endl;
        while (temp != NULL)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }
    Node<T> *reverse(Node<T> *link)
    {
        if (link == NULL || link->getNext() == NULL)
        {
            return link;
        }
        Node<T> *curr = link;
        Node<T> *prev = NULL;
        Node<T> *next;
        while (!curr)
        {
            next = curr->getNext();
            curr->setNext(prev);
            prev = curr;
            curr = next;
        }
        // below four lines are to debug to check whether the link list has been reversed or not
        curr = head;
        head = prev;
        displayLinkedList();
        head = curr;
        displayLinkedList();
        return prev;
    }
    void checkPalindrome()
    {
        Node<T> *slow = head, *fast = head;
        while (fast != NULL && fast->getNext() != NULL)
        {
            slow = slow->getNext();
            fast = fast->getNext()->getNext();
        }
        cout << slow->getData() << endl;
        Node<T> *rev = reverse(slow->getNext());
        Node<T> *temp = head;
        bool flag = true;
        while (rev != NULL && temp != rev)
        {
            if (rev != temp)
            {
                flag = false;
                break;
            }
            rev = rev->getNext();
            temp = temp->getNext();
        }
        if (flag)
            cout << "Linked list is a palindrome" << endl;
        else
            cout << "Linked list is not a palindrome" << endl;
    }
    ~SinglyLinkedList()
    {
        Node<T> *temp = head;
        Node<T> *n;
        while (temp != NULL)
        {
            n = temp;
            temp = temp->getNext();
            delete n;
        }
        cout << "Deleted" << endl;
    }
};

int main()
{
    int arr[] = {1, 0, 2, 0, 1};
    int size = 5;
    SinglyLinkedList<int> *list = new SinglyLinkedList<int>();
    list->turnArrToLL(arr, size);
    list->displayLinkedList();
    list->checkPalindrome();
    return 0;
}