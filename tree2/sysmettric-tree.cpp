


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
//Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
   
bool checksymetry(TreeNode* root1 , TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL){return true;}
        if(!root1 ||  !root2){return false;}
        
        return (root1->val == root2->val)&&checksymetry(root1->left ,root2->right)&&
            checksymetry(root1->right , root2->left);
    }
    
    
    bool isSymmetric(TreeNode* root) {
        if(!root){return true;}
        return checksymetry(root->left , root->right);
        
        
    }