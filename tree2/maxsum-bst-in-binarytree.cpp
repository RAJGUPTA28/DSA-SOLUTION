 
 
 
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
 
 //same as largest bst in binary tree but meaning 
//hrr ek node k liye
 //(isbst , sum , left min , right max)

 //hrr baar return marne se pehle maxsuum m se compare krr lena h ki kon max h
 
 
 
 int maxsum;
    vector<int> maxsumBST(TreeNode* root)
    {
        if(!root){return {1,0,INT_MAX ,INT_MIN};}
        if(!root->left && !root->right)
        {   maxsum = max(maxsum , root->val);
            return {1 , root->val , root->val ,root->val};}
        
        
        
        vector<int> lt = maxsumBST(root->left);
        vector<int> rt = maxsumBST(root->right);
        
        if(lt[0] && rt[0])
        {
            if(lt[3] <root->val && root->val<rt[2])
            { 
               int minl = lt[2];
               int maxr = rt[3];
                if(minl == INT_MAX){minl = root->val;}
                if(maxr == INT_MIN){maxr = root->val;}
                
                maxsum = max(maxsum ,root->val + rt[1] + lt[1]);
                return {1,root->val + rt[1] + lt[1],minl , maxr};
               
                
            }
               int sum = max(rt[1] , lt[1]);
               maxsum = max(maxsum , sum);
               return {0,sum,0, 0};
        }
        
        
        return {0,max(rt[1] ,lt[1]) ,0 ,0};
    }
    
    
    int maxSumBST(TreeNode* root) {
     vector<int> ans;
        maxsum = 0;
    ans = maxsumBST(root);
        return maxsum;
        
    }