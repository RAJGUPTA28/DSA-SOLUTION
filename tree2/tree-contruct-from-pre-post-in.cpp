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




 int CurrIDX;
    unordered_map<int,int> mp;
    
    TreeNode* gettree(vector<int>& inorder, vector<int>& postorder , int lb ,int ub)
    {
        if(lb>ub){return NULL;}
        
         TreeNode* root = new TreeNode(postorder[CurrIDX--]);
        if(lb == ub){return root;}
        int upto = mp[root->val];
        
         root->right = gettree(inorder,postorder , upto + 1 ,ub);
         root->left =  gettree(inorder,postorder,lb , upto - 1 );
    
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        int n = inorder.size();
      for(int i = 0 ; i <n ;i++)
      {mp[inorder[i]] = i;}
        CurrIDX = n -1 ;
        
       TreeNode*  root = gettree(inorder,postorder,0 , n-1);
        
        return root;
    }







/////////////////////////////////////////////////////////////////////

 int currIDX;
    unordered_map<int , int> mp;
    TreeNode* maketree(vector<int>& preorder, vector<int>& inorder ,int lb , int ub)
    {
        if(lb>ub){return NULL;}
        TreeNode* root = new  TreeNode(preorder[currIDX++]);
               
        if(lb == ub){return root;}
        int upto = mp[root->val];
        
            root->left = maketree(preorder ,inorder , lb ,upto -1);
            root->right= maketree(preorder ,inorder , upto +1 ,ub);
        
        
        return root;
    }
    
    
    
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0 ; i <n;i++)
        {mp[inorder[i]] = i; }
        currIDX = 0;
        
        TreeNode* root = maketree(preorder , inorder ,0 , n-1);
        
        return root;
    }


