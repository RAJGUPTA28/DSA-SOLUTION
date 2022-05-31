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

//      12
// 13        14
//    25  11
// 115

// left view - >  12 13 25 115
void leftview(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;

    q.push(root);
    while (!q.empty())
    {

        int sz = q.size();
        cout << " " << q.front()->data;
        while (sz--)
        {
            Node *temp = q.front();
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
    }
}
vector<int> leftView(Node *root)
{
  queue<Node*> q;
  
 q.push(root);
  vector<int> ans;
  if(!root){return ans;}
 
  
  while(!q.empty())
  {
     ans.push_back(q.front()->data);
      int n = q.size();
      while(n--)
      { Node* temp = q.front();
          q.pop();
          if(temp->left){q.push(temp->left);}
          if(temp->right){q.push(temp->right);}
      }
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

    //      12
    // 13        14
    //    25  11
    // 115

    cout << "tree\n";
    leftview(root);
}