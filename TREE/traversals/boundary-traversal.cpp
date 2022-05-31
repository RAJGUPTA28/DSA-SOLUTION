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
//     13        14
//  56   25    11
//      115

// boundary traversal = 12 13 56 115 11 14

// we will break the ques in 3 parts
// left   right   leaf nodes

void leftraversal(node *root, vector<int> &ans)
{
    if (!root)
        return;
    if (root->left)
    {   ans.push_back(root->data);
        leftraversal(root->left, ans);
     
    }
    else if(root->right)
    {ans.push_back(root->data);
        leftraversal(root->right , ans);
        
    }
}

void leaftraversal(node* root , vector<int> &ans)
{
    if(root == NULL) return;
    leaftraversal(root->left , ans);
    if(!root->right && !root->left)
    {
        ans.push_back(root->data);
    }
    leaftraversal(root->right,ans);
}

void righttraversal(node* root , vector<int> &ans)
{
    if(root == NULL ) return;
    if(root->right)
    {
       righttraversal(root->right , ans);
       ans.push_back(root->data);
    }
    else if(root->left)
    {
        righttraversal(root->left  ,ans);
        ans.push_back(root->data);
    }
}

 vector<int> boundarytraversal(node *root)
{
    
     vector<int> ans;
          if(!root){return ans;}
          if(!root->right && !root->left)
          {ans.push_back(root->data);
           return ans;}
    ans.push_back(root->data);
    leftraversal(root->left, ans);
    leaftraversal(root, ans);
    righttraversal(root->right, ans);

    for(auto val : ans)
    {
        cout<<" "<<val;
    }

    return ans;
}

main()
{
    auto root = addnode(NULL, 12);
    root->left = addnode(root, 13);
    root->left->right = addnode(root, 56);
    root->right = addnode(root, 14);
    root->left->right = addnode(root, 25);
    root->right->left = addnode(root, 11);
    root->left->right->left = addnode(root, 115);

    //      12
    //   13        14
    // 56    25  11
    //     115

    cout << "tree\n";
 boundarytraversal(root);
}