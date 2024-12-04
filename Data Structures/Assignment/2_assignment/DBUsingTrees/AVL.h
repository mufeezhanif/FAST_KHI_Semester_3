#ifndef AVL_H
#define AVL_H

#include "Node.h"

class AVL
{
public:
    Node *root;
    int size;

    AVL();
    void insertData(int id, string name, int age);
    int getBalance(Node *node);
    int getHeight(Node *node);
    Node *leftRotate(Node *x);
    Node *rightRotate(Node *y);
    Node *minValNode(Node *node);
    void DeleteEntry(int id);
    Node *search(int id);
    void printTable();
    void preOrder(Node *node);
    ~AVL();

private:
    void deleteTree(Node *);
    Node *insert(Node *head, Node *newNode);
    Node *deleteNode(Node *node, int id);
};

#endif