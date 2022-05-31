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

int maxval;

int height(node *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    maxval = max(maxval, lh + rh );

    return 1 + max(rh, lh);
}

int diameter(node *root)
{
    maxval = INT_MIN;
    int h = height(root);

    return maxval;
}

main()
{
    auto root = addnode(NULL, 12);
    root->left = addnode(root, 13);
    root->right = addnode(root, 14);
    root->left->right = addnode(root, 25);
    root->right->left = addnode(root, 11);
    root->left->right->left = addnode(root, 115);

    //      12
    // 13        14
    //    25  11
    // 115
    cout << "diameter of the tree is : " << diameter(root) << endl;
    cout << "tree\n";
    inorder(root);
}