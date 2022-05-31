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

void inordertraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

     inordertraversal(root->left);
    cout << " " << root->data;
    inordertraversal(root->right);
}

//construc ttree from given inorder and preorder

// approach ->

// preorder -> trraverse willget the root
// now in inorder seach for value to that root left side and right side
// int inorder[] = {4,2,1,3,5};
// int preorder[] = {1,2,4,3,5};

// preorder  ->    1 is root  in preorder   we get 2 4 to its left and 3 5  to its right

//

// storing index of a given vlaue in inorder
//unordered map //to get index uptil it. to use it to get left and right subtree
//get a value in preorderorder  seachit in map and then find the index and get its left and right values


int currIDX = 0;
unordered_map<int, int> mp;
node *constructTREE(int *inorder, int *preorder, int lb, int ub)
{
    if (lb > ub)
    {
        return NULL;
    }
    node *res = new node(preorder[currIDX++]);
    if(lb==ub) return res;
    int leftupto = mp[res->data];
    res->left = constructTREE(inorder, preorder, lb, leftupto -1);
    res->right = constructTREE(inorder, preorder, leftupto + 1, ub);

    return res;
}

node *BuildTREE(int inorder[], int preorder[], int n)
{
    for (int i = 0; i < n; i++)
    {
        mp[inorder[i]] = i;
    }

    node *root = constructTREE(inorder, preorder, 0, n-1);

    return root;
}

main()
{
    int inorder[] = {4, 2, 1, 3, 5};
    int preorder[] = {1, 2, 4, 3, 5};
    int n = 5;
    node *root = BuildTREE(inorder ,preorder ,5);

    //   1
    // 2   3
    //4      5

    inordertraversal(root);
}