#include<bits/stdc++.h>
using namespace std;

 
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

 
 
 
 
 
 
 
 
 //SAME CODE WOULD NOT WORK IN LEETCODE
 vector<int> verticalOrder(Node *root)
{
    map<int, vector<int>> mp;
    vector<int> ans;
    queue<pair<Node *, int>> q;
    int h = 0;

    q.push({root, 0});
    while (!q.empty())
    {
        Node *curr = q.front().first;
        h = q.front().second;
        q.pop();
        mp[h].push_back(curr->data);
         if (curr->left)
        {
            q.push({curr->left, h - 1});
        }
        if (curr->right)
        {
            q.push({curr->right, h + 1});
        }
      
    }


    for (auto val : mp)
    {
      for(auto t : val.second)
      {
          ans.push_back(t);
      }
    }
    
    
    return ans;
}