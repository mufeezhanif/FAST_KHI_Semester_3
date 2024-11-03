#include <bits/stdc++.h>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data)
    {
        left = NULL;
        right = NULL;
    }
};

class BT
{
    Node *root;
    BT()
    {
        root = NULL;
    }

    void Insert(Node *n)
    {
        Node *temp = root;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp->left == NULL)
            {
                temp->left = n;
                return;
            }
            else if (temp->right == NULL)
            {
                temp->right = n;
                return;
            }
            else
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
    }

    void deleteNode(Node *tempNode, int Keydata)
    {
        Node *temp = tempNode, *Keynode = NULL;

        If(temp == null)
        {

            return;
        }

        If(temp->data = Keydata)
        {

            keynode = temp;

            return;
        }

        queue<Node *> q;

        q.push(tempNode);

        while (!q.empty())
        {

            temp = q.front();

            q.pop();

            if (temp->data == Keydata)
            {

                Keynode = Temp;

                return;
            }

            if (temp->left != NULL)
            {

                q.push(temp->left);
            }

            if (temp->right != NULL)
            {

                q.push(temp->right);
            }
        }

        If(keynode != null)
        {

            remove(tempNode, keynode)
        }
    }

    void remove(Node *temp, Node *delnode)
    {
        queue<Node *> q;
        q.push(temp);
        while (temp->left != delnode || temp->right != delnode)
        {
            temp = q.pop();
            if (temp->left == delnode)
            {

                temp->left = NULL;

                delete delnode;

                return;
            }

            else if (temp->right == delnode)
            {

                temp->right = NULL;

                delete delnode;

                return;
            }

            else
            {

                q.push(temp->left);

                q.push(temp->right);
            }
        }
    };


};

int main()
{

    return 0;
}