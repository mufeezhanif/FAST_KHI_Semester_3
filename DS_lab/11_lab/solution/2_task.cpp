#include <bits/stdc++.h>

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

        heaparr[1] = heaparr[size];
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
        printHeap();
    }

 
};

int main()
{
    MaxHeap h1(10);
    h1.insert(50);
    h1.insert(30);
    h1.insert(20);
    h1.insert(15);
    h1.insert(10);
    h1.insert(8);
    h1.printHeap();
    h1.deleteVal();
    return 0;
}