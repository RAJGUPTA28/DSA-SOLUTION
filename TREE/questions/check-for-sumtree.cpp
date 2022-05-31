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

// root is sum of its left subtree and right subtree

//        8
//   -2      6
//  -1 -1   7 -1

//it is a sum treee

bool sum_tree = true;
int isSUMTREE(node *root)
{
    if (!root)
    {
        return 0;
    }
    if (!root->right && !root->left)
        return root->data;
    if (sum_tree == false)
        return 0;
    int a = isSUMTREE(root->left);
    int b = isSUMTREE(root->right);
    if (a + b != root->data)
        sum_tree = false;
    return a + b + root->data;
}

main()
{
    auto root = addnode(NULL, 8);
    root->left = addnode(root, -2);
    root->right = addnode(root, 6);
    root->left->right = addnode(root, -1);
    root->right->left = addnode(root, 7);
    root->left->left = addnode(root, -1);
    root->right->right = addnode(root, -1);

    //        8
    //   -2      6
    //  -1 -1   7 -1

    cout << "tree\n";
    inorder(root);

    isSUMTREE(root);
    cout << " \n the given tree is : " << sum_tree;
}