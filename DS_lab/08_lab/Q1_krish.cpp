#include<iostream>
#include<cstring>
using namespace std;

class Student {
public:
    string name;
    int score;

    Student() {}

    Student(string n, int s) {
        this->name = n;
        this->score = s;
    }
};

class Node {
public:
    Student std;
    Node *next;

    Node(Student &s) {
        std = s;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(Student s) {
        Node* newnode = new Node(s);
        if (head == nullptr) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    
    void deleteNode(string st, int sc) {
        Node* temp = head;
        Node* prev = nullptr;

        if (head != nullptr && head->std.name == st && head->std.score == sc) { // delete head
            Node* t = head;
            head = head->next;
            t->next = nullptr;
            delete t;
            return;
        }
        
        while (temp != nullptr) {
            if (temp->std.name == st && temp->std.score == sc) {
                prev->next = temp->next;
                temp->next = nullptr;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        
        cout << "NODE NOT FOUND" << endl;
    }
    
    int getlength() {
        Node* temp = head;
        int cnt = 0;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    
    Student getMax() {
        Node* temp = head;
        Student maxi = head->std;

        while (temp != nullptr) {
            if (temp->std.score > maxi.score) {
                maxi = temp->std;
            }
            temp = temp->next;
        }

        return maxi;
    }
    
    void countingSort(int place) {
        int n = getlength();
        Student *output = new Student[n];  
        int count[10] = {0};

        Node* temp = head;
        while (temp != nullptr) {
            count[(temp->std.score / place) % 10]++;
            temp = temp->next;
        }

        
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

       
        temp = head;
        for (int i = n - 1; i >= 0; i--) {
            output[count[(temp->std.score / place) % 10] - 1] = temp->std;
            count[(temp->std.score / place) % 10]--;
            temp = temp->next;
        }

        temp = head;
        for (int i = 0; i < n; i++) {
            temp->std = output[i];
            temp = temp->next;
        }
    }

    void radixSort() {
        Student maxi = getMax();
        
        for (int place = 1; maxi.score / place > 0; place *= 10) {
            countingSort(place);
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Student Name: " << temp->std.name << "\tScore: " << temp->std.score << endl;
            temp = temp->next;
        }
    }
    
    //Binary Search
    Node*middle(Node*start , Node*last){
    	if(start == nullptr) return nullptr;
    	
    	if(start == last) return start;
    	
    	Node*slow = start;
    	Node*fast = start->next;
    	
    	while(fast != last){
    		fast = fast->next;
    		slow = slow->next;
    		
    		if(fast != last){
    			fast = fast->next;
			}
		}
		
		return slow;
	}
    
   Node* BinarySearch(string str, int sc) {
   
    Node* start = head;
    Node* end = nullptr;

    while (start != end) {
        Node* mid = middle(start, end);
        
        if (mid == nullptr) {
            return nullptr;
        }
        if (mid->std.name == str && mid->std.score == sc) {
            return mid;
        }
        
        if (mid->std.score < sc) {
            start = mid->next; 
        } else {
            end = mid;  
        }
    }

    return nullptr;  // If node is not found
}

};

int main() {
    Student s1("Ayan", 90);
    Student s2("Zammer", 60);
    Student s3("Sara", 70);
    Student s4("Sohail", 30);
    Student s5("Ahmed", 20);

    LinkedList l1;
    l1.insert(s1);
    l1.insert(s2);
    l1.insert(s3);
    l1.insert(s4);
    l1.insert(s5);

    cout << "Before sorting:" << endl;
    l1.display();
    
    l1.radixSort();

    cout << "\nAfter sorting:" << endl;
    l1.display();
    
    cout << "\n\n";
    
    Node*nd = l1.BinarySearch("Kirsh" , 30);
    
    if(nd != nullptr){
    	l1.deleteNode(nd->std.name , nd->std.score);
	}
	else{
		cout << "NODE NOT FOUND" << endl;
	}
l1.display();

    return 0;
}
