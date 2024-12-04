#ifndef BTREENODE_h
#define BTREENODE_h

#include <bits/stdc++.h>
#include "EntryData.h"
using namespace std;

class BTreeNode
{
public:
    vector<BTreeNode *> children;
    vector<EntryData> keys;
    bool leaf;
    int min_deg;
    BTreeNode(int t, bool leafNode);
    void ins_non_full(EntryData newKey);
    void split_child(int i, BTreeNode *y);
    void disp_btree(int level);
    bool search(int id);
};

#endif