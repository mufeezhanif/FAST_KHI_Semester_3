#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    string name;
    int score;
    Node *next;
    static int size;
    Node();
    Node(string name, int score) : name(name), score(score), next(NULL) { incString(); }
    static void incString()
    {
        ++size;
    }
};

int findMax(Node *arr, int n) 
{
    int max = arr[0].score;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i].score > max)
        {
            max = arr[i].score;
        }
    }
    return max;
}

void countSort(Node *arr, int n, int exp)
{
    Node result[n];
    int i = 0;
    int count[10];

    for (int i = 0; i < 10; ++i)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        count[(arr[i].score / exp) % 10]++;
    }

    for (int i = 1; i < 10; ++i)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i)
    {
        result[count[(arr[i].score / exp) % 10] - 1] = arr[i];
        count[(arr[i].score / exp) % 10]--;
    }

    for (int i = 0; i < n; ++i)
    {
        arr[i] = result[i];
    }
}

void applyRadixSort(Node *arr, int n)
{
    int max = findMax(arr, n);
    cout << "Max: " << max << endl;
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

void radixSort(Node *head)
{
    int count = head->size;
    Node *arr = new Node[count];
    Node *temp = head;
    for (int i = 0; i < count; ++i)
    {
        arr[i] = *temp;
        temp = temp->next;
    }
    applyRadixSort(arr, count);
    *head = arr[0];
    temp = head;
    for (int i = 1; i < count - 1; ++i)
    {
        *(temp->next) = *(arr + i);
        temp = temp->next;
    }
}

void addNode(Node *head, string name, int score)
{
    Node *newNode = new Node(name, score);
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    cout << "added" << endl;
    radixSort(head);
}

void displayList(Node *head)
{
    Node *temp = head;
    cout << endl;
    while (temp)
    {
        cout << temp->name << " " << temp->score << endl;
        temp = temp->next;
    }
}

int main()
{
    Node head("ahmed", 100);

    addNode(&head, "mufeez", 30);
    addNode(&head, "Ali", 0);
    addNode(&head, "Hamza", 50);
    addNode(&head, "Arhan", 90);
    addNode(&head, "Ragib", 10);
    displayList(&head);
    cout << endl;
    return 0;
}