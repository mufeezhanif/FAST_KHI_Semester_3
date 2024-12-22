#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


class Heap{
  int *arr;
  int size;

  public:

  Heap(){
    arr = new int[100];  //max assumed
    size = 0;

    arr[0] = -1;
  }

  /*  
  1- Based Indexing
    Node - ith index
    Left child - 2ith 
    Right Child - 2i + 1 th
    Parent = i/2


  0- Based Indexing
    Node - ith index
    Left child - 2i + 1th 
    Right Child - 2i + 2 th
    Parent = i - 1 /2

   */

  void insertintoHeap(int val){
    size = size + 1;
    int index = size;
    arr[index] = val;  // step1 : insert
    
    
    while(index > 1){   // step2: place it at its correct position
        int parent = index / 2;

        if(arr[parent] < arr[index]){
            swap(arr[parent] ,arr[index]);
            index = parent;
        }
        else{
            return;
        }
    }
   
  }


  void deleteFromHeap(){
      
      if(size == 0) return;
    
       // Last element : that  will be at sizeth- index
      arr[1] = arr[size];  //step-1
      size--;              //step-2

      int i = 1;  // step-3
      while(i < size){
        int leftIndex = 2*i;
        int rightIndex = 2*i + 1;

        if(leftIndex < size  && arr[i] < arr[leftIndex]){    //check left Child first , if leftchild > parent .. swap
            swap(arr[i] , arr[leftIndex]);
            i = leftIndex;  
        }
        else if(rightIndex < size && arr[i] < arr[rightIndex]){  // check right child
            swap(arr[i] , arr[rightIndex]);
            i = rightIndex;
        }
        else{ // everything is correct , Heap is maintained
            return;
        }
      }

  }



  void printHeap(){
    for(int i = 1; i<=size ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
  }
};



//HEAPIFY ALGO -- MAX HEAP  - 1-Based Indexing

// approach - 2
/*
  similarly just replace root with last value and then call heapify for the oth index , it will just place the root to its correct posotion
*/
void heapify(int *arr , int n , int i){
   
    int largest = i;
    int leftChild = 2*i;
    int rightChild = 2*i + 1;

    //step-1 --> find the maximum of left and right child , if exits , so that parent can be swapped
    if(leftChild <= n  && arr[largest] < arr[leftChild]){  
        largest = leftChild;
    }

    if(rightChild <= n && arr[largest] < arr[rightChild]){
        largest = rightChild;
    }

    if(largest != i){
        swap(arr[i] , arr[largest]);
        heapify(arr , n , largest);   // to place the  swapped one at its correct position
    }
    else{
         // means the node is at its right position
        return;
    } 
}



//HEAP SORT

void HeapSort(int*arr , int n){

    for(int i = n/2 ; i>0 ; i--){
        heapify(arr , n , i);   //creating the Heap --> 
    }
    
    int size = n;
    
    while(size > 1){
        //step1 -- swap
        swap(arr[size] , arr[1]);
        size--;

        //step-2
        heapify(arr , size , 1); // it will place the root to its correct position
    }

}






int main(){
    Heap h;
    h.insertintoHeap(10);
    h.insertintoHeap(11);
    h.insertintoHeap(12);
    h.insertintoHeap(15);
    h.insertintoHeap(90);
    h.insertintoHeap(100);

    h.printHeap();

    // h.deleteFromHeap();
    // h.printHeap();

//     int arr[8] = {-1 ,10,20,15,12,40,25,18};
//     int n = 7;
//    for(int i = n/2 ; i>0 ; i--){
//     heapify(arr ,n , i);
//    }

//    for(int i = 1 ; i<=n ; i++){
//     cout << arr[i] <<  " ";
//    }
//    cout << endl;

//     HeapSort(arr , n);

//    for(int i = 1 ; i<=n ; i++){
//     cout << arr[i] <<  " ";
//    }

   
  //Max Heap  --- By Default
  priority_queue<int>maxHeap;            //--> this STL builtin function will do same work as our heapify()function
    maxHeap.push(45);
    maxHeap.push(50);
    maxHeap.push(55);
    maxHeap.push(70);
    maxHeap.push(60);
    

    while(!maxHeap.empty()){
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }cout << endl;
   

   //MIN HEAP --> remember the Syntax
    priority_queue<int , vector<int> , greater<int> >minHeap;

    minHeap.push(45);
    minHeap.push(50);
    minHeap.push(55);
    minHeap.push(70);
    minHeap.push(60);

    while(!minHeap.empty()){
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
   
}