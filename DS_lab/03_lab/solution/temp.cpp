#include<iostream>
using namespace std;

class Node {
    private:
    int val;
    Node* next;

    public:
    int getval() {
        return val;
    }

    Node* getptr() {
        return next;
    }

    void setval(int val) {
        this->val=val;
    }

    void setptr(Node* ptr) {
        next=ptr;
    }

    Node(int v, Node* ptr) {
        val=v;
        next=ptr;
    }
};

class ll {
    Node* head;
    Node* tail;

    public:
    ll() {
        head = NULL;
        tail = NULL;
    }

    void convertarrtoll(int arr[], int nums) {
        if (nums==0) return;

        head = new Node(arr[0],NULL);
        Node* mover=head;

        for (int i = 1; i < nums; i++){
            Node* temp = new Node(arr[i],NULL);
            mover->setptr(temp);
            mover=mover->getptr();
        }

        tail=mover;
    }

    void display() {
        Node* mover = head;
        while (mover) {
            cout << mover->getval()<<" ";
            mover=mover->getptr();
        }
        cout << endl;
    }
    
    void func(){
        if (head == NULL || head->getptr() == NULL)
        return;
        
        Node* newhead=head->getptr();
        Node* temp1=newhead;
        Node* temp2=head;
        
        while(temp1!=NULL && temp1->getptr()!=NULL ){
            temp2->setptr(temp1->getptr());
            temp2=temp2->getptr();
            temp1->setptr(temp2->getptr());
            temp1=temp1->getptr();
        }
        
        temp1=newhead;
        Node* prev=NULL;
        while(temp1!=NULL){
            Node* front=temp1->getptr();
            temp1->setptr(prev);
            prev=temp1;
            temp1=front;
        }
        temp2->setptr(prev);
    }
};

int main() {
    cout<<"\t\tUZAIR HAROON-23K3033"<<endl;
    
    ll linkedlist;
    int arr[] = {10,4,9,1,3,5,9,4};
    linkedlist.convertarrtoll(arr, 8);
    linkedlist.display();

    linkedlist.func();
    linkedlist.display();
}