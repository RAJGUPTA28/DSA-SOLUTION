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

TreeNode *addTreeNode(TreeNode *root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return root;
    }
    TreeNode *newTreeNode = new TreeNode(val);

    return newTreeNode;
}

void inordertraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

     inordertraversal(root->left);
    cout << " " << root->val;
    inordertraversal(root->right);
}

//construc ttree from given inorder and postorder

// approach ->

// postorder -> trraverse willget the root
// now in inorder seach for value to that root left side and right side
// int inorder[] = {4,2,1,3,5};
// int postorder[] = {1,2,4,3,5};

// postorder  ->    1 is root  in postorder   we get 2 4 to its left and 3 5  to its right

//

// storing index of a given vlaue in inorder
//unordered map //to get index uptil it. to use it to get left and right subtree
//get a value in postorderorder  seachit in map and then find the index and get its left and right values


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




main()
{
    int inorder[] = {4, 2, 1, 3, 5};
    int postorder[] = {1, 2, 4, 3, 5};
    int n = 5;
  

    //   1
    // 2   3
    //4      5

   
}