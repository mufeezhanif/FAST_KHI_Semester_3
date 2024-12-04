#include "BTree.h"

BTree::BTree(int t)
{
    root = nullptr;
    min_deg = t;
}
void BTree::insert(int id, string name, int age)
{
    EntryData newKey(id, name, age);
    if (root == nullptr)
    {
        root = new BTreeNode(min_deg, true);
        root->keys.push_back(newKey);
    }
    else
    {
        if (root->keys.size() == 2 * min_deg - 1)
        {
            BTreeNode *s = new BTreeNode(min_deg, false);
            s->children.push_back(root);
            s->split_child(0, root);
            root = s;
        }
        root->ins_non_full(newKey);
    }
}
void BTree::displayTree()
{
    if (root != nullptr)
    {
        root->disp_btree(0);
    }
}
bool BTree::search_btree(int id)
{
    if (root == nullptr)
    {
        return false;
    }
    return root->search(id);
}