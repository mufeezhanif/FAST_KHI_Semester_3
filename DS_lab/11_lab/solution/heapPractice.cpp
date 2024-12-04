#include <iostream>

using namespace std;

class MinHeap
{
public:
    int *heaparr;
    int capacity;
    int size;

    MinHeap(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        heaparr = new int[capacity];
    }

    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Heap is full\n";
            return;
        }
        if (size == 0)
        {
            ++size;
            heaparr[size] = val;
            return;
        }

        ++size;
        heaparr[size] = val;
        int i=size;
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (heaparr[parent] > heaparr[i])
            {
                swap(heaparr[parent], heaparr[i]);
                i = parent;
            }
            else
            {
                return;
            }
        }
    };
    void  deleteVal()
    {
        if (size == 0)
        {
            cout << "There in nothing in the heap\n";
            return;
        }
        heaparr[1] = heaparr[size];

        int i = 1;
        while (i < size)
        {
            int leftind = i * 2;
            int rightind = i * 2 + 1;
            if (leftind <= size && heaparr[leftind] < heaparr[i])
            {
                swap(heaparr[leftind], heaparr[i]);
                i = leftind;
            }
            else if (rightind <= size && heaparr[rightind] < heaparr[i])
            {
                swap(heaparr[rightind], heaparr[i]);
                i = rightind;
            }
            else
                return;
        }
    };
    void heapifyTheAray(int arr[], int n, int ind)
    {
        int smallest = ind;
        int rightChild = (smallest * 2) + 1;
        int leftChild = smallest * 2;

        if (rightChild <= n && arr[rightChild] < arr[smallest])
        {
            smallest = rightChild;
        }
        if (leftChild <= n && arr[leftChild] < arr[smallest])
        {
            smallest = leftChild;
        }

        if (smallest != ind)
        {
            swap(arr[smallest], arr[ind]);
            heapifyTheAray(arr, n, smallest);
        }
    }
    void buildHeap(int arr[], int n){
        for(int i=1 ;i<n+1;++i){
            insert(arr[i]);
        }
    }
    void heapSort(int arr[], int n){


        int realSize = n;
        while(n>1){
            swap(arr[n], arr[1]);
            n--;
            heapifyTheAray(arr,n,1);
        }
    }
    int returnSize()
    {
        return size;
    }
    void printHeap()
    {
        for (int i = 1; i <= size; ++i)
        {
            cout << heaparr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int arr[6] = {12, 46, 48, 45, 12, 21};
    MinHeap m1(6);
    for(int i=5/2;i>0;--i){
    m1.heapifyTheAray(arr, 5, i);
    }
    m1.heapSort(arr,5);

    for(int i=1;i<6;++i){
        cout<<arr[i]<<" ";
    }
    m1.buildHeap(arr, 5);
    // m1.printHeap();
}