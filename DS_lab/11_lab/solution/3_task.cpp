#include<iostream>

using namespace std;


class MaxHeap
{
public:
    int *heaparr;
    int capacity;
    int size;

    MaxHeap(int capacity)
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
        int i = size;
        while (i > 1)
        {
            int parent = (i) / 2;
            if (heaparr[parent] < heaparr[i])
            {
                swap(heaparr[parent], heaparr[i]);
                i = parent;
            }
            else
            {
                return;
            }
        }
    }
    void printHeap()
    {
        for (int i = 1; i <= size; ++i)
        {
            cout << heaparr[i] << " ";
        }
        cout << endl;
    }
    void deleteVal()
    {
        if (size == 0)
        {
            cout << "There is nothing in the heap\n";
            return;
        }
        int temp = heaparr[1];
        heaparr[1] = heaparr[size];
        heaparr[size] = temp;
        --size;

        int i = 1;
        while (i <= size)
        {
            int leftind = i * 2;
            int rightind = i * 2 + 1;
            int largest = i;

            if (leftind <= size && heaparr[leftind] > heaparr[largest])
            {
                largest = leftind;
            }

            if (rightind <= size && heaparr[rightind] > heaparr[largest])
            {
                largest = rightind;
            }

            if (largest == i)
            {
                break;
            }

            swap(heaparr[i], heaparr[largest]);
            i = largest;
        }
    }

    void buildHeap(int arr[], int n){
        for(int i=0 ;i<n;++i){
            insert(arr[i]);
        }
    }
    void heapSort(){
        int realSize = size;
        while(size>1){
            deleteVal();
        }
        size = realSize;
        printHeap();
    }
    
  void deleteVal(int val)
    {
        if (size == 0)
        {
            cout << "There is nothing in the heap\n";
            return;
        }
        int i = 1;
        for(i=1;i<size;++i){
            if(heaparr[i] == val) break;
        }
        heaparr[i] = heaparr[size];
        --size;

        while (i <= size)
        {
            int leftind = i * 2;
            int rightind = i * 2 + 1;
            int largest = i;

            if (leftind <= size && heaparr[leftind] > heaparr[largest])
            {
                largest = leftind;
            }

            if (rightind <= size && heaparr[rightind] > heaparr[largest])
            {
                largest = rightind;
            }

            if (largest == i)
            {
                break;
            }

            swap(heaparr[i], heaparr[largest]);
            i = largest;
        }
        printHeap();
    }

};

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
        int i = size;
        while (i > 1)
        {
            int parent = (i) / 2;
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
    }
    void printHeap()
    {
        for (int i = 1; i <= size; ++i)
        {
            cout << heaparr[i] << " ";
        }
        cout << endl;
    }
    void deleteVal()
    {
        if (size == 0)
        {
            cout << "There is nothing in the heap\n";
            return;
        }
        int temp = heaparr[1];
        heaparr[1] = heaparr[size];
        heaparr[size] = temp;
        --size;

        int i = 1;
        while (i <= size)
        {
            int leftind = i * 2;
            int rightind = i * 2 + 1;
            int largest = i;

            if (leftind <= size && heaparr[leftind] < heaparr[largest])
            {
                largest = leftind;
            }

            if (rightind <= size && heaparr[rightind] < heaparr[largest])
            {
                largest = rightind;
            }

            if (largest == i)
            {
                break;
            }

            swap(heaparr[i], heaparr[largest]);
            i = largest;
        }
    }

    void buildHeap(int arr[], int n){
        for(int i=0 ;i<n;++i){
            insert(arr[i]);
        }
    }
    
  void deleteVal(int val)
    {
        if (size == 0)
        {
            cout << "There is nothing in the heap\n";
            return;
        }
        int i = 1;
        for(i=1;i<size;++i){
            if(heaparr[i] == val) break;
        }
        heaparr[i] = heaparr[size];
        --size;

        while (i <= size)
        {
            int leftind = i * 2;
            int rightind = i * 2 + 1;
            int largest = i;

            if (leftind <= size && heaparr[leftind] < heaparr[largest])
            {
                largest = leftind;
            }

            if (rightind <= size && heaparr[rightind] < heaparr[largest])
            {
                largest = rightind;
            }

            if (largest == i)
            {
                break;
            }

            swap(heaparr[i], heaparr[largest]);
            i = largest;
        }
        printHeap();
    }

};


int main(){
    MaxHeap maxh(10);
    MinHeap minh(10);

    int arr[10] = {25,30,35,11,15,19,18,55,78,36};
    cout<<"Max heap\n";
    maxh.buildHeap(arr,10);
    maxh.printHeap();
    maxh.deleteVal(55);
    maxh.printHeap();
    maxh.heapSort();


    cout<<"Min heap\n";
    minh.buildHeap(arr,10);
    minh.printHeap();
    maxh.deleteVal(18);
    maxh.printHeap();

    

    return 0;
}