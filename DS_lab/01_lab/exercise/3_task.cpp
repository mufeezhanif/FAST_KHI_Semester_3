#include <iostream>

using namespace std;

class Document{
    public:
    string *content;

    Document(const string s){
        content =  new string(s);
    }
    Document(Document &other){
        this->content = new string(*other.content);
    }

    Document& operator=(Document &other){
        this->content = new string(*other.content);
        return *this;
    }

    ~Document(){
        delete content;
        content = nullptr;
    }
};
int main()
{
    Document doc1("This is doc 1");
    Document doc2 = doc1;

    *doc2.content = "This is changed text";
    cout<<*doc1.content<<endl;
    cout<<*doc2.content<<endl;
    
    return 0;
}