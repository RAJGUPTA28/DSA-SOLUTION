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

Node *addNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    Node *newNode = new Node(data);

    return newNode;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << " " << root->data;
    inorder(root->right);
}

// approach make vertvcal level
// use height 1 for right and -1 for left for each Node to find its vertical level
//use map and queue to mark the first occurance of teh level val
// eg ->  12 25 11 are in same level oth 13 115 same level -1  and 111 at level

// -1      0     1    2
//        12
// 13           14
//      25   11     111
// 115 

// top view -> 13 12 14 111

void topview(Node *root)
{

    if(root == NULL){return;}
    map<int, Node *> mp;
 
    queue<pair<Node *, int>> q; // Node , its height;
    q.push({root, 0});
    while (!q.empty()) 
    {
        Node *temp = q.front().first;
      int  h = q.front().second;
        q.pop();
        if (!mp[h])
        {
            mp[h] = temp;
        }
           if (temp->left)
        {
            q.push({temp->left, h - 1});
        }
        if (temp->right)
        {
            q.push({temp->right, h + 1});
        }
     
    }

    for (auto val : mp)
    {
        cout << " " << val.second->data;
    }
}



    vector<int> topView(Node *root)
    {
        map<int , Node*> mp;
        //last time occurance of any vertical level 
      //  left h - 1  right h + 1
        vector<int>ans;
        
        if(!root){return ans;}
        queue<pair<Node*, int>>q;
        
        int h = 0;
        
        q.push({root ,0});
        
        while(!q.empty())
        {
            Node* curr = q.front().first;
            h = q.front().second;
             q.pop();
            if(!mp[h]) {mp[h] = curr;}
            if(curr->left){q.push({curr->left ,h -1});}
            if(curr->right){q.push({curr->right,h+1});}
        }
        
     
        for(auto val : mp)
        {
            ans.push_back(val.second->data);
        }
        
        return ans;
    
    
    }

main()
{
    auto root = addNode(NULL, 12);
    root->left = addNode(root, 13);
    root->right = addNode(root, 14);
    root->left->right = addNode(root, 25);
    root->right->left = addNode(root, 11);
    root->left->right->left = addNode(root, 115);
    root->right->right = addNode(root, 111);
    //      12
    // 13        14
    //    25  11    111
    // 115

    cout << "tree\n";
    topview(root);
}