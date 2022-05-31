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

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << " " << root->val;
    inorder(root->right);
}

//      12                 ->
// 13        14            <-
//    25  11    111        ->
// 115                     <-

//   zigzag->   12  14 13  25 11 111  115
// approach normal traversal  fir reverse the even levels and push in a vector
void zigzagtraversal(TreeNode *root)
{
    if (root == NULL)
          return;

    int f = 1; // 0  1 indicating odd even
    queue<TreeNode *> q;
 
    vector<int> ans;
    q.push(root);
    while (!q.empty())
    {   vector<int> t;
        int sz = q.size();

        while (sz--)
        {
            TreeNode *temp = q.front();
            t.push_back(temp->val);
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        if (f % 2 == 0)
        {
            reverse(t.begin(), t.end());
        }

        for(auto val : t){ans.push_back(val);}
        f = !f; //alternate levels
    }


    for(auto v :ans)
    {
        cout<<" " <<v;
    }
}

 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){return ans;}
        int f = 1;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> t;
            int n = q.size();
          
            while(n--)
            {   TreeNode* temp = q.front();
                q.pop();
                t.push_back(temp->val);
             if(temp->left){q.push(temp->left);}
             if(temp->right){q.push(temp->right);}
            }
            if(f==0){reverse(t.begin() ,t.end());}
            ans.push_back(t);
            f = !f; //flip flop
        }
        
        return ans;
    }
main()
{
    auto root = addTreeNode(NULL, 12);
    root->left = addTreeNode(root, 13);
    root->right = addTreeNode(root, 14);
    root->left->right = addTreeNode(root, 25);
    root->right->left = addTreeNode(root, 11);
    root->left->right->left = addTreeNode(root, 115);
    root->right->right = addTreeNode(root, 111);
    //      12
    // 13        14
    //    25  11    111
    // 115

    cout << "tree\n";
    zigzagtraversal(root);
}