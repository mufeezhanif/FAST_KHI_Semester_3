#include <iostream>
using namespace std;

class HashMap {
private:
    static const int TABLE_SIZE = 10; 
    int* Hashtable;                    

public:
	
    HashMap() {
        Hashtable = new int[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            Hashtable[i] = -1;  // Use -1 to indicate an empty slot
        }
    }

    int hash(int value) {
        return value % TABLE_SIZE;
    }

    // in Quadratic Hashing -> probeIndex = (hashIndex + i*i) % TABLE_SIZE;

    void insert(int value) {
        int hashIndex = hash(value); 
        
        for (int i = 0; i < TABLE_SIZE; i++) {
            int probeIndex = (hashIndex + i) % TABLE_SIZE;
            if (Hashtable[probeIndex] == -1 || Hashtable[probeIndex] == -2) { // Empty or deleted slot here -2 shows the deleetd slot.
                Hashtable[probeIndex] = value;
                cout << "Value " << value << " inserted at index " << probeIndex << endl;
                return;
            }
        }

        cout << "Error: Hash table is full. Cannot insert " << value << endl;
    }

    void remove(int value) {
        int hashIndex = hash(value); 

        for (int i = 0; i < TABLE_SIZE; i++) {
            int probeIndex = (hashIndex + i) % TABLE_SIZE;

            if (Hashtable[probeIndex] == value) { // Value found
                Hashtable[probeIndex] = -2;  // Mark the slot as deleted
                cout << "Value " << value << " deleted from index " << probeIndex << endl;
                return;
            }

            if (Hashtable[probeIndex] == -1) {
                break;
            }
        }

        cout << "Value " << value << " not found in the hash table!" << endl;
    }

    void display() {
        cout << "Hash Table Contents:" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            if (Hashtable[i] == -1) {
                cout << "Empty" << endl;
            } else if (Hashtable[i] == -2) {
                cout << "Deleted" << endl;
            } else {
                cout << Hashtable[i] << endl;
            }
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

    cout << "\nInitial Hash Table:" << endl;
    map.display();

    cout << "\nDeleting value 85..." << endl;
    map.remove(85);
    cout << "Deleting value 73..." << endl;
    map.remove(73);
    cout << "Deleting value 100 (non-existent)..." << endl;
    map.remove(100);

    cout << "\nUpdated Hash Table:" << endl;
    map.display();

    return 0;
}