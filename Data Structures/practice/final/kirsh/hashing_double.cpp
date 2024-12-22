#include <iostream>
using namespace std;

class HashTable
{
private:
    int *table; 
    int size;  
    int count;  

    int hash1(int key)
    {
        return key % size;
    }

    int hash2(int key)
    {
        return 1 + (key % (size - 1));
    }

public:
    HashTable(int tableSize)
    {
        size = tableSize;
        count = 0;
        table = new int[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = -1; 
        }
    }

    void insert(int key)
    {
        if (count == size)
        {
            cout << "Hash table is full! Cannot insert key " << key << endl;
            return;
        }

        int index = hash1(key);
        int stepSize = hash2(key);
        int i = 0;

        while (table[(index + i * stepSize) % size] != -1)
        {
            i++;

            if (i == size)
            { 
                cout << "No available slot for key " << key << endl;
                return;
            }
        }

        table[(index + i * stepSize) % size] = key;
        count++;
    }

    bool search(int key)
    {
        int index = hash1(key);
        int stepSize = hash2(key);
        int i = 0;

        while (table[(index + i * stepSize) % size] != -1)
        {
            if (table[(index + i * stepSize) % size] == key){
                     return true;
            }
               
                 i++;
            if (i == size) break;
        }
        
        return false;
    }

    void display()
    {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < size; i++)
        {
            if (table[i] == -1)
            {
                cout << "Index " << i << ": Empty" << endl;
            }
            else
            {
                cout << "Index " << i << ": " << table[i] << endl;
            }
        }
    }

    ~HashTable()
    {
        delete[] table;
    }
};

int main()
{
    HashTable ht(7);

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(30);

    ht.display();

    cout << "\nSearch for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    cout << "Search for 25: " << (ht.search(25) ? "Found" : "Not Found") << endl;

    return 0;
}