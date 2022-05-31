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
// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

//convert binary tree to strign and agaiin string to tree 



//getline (s ,str ,',')// from stream give m string str until deliminator ',' occurs 
 string serialize(TreeNode* root) {
        string s  ="";
        if(!root){return s;}
        
        queue<TreeNode*> q;
        q.push(root);
        //level order
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr == NULL)
            {
                s.append("#,") ;
            }
            else{
                 
                s.append(to_string(curr->val)+',');
            }
            
            if(curr)
            {
               q.push(curr->left);
               q.push(curr->right);
            }
        }
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(!data.length()){return NULL;}
        
        stringstream s(data);
        string str;
        
        getline(s ,str,',');   //from stream  to strign deliminator
            
        TreeNode* root = new TreeNode(stoi(str));
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* currNode = q.front();
            q.pop();
            
            //left node
            getline(s, str , ',');
                
                if(str == "#")
                {
                    currNode->left = NULL;
                }
                else{
                    currNode->left = new TreeNode(stoi(str));
                    q.push(currNode->left);
                }
            
              //right tree
            getline(s, str , ',');
                
                if(str == "#")
                {
                    currNode->right = NULL;
                }
                else
                {
                    currNode->right = new TreeNode(stoi(str));
                    q.push(currNode->right);
                }
        }
    
        
        
        return root;
    }