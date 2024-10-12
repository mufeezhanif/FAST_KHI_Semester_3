/*
The data structure used for the described problem is queue data structure
push will add the item and pop will remove it

Each element in the queue is an item, to remove multiple items, call the pop function that number of time


function display data will print all orders
*/

#include <bits/stdc++.h>
using namespace std;
template <typename T>
class CircularQueueArray
{
public:
    int start;
    int end;
    int size;
    int max;
    T *arr;

    CircularQueueArray(int max)
    {
        this->max = max;
        start = end = -1;
        size = 0;
        arr = new T[max];
    }

    void push(T data)
    {
        if (start == -1 && end == -1)
        {
            start = end = 0;
            arr[end] = data;
            ++size;
        }
        else
        {
            end = (end + 1) % max;
            arr[end] = data;
            ++size;
        }
    }

    void pop()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        start = (start + 1) % max;
        --size;
    }

    T top()
    {
        if (start != -1)
            return arr[start];
        return T();
    }

    void displayData(){
        if(size ==0) cout<<"No items ordered"<<endl;
        int count= (start<= end) ? end - start: start-end;
        for(int i=0;i<count ;++i){
            cout<<"Item "<<i<<" :"<<arr[i]<<endl;
        }
    }
};

int main()
{
    return 0;
}
