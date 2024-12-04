#ifndef NODE_H
#define NODE_H

#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int id;
    string name;
    int age;
    Node *left;
    Node *right;
    int height;
    Node(int id, string name, int age);
    void  copyObj(Node* other);
    void printData();
    
};

#endif