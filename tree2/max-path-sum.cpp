#include<bits/stdc++.h>
using namespace std;



// A path in a binary tree is a sequence of TreeNodes where each pair of adjacent TreeNodes in the sequence has an edge connecting them. A TreeNode can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the TreeNode's values in the path.
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

int maxi;
    int getmaxpath(TreeNode* root)
    {
        if(!root){return 0;}
      
        int lh = max(0,getmaxpath(root->left)); //left path
        int rh = max(0,getmaxpath(root->right)); //right path
        //logic ki uss node se hote hue max sum
        maxi = max(maxi , (lh + rh )+root->val);//ans max path sum

        return max(lh , rh) +root->val;//max l or r path
    }
    



    int maxPathSum(TreeNode* root) {
        
         maxi = INT_MIN;
         getmaxpath(root) ;
        
        return maxi;     
    }