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
// find the bottom view of the tree
//      12
// 13        14
//     25  11    111
// 115

// if overlapping occurs print the element added recent
// bottomview->  115 11 14 111

//same as top view but the mark the occurance of very recently occured element  within that vertical level in teh map 



void bottomview(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<pair<Node *, int>> q; // Node height
    map<int, Node *> mp;

    q.push({root, 0});
    while (!q.empty())
    {
        Node *temp = q.front().first;
        int h = q.front().second;

        mp[h] = temp;
        q.pop();
        if (temp->left)
        {
            q.push({temp->left, h - 1});
        }
        if (temp->right)
        {
            q.push({temp->right, h + 1});
        }
    }


    for(auto val : mp)
    {
        cout<<" "<<val.second->data;
    }
}



 vector <int> bottomView(Node *root)
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
             mp[h] = curr;
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
    bottomview(root);
}