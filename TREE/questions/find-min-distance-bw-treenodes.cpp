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

// the distanceb/w two nodes in a binary tree is min when the distance is through lowest comman ancestor
//

//      12
// 13        14
//    25  11
// 115

//distance b/w 25 and 11 is   4
// which is through 12  their lowest comman ancestor

// distance b/t  25 and 115 is 1
//their lca is 25

node *findlca(node *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (root->data == n2 || root->data == n1)
    {
        return root;
    }

    node *llca = findlca(root->left, n1, n2);
    node *rlca = findlca(root->right, n1, n2);

    if (llca and rlca)
        return root;

    if (llca)
        return llca;
    else
        return rlca;
}

int distance(node *root, int val)
{
    if (!root)
        return 0;

    if (root->data == val)
        return 1;

    int l = distance(root->left, val);
    int r = distance(root->right, val);
    if (!l and !r)
        return 0;
    else
    {
        return l + r + 1;
    }
}

int distancebtwNODES(node *root, int nodeval1, int nodeval2)
{
    node *lca = findlca(root, nodeval1, nodeval2);

    int dist1 = distance(lca, nodeval1);
    int dist2 = distance(lca, nodeval2);


    return dist1 + dist2 -2;
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


    cout<<"\n   the distance b/w 115 and 11 node is : "<<distancebtwNODES(root,115 , 11);
}