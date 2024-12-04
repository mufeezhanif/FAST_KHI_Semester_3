#include "Node.h"

Node::Node(int id, string name, int age) : id(id), name(name), age(age)
{
    height = 0;
    right = left = nullptr;
}

void Node::copyObj(Node *other)
{
    this->id = other->id;
    this->name = other->name;
    this->age = other->age;
    this->height = other->height;
}

void Node::printData()
{
    cout << "Printing current entry: \n";
    cout << id << " " << name << " " << age << endl;
}