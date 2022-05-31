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

// sum of  nodes onlongest path from root to leaf
// if max height same for some pairs return the max sum val.
// making pair of height and sum uptil that root

//approach
// height ,sum

pair<int, int> sumoflongest(node *root)
{
    if (!root)
        return {0, 0};

    pair<int, int> lh = sumoflongest(root->left);
    pair<int, int> rh = sumoflongest(root->right);

    if (lh.first > rh.first)
    {
        return {lh.first + 1, lh.second + root->data};
    }
    // lsum   lheight

    if (rh.first > lh.first)
    {
        return {rh.first + 1, rh.second + root->data};
    }//rsum  rheight
    else
    {
        return {lh.first + 1, max(lh.second, rh.second) + root->data};
    }
}

int SUMofNODESonlongestpath(node *root)
{
    pair<int, int> max_height_sum;
    max_height_sum = sumoflongest( root);
    cout<<"\nheight is: "<<max_height_sum.first;
    return max_height_sum.second;
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

    cout << "tree\n";
    inorder(root);

    cout<<"\n the sum is :"<<SUMofNODESonlongestpath(root);
}