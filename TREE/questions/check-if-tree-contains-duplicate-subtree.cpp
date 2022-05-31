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
// duplicates subtree

// approach  we will create strings of the subtree and store it iin aa map
//and increase count later we will check for counts >= 2

// to avoid sum errors like
//   2              2     string is : 234
// 3   4               3
// string: 234            4   2$3$4

// to avoid this we will add extra strign $ when a NULl occurs to left or right



unordered_map<string, int> mp;
string generatestring(node *root)
{
    if (!root)
    {
        return "$";
    }
    string s = "";
    if (!root->left && !root->right)
    {
        s = to_string(root->data);
        return s;
    }

    s = s + to_string(root->data);
    s = s + generatestring(root->left);
    s = s + generatestring(root->right);

    mp[s]++;

    return s;
}

bool isduplicatesubtrees(node *root)
{

    generatestring(root);
    for (auto val : mp)
    {
        if (val.second >=2)
        {
            cout << " " << val.first;
            return true;
        }
    }
    return false;
}

main()
{
    auto root = addnode(NULL, 1);
    root->left = addnode(root, 2);
    root->right = addnode(root, 3);
    root->left->right = addnode(root, 5);
    root->left->left = addnode(root, 4);
    root->right->right = addnode(root, 2);
    root->right->right->right = addnode(root, 5);
    root->right->right->left = addnode(root, 4);
    //        1
    //     2     3
    //   4   5     2
    //           4   5

    cout << "tree\n";
    inorder(root);


    cout<<"\nthe tree has duplicatres subtree "<<isduplicatesubtrees(root);
}