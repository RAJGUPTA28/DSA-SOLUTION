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

// lowest comman ancestor - the very first parent to both given nodes
//                  1
//              4      -1
//          10   -2   3
//              0

// for -2 and 3   1 is ancestor
// for 10 and 4   4 is ancestor
//0   and 3  ->   1
// -2  & 10   -> 4
// 4   & -1  -> 1

//approach if a node is getting Null from any ofiits sides it is not the lca  of given nodes 

// hence we would search for a node with corresponds to both sides a node value is present
// for some case where the given nodes have some parent child relation we would return the parent



node*  LOWESTCOMMANANCESTOR(node* root,int n1 ,int n2)
{
    if(!root) return NULL;
    if(root->data == n1 or root->data == n2) 
           return root;

    node* llca = LOWESTCOMMANANCESTOR(root->left , n1 ,n2);
    node* rlca = LOWESTCOMMANANCESTOR(root->right, n1 , n2);

    if(llca and rlca)  
        return root; // getting some not null value from left and right

    if(llca) return llca;
    else {return rlca;}
}



main()
{
    auto root = addnode(NULL, 1);
    root->left = addnode(root, 4);
    root->left->left = addnode(root, 10);
    root->right = addnode(root, -1);
    root->left->right = addnode(root, -2);
    root->right->left = addnode(root, 3);
    root->left->right->left = addnode(root, 0);

    //                   1
    //               4      -1
    //           10    -2  3
    //                0

    cout << "tree\n";
    inorder(root);

node* val = LOWESTCOMMANANCESTOR(root, 10 ,4);
cout<<"\n lca of 10 4 ->  " <<val->data;
cout<<"\n lca of 0 3  -> " <<LOWESTCOMMANANCESTOR(root, 0 ,3)->data;
cout<<" \nlca of -2 -1  -> " <<LOWESTCOMMANANCESTOR(root, -2 ,-1)->data;
cout<<"\n lca of  4  -1  -> " <<LOWESTCOMMANANCESTOR(root, -1 ,4)->data;


}