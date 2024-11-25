#include<bits/stdc++.h>

using namespace std;

class Heap{
    public:
        int currSize;
        int * heap;
        int capacity;
        Heap(int size){
            heap= new int[size];
            currSize=0;
            capacity = size;
        }

        void insert(int val){
            if(currSize == capacity){
                cout<<"Heap full\n";
                return;
            }
            int i = currSize;
            ++currSize;
            heap[i] = val;
            while(i>0){
                int parent = ((i-1)/2);
                if(heap[parent] < heap[i]){
                    swap(heap[parent], heap[i]);
                    i = parent;
                }
                else{
                    break;
                }
            }
        }

        void deleteVal(){
            if(currSize==0){
                cout<<"Heap doesn't have any value";
            }
            
        }
        void printHeap(){
            for(int i=0;i<currSize;++i){
                cout<<heap[i]<<" ";
            }
            cout<<endl;
        }
};


int main(){
    Heap h1(10);
    h1.insert(5);
    h1.insert(1);
    h1.insert(2);
    h1.insert(2);
    h1.printHeap();
    return 0;
}