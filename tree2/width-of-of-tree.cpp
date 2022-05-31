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

// in widh we also haveto take in count the null nodes in b/w
//   1
//  2 3   ans is 4
// 4   5

//  1
// 2  //ans is 2
// 3  5

// use the level order traversal operations
// assign label  left 2 *i   right = 2*i + 1
// width uss level ka  (maxlabel -  minlabel)  + 1

int widthoftree(Node *root)
{
    if (!root)
    {
        return 0;
    }

    queue<pair<Node *, int>> q; // node  label
    q.push({root, 1});
    // root ka label 1

    int minlabel;
    int maxlabel;
    while (!q.empty())
    {
        int n = q.size();
       
        minlabel = q.front().second;
      
        while (n--)
        { Node *temp = q.front().first;
            int label = q.front().second;
            q.pop();
            if (temp->left)
            {
                q.push({temp->left, 2 * label});
            }
            if (temp->right)
            {
                q.push({temp->right, 2 * label + 1});
            }
            maxlabel = label;
        }
    }

    int ans = (maxlabel - minlabel) + 1;


    return ans;
}

main()
{
    auto root = addNode(NULL, 12);
    root->left = addNode(root, 13);
    root->right = addNode(root, 14);
    root->left->left = addNode(root, 25);
    root->right->right = addNode(root, 11);
    

    //      12
    // 13        14
    //25            11
    

    cout << "tree\n";

   cout<<widthoftree(root);
}