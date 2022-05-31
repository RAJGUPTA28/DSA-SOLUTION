//Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.


   #include <bits/stdc++.h>
using namespace std;

class TreeNode
{

public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d)
    {
        val = d;
        left = right = NULL;
    }
};


 void solve(TreeNode* root, TreeNode* &pred) {
        TreeNode* curr = root;
        if(!root){return;}
          
        solve(curr->right, pred);
        solve(curr->left, pred);
        
        curr->right = pred;
        curr->left = NULL;
        pred = curr;
    } 

    void flatten(TreeNode* root) {
        TreeNode* pred = NULL;
        solve(root, pred);
    }