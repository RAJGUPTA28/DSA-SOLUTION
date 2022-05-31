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


void inorder(node* root )
{
    if(root == NULL)
    {
        return ;
    }

    inorder(root->left);
    cout<<" "<<root->data;
    inorder(root->right);
}
    //      12 
    // 13        14
    //    25  11
    // 115

    // rigth view  12 14 11 115
void rightview(node* root)
{
    if(root == NULL) return;
    queue<node* > q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();
         cout<<" "<<q.front()->data;
        while (sz--)
        { node* temp = q.front();
          q.pop();
            if(temp->right){q.push(temp->right);}
            if(temp->left){q.push(temp->left);}
        }
       
    }
    
}


main()
{
    auto root = addnode(NULL, 12);
    root->left = addnode(root, 13);
    root->right = addnode(root, 14);
    root->left->right = addnode(root , 25);
    root->right->left = addnode(root,11);
    root->left->right->left = addnode(root , 115);

    //      12 
    // 13        14
    //    25  11
    // 115

cout<<"tree\n";
rightview(root);    
}