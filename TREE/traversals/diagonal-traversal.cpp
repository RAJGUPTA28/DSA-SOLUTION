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

//        12
//  13        14
//      25         11
//   /          /
// 115        100

// diagonal traversal ->  12 14 11   13 25 100   115

// from a node keep traversing to right until null then if it has left child store it in a queue
// .. node use nodes present in queue to follow same thing

void diagonaltraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    vector<int> ans;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        while (temp)
        {
            if (temp->left)
            {
                q.push(temp->left);
            }
            ans.push_back(temp->data);

            temp = temp->right;
        }
       
    }

    for (auto val : ans)
    {
        cout << " " << val;
    }
}

main()
{
    auto root = addnode(NULL, 12);
    root->left = addnode(root, 13);
    root->right = addnode(root, 14);
    root->left->right = addnode(root, 25);
    // root->left->right->right = addnode(root , 36);
    root->right->right = addnode(root, 11);
    root->left->right->left = addnode(root, 115);
    root->right->right->left = addnode(root, 100);
    //        12
    //  13        14
    //     25         11
    //   /   \        /
    // 115        100

    cout << "tree\n";
    diagonaltraversal(root);
}