#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

bool path(Node *root, vector<int> &ans, int val)
{
    if (!root)
    {
        return false;
    }

    ans.push_back(root->data);

    if (root->data == val)
    {
        return true;
    }

    if (path(root->left, ans, val) || path(root->right, ans, val))
    {
        return true;
    }

    ans.pop_back();
    return false;
}

vector<int> solve(Node *A, int B)
{
    vector<int> ans;
    path(A, ans, B);

    return ans;
}