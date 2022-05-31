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

int maxsum;
int largestsubtreeSum(node *root)
{
    if (!root)
    {
        return 0;
    }

    int lsum = largestsubtreeSum(root->left);
    int rsum = largestsubtreeSum(root->right);

    maxsum = max(maxsum, lsum + rsum + root->data);

    return lsum + rsum + root->data;
}

int maxsumsubtree(node *root)
{
    maxsum = INT_MIN;

    largestsubtreeSum(root);
    return maxsum;
}

main()
{
    auto root = addnode(NULL, -12);
    root->left = addnode(root, 13);
    root->right = addnode(root, -14);
    root->left->right = addnode(root, 25);
    root->right->left = addnode(root, 11);
    root->left->right->left = addnode(root, 115);

    //      -12
    // 13        -14
    //    25  11
    // 115

    cout << "tree\n";
    inorder(root);

    cout << " \nthe max subtree sum is: " << maxsumsubtree(root);
}