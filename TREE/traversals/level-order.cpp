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

void levelordertraversal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        cout << " " << temp->val;
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}


vector<vector<int>> levelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    vector<vector<int>> ans;
    if (!root)
    {
        return ans;
    }
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        vector<int> semi;
        while (n--)
        {
            TreeNode *temp = q.front();
            q.pop();

            semi.push_back(temp->val);

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }

        ans.push_back(semi);
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

    //      12
    // 13        14
    //    25  11
    // 115

    cout << "tree\n";

    levelordertraversal(root);
}