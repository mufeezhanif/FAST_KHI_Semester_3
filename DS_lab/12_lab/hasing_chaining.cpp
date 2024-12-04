#include <iostream>
using namespace std;

class HashNode {
public:
    int value;        
    HashNode* next;

    HashNode(int value) {
        this->value = value;
        this->next = nullptr;
    }
};


class HashMap {
private:
    HashNode** htable;          
    static const int TABLE_SIZE = 7;

public:
    
    HashMap() {
        htable = new HashNode*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
            htable[i] = nullptr;
    }

    void insert(int value) {
        int hash = value % TABLE_SIZE; // Compute hash index
        HashNode* newNode = new HashNode(value);

        if (htable[hash] == nullptr) {
            htable[hash] = newNode;
        } else {
            HashNode* temp = htable[hash];
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    
    void remove(int value) {
        int hash = value % TABLE_SIZE; 
        HashNode* entry = htable[hash];
        HashNode* prev = nullptr;

        while (entry != nullptr) {
            if (entry->value == value) { 
                if (prev == nullptr) { // Node is the first in the bucket
                    htable[hash] = entry->next;
                } else {
                    prev->next = entry->next;
                }
                cout << "Value " << value << " deleted successfully!" << endl;
                delete entry;
                return;
            }
            prev = entry;
            entry = entry->next;
        }

        cout << "Value " << value << " not found!" << endl;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Bucket " << i << ": ";
            HashNode* entry = htable[i];
            while (entry != nullptr) {
                cout << entry->value << " -> ";
                entry = entry->next;
            }
            cout << "nullptr" << endl;
        }
    }
};

int main() {
    HashMap map;

    map.insert(70);
    map.insert(50);
    map.insert(85);
    map.insert(92);
    map.insert(73);
    map.insert(101);
    map.insert(76);

    cout << "Hash Table Contents:\n";
    map.display();

    cout << "\nDeleting value 85...\n";
    map.remove(85);
    cout << "Deleting value 73...\n";
    map.remove(73);
    cout << "Deleting value 100 (non-existent)...\n";
    map.remove(100);

    cout << "\nUpdated Hash Table Contents:\n";
    map.display();

    return 0;
}
