#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node *addnode(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    node *newnode = new node(data);

    return newnode;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << " " << root->data;
    inorder(root->right);
}

int ans;
void dequal(node *root, int d, int &maxd)
{
    if (!root)
        return;
    if (ans == 0)
        return;
    if (!root->right && !root->left)
    {
        if (maxd == -1)
        {
            maxd = d;
        }
        else
        {
            if (d != maxd)
            {
                ans = 0;
            }
        }
        return;
    }
    dequal(root->left, d + 1, maxd);
    dequal(root->right, d + 1, maxd);
}

bool isLeafSAMElevel(node *root)
{
    int mxd = -1;
    ans = 1;
    int d = 0;
    dequal(root, mxd, d);

    return ans;
}

main()
{
    auto root = addnode(NULL, 12);
    root->left = addnode(root, 13);
    root->right = addnode(root, 14);
  
    cout << "tree\n";
    inorder(root);

    cout << " \ngiven tree has all leaf node at same level : " << isLeafSAMElevel(root);
}