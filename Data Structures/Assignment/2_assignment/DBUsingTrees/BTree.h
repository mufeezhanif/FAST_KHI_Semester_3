#ifndef BTREE_h
#define BTREE_h

#include "BTreeNode.h"

class BTree
{
public:
    BTreeNode *root;
    int min_deg;
    BTree(int t);
    void insert(int id, string name, int age);
    void displayTree();
    bool search_btree(int id);
};


#endif