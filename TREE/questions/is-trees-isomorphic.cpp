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
// isomorphic tree
//given 2 trees checkthey are isomorphic or not

//    1                 1            not isomorphic
//   2   3            3   2
//  4               4

//    1                 1           isomorphic
//   2   3            3   2
//  4                       4


//    1                 1           isomorphic
//   2   3            3   2
//  4                    4   


//    1                 11           isomorphic
//   2   3            13    12
//  4                          14   

//trees havign swops child are also  isomorphic 
// one to one maping must be there
//aproach the child nodes  to a tree must be same 
// evenswaped oreven diffrent valued

// if a node in one tree is returning null then other should also give null at the same time


bool istreesISOMORPHIC(node* root , node* root1)
{
    if(!root && !root1 ) return true; // both pointing to null at same time  
    if(!root || !root1)  return false;


bool directsame= istreesISOMORPHIC(root->left , root1->left)and istreesISOMORPHIC(root->right ,root1->right);
bool swapedsame =  istreesISOMORPHIC(root->left,root1->right)  and istreesISOMORPHIC(root->right , root1->left);


return directsame or swapedsame;

}





main()
{
    auto root = addnode(NULL, 1);
    root->left = addnode(root, 2);
    root->right = addnode(root, 3);
   root->left->left = addnode(root , 4);


    auto root1= addnode(NULL ,1);
    root1->right = addnode(root1 , 2);
    root1->left = addnode(root1 , 3);
    root1->right->right = addnode(root1,4);

  


    //    1                 1           isomorphic
    //   2   3            3   2
    //  4                       4

    cout << "tree 1\n";
    inorder(root);
      cout << "\ntree 1\n";
    inorder(root1);

    cout<<"\nthe given trees are isomorphic : "<<istreesISOMORPHIC(root , root1);}