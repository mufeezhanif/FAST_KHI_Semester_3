#include "BTreeNode.h"

BTreeNode::BTreeNode(int t, bool leafNode)
{
    min_deg = t;
    leaf = leafNode;
}
void BTreeNode::ins_non_full(EntryData newKey)
{
    int i = keys.size() - 1;
    if (leaf)
    {
        while (i >= 0 && keys[i].ID > newKey.ID)
        {
            i--;
        }
        keys.insert(keys.begin() + i + 1, newKey);
    }
    else
    {
        while (i >= 0 && keys[i].ID > newKey.ID)
        {
            i--;
        }
        i++;
        if (children[i]->keys.size() == 2 * min_deg - 1)
        {
            split_child(i, children[i]);
            if (keys[i].ID < newKey.ID)
            {
                i++;
            }
        }
        children[i]->ins_non_full(newKey);
    }
}
void BTreeNode::split_child(int i, BTreeNode *y)
{
    BTreeNode *z = new BTreeNode(y->min_deg, y->leaf);
    for (int j = 0; j < min_deg - 1; j++)
    {
        z->keys.push_back(y->keys[j + min_deg]);
    }
    if (!y->leaf)
    {
        for (int j = 0; j < min_deg; j++)
        {
            z->children.push_back(y->children[j + min_deg]);
        }
    }
    keys.insert(keys.begin() + i, y->keys[min_deg - 1]);
    children.insert(children.begin() + i + 1, z);
    y->keys.resize(min_deg - 1);
    y->children.resize(min_deg);
}
void BTreeNode::disp_btree(int level)
{
    for (int i = 0; i < keys.size(); i++)
    {
        if (!leaf)
        {
            children[i]->disp_btree(level + 1);
        }
        cout << "Level " << level << " : Key ID = " << keys[i].ID << ", Name = " << keys[i].name << ", Age = " << keys[i].age << endl;
    }
}
bool BTreeNode::search(int id)
{
    int i = 0;
    while (i < keys.size() && id > keys[i].ID)
        i++;
    if (i < keys.size() && keys[i].ID == id)
    {
        return true;
    }
    if (leaf)
        return false;
    return children[i]->search(id);
}
