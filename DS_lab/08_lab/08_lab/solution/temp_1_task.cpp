#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    string name;
    int score;
    Node* next;
    static int size;

    Node() : name(""), score(0), next(nullptr) { incSize(); }
    Node(string name, int score) : name(name), score(score), next(nullptr) { incSize(); }

    static void incSize() {
        ++size;
    }
};

int Node::size = 0;

int findMax(Node* arr, int n) {
    int maxScore = arr[0].score;
    for (int i = 1; i < n; ++i) {
        if (arr[i].score > maxScore) {
            maxScore = arr[i].score;
        }
    }
    return maxScore;
}

void countSort(Node* arr, int n, int exp) {
    Node* result = new Node[n];
    int count[10] = {0};

    for (int i = 0; i < n; ++i) {
        count[(arr[i].score / exp) % 10]++;
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        result[count[(arr[i].score / exp) % 10] - 1] = arr[i];
        count[(arr[i].score / exp) % 10]--;
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = result[i];
    }

    delete[] result;
}

void applyRadixSort(Node* arr, int n) {
    int maxScore = findMax(arr, n);
    for (int exp = 1; maxScore / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

void radixSort(Node*& head) {
    if (!head) return; // Return if the list is empty

    int count = Node::size;
    Node* arr = new Node[count];
    Node* temp = head;

    for (int i = 0; i < count; ++i) {
        arr[i] = *temp;
        temp = temp->next;
    }

    applyRadixSort(arr, count);

    // Rebuild the linked list
    head = new Node(arr[0].name, arr[0].score);
    temp = head;
    for (int i = 1; i < count; ++i) {
        temp->next = new Node(arr[i].name, arr[i].score);
        temp = temp->next;
    }

    delete[] arr;
}

void addNode(Node*& head, string name, int score) {
    Node* newNode = new Node(name, score);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    radixSort(head);
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->name << " " << temp->score << endl;
        temp = temp->next;
    }
}

int main() {
    Node* head = nullptr; // Initialize the head to nullptr

    addNode(head, "ahmed", 100);
    addNode(head, "mufeez", 30);
    addNode(head, "Ali", 0);
    addNode(head, "Hamza", 50);
    addNode(head, "Arhan", 90);
    addNode(head, "Ragib", 10);

    displayList(head);

    // Cleanup: Free allocated memory for the linked list
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
