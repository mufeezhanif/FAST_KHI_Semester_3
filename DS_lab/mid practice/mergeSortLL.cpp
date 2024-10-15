#include <bits/stdc++.h>

using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node();
        Node(int data):data(data), next(NULL){}
};

class LinkedList{
    public:
        Node *head;
        Node *last;

};

Node *operator[](int index)
{
    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp;
}

void merge(int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    LinkedList left, right;

    for (int i = 0; i < n1; i++)
    {
        if (i == 0)
        {
            left.head = new Node;
            left.head->data = (*this)[i + low]->data;
            left.head->next = nullptr;
            left.last = left.head;
        }
        else
        {
            Node *temp = new Node;
            temp->data = (*this)[i + low]->data;
            temp->next = nullptr;
            left.last->next = temp;
            left.last = temp;
        }
    }

    for (int i = 0; i < n2; i++)
    {
        if (i == 0)
        {
            Node *temp = new Node;
            right.head = new Node;
            temp->data = (*this)[mid + 1 + i]->data;
            temp->next = nullptr;
            right.head = temp;
            right.last = temp;
        }
        else
        {
            Node *temp = new Node;
            temp->data = (*this)[mid + 1 + i]->data;
            temp->next = nullptr;
            right.last->next = temp;
            right.last = temp;
        }
    }

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (left[i]->data <= right[j]->data)
        {
            (*this)[k]->data = left[i]->data;
            i++;
        }
        else
        {
            (*this)[k]->data = right[j]->data;
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        (*this)[k]->data = left[i]->data;
        i++;
        k++;
    }

    while (j < n2)
    {
        (*this)[k]->data = right[j]->data;
        j++;
        k++;
    }
}

void merge_sort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main()
{

    return 0;
}
