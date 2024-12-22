#include<iostream>
#include<utility>
using namespace std;


// CHAINING (Open Hashing)
class HashNode{
 public:
   int value;
   HashNode*next;

   HashNode(int val){
    this->value = val;
    this->next  = nullptr;
   }


};

class HashMap{
 public:
  HashNode**hashtable; 
  const int tablesize = 10;

  public:
  HashMap(){
    hashtable = new HashNode*[tablesize];
     for(int i = 0 ; i<tablesize ; i++){
        hashtable[i] = nullptr;
     }
  }

  void insert(int val){
     int hash = val % tablesize;
     HashNode*newnode = new HashNode(val);

     if(hashtable[hash] == nullptr){
        hashtable[hash] = newnode;
     }
     else{
         HashNode*temp = hashtable[hash];
         while(temp->next != nullptr){
            temp = temp->next;
         }

         temp->next = newnode;
     }
  }


  void remove(int value) {
       int hash = value % tablesize; 
         HashNode* entry = hashtable[hash];
        HashNode* prev = nullptr;

        while (entry != nullptr) {
            if (entry->value == value) { 
                if (prev == nullptr) { // Node is the first in the bucket
                    hashtable[hash] = entry->next;
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
        for (int i = 0; i < tablesize; i++) {
            cout << "Bucket " << i << ": ";
            HashNode* entry = hashtable[i];
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
    map.remove(70);
    cout << "Deleting value 100 (non-existent)...\n";
    map.remove(100);

    cout << "\nUpdated Hash Table Contents:\n";
    map.display();

    return 0;
}



