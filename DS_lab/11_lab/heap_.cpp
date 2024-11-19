#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* heap;
    int capacity;
    int currentSize;

    void swap(int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
    }

    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < currentSize && heap[left] > heap[largest])
            largest = left;

        if (right < currentSize && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

public:
   
    MaxHeap(int cap) {
        capacity = cap;
        heap = new int[capacity];
        currentSize = 0;
    }

    void insert(int value) {
        if (currentSize == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }

        heap[currentSize] = value;
        int i = currentSize;
        currentSize++;

        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int deleteMax() {
        if (currentSize <= 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        int root = heap[0];
        heap[0] = heap[currentSize - 1];
        currentSize--;

        heapify(0);

        return root;
    }

    int peek() const {
        if (currentSize <= 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return heap[0];
    }

    int extractMax() {
        return deleteMax(); 
    }


    void buildHeap(int arr[], int n) {
        if (n > capacity) {
            cout << "Array size exceeds heap capacity!" << endl;
            return;
        }

        for (int i = 0; i < n; i++) {
            heap[i] = arr[i];
        }
        currentSize = n;

        for (int i = currentSize / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

   
    void printHeap() const {
        for (int i = 0; i < currentSize; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    
    int size() const {
        return currentSize;
    }

  
    bool isEmpty() const {
        return currentSize == 0;
    }
};

int main() {
    int capacity = 20; // define the max capcacity for heap. 
    MaxHeap h(capacity);

    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(5);
    h.insert(15);

    cout << "Heap: ";
    h.printHeap();

    cout << "Peek (Max): " << h.peek() << endl;  

    cout << "Extracted Max: " << h.extractMax() << endl;
    cout << "Heap after extraction: ";
    h.printHeap();

    int arr[] = {8, 2, 5, 3, 7, 10};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    h.buildHeap(arr, arrSize);
    cout << "Heap built from array: ";
    h.printHeap();

    return 0;
}
