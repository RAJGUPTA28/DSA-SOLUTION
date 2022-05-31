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

//      10
//   -2     6
//   8 -4   7 5

//sum tree is :-
//    20
//  4   12
// 0  0 0  0
int sumtree(node *root)
{
    if (!root)
    {
        return 0;
    }
    int a = sumtree(root->left);
    int b = sumtree(root->right);
    int x = root->data;
    root->data = a + b;

    return a + b + x;
}

main()
{
    auto root = addnode(NULL, 12);
    root->left = addnode(root, 13);
    root->right = addnode(root, 14);
    root->left->right = addnode(root, 25);
    root->right->left = addnode(root, 11);
    root->left->left = addnode(root, 115);

    //          12
    //     13        14
    // 115   25   11
    // 

    cout << "tree\n";
    inorder(root);

    sumtree(root);
    cout<<endl;
    inorder(root);
}