#ifndef BST_H
#define BST_H

#include "Node.h"

class BST
{
public:
    Node *root;
    int size;

    BST();
    void insert(int id, string name, int age);
    void deleteVal(int id);
    Node *findEntry(int id);
    ~BST();

private:
    void deleteTree(Node *);
    Node *getSuccessor(Node *head);
    Node *deleteValNode(Node *head, int key);
};

#endif