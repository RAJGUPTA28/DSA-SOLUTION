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

//        8
//   -2      6
//  -1 -1   7 -1

// we have to make it a dll acc to inorder-traversal
// -1  -2  -1  8  7  6  -1

void makedll(node *root, node *&head, node *&prevnode, int &f)
{
    if (root == NULL)
    {
        return;
    }

    makedll(root->left, head, prevnode, f);
    if (f == 0)
    {
        f = 1;
        head = root;
        prevnode = root;
        head->left = NULL;

    }
    else
    {
        prevnode->right = root;
        prevnode->right->left = prevnode;
        prevnode =prevnode->right;
        
    }

    makedll(root->right , head , prevnode , f);
}

node *convertTOdll(node *root)
{
    node *head = NULL;
    node *prevnode = NULL;

    int f = 0;

    makedll(root, head, prevnode, f);

    return head;
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

    cout << " \ndll is : ";
    auto head = convertTOdll(root);
    auto temp = head;
    while (temp)
    {
        cout << "  ->  " << temp->data;
        temp = temp->right;
    }
}