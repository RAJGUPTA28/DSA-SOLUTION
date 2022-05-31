#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node *addnode(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    node *newnode = new node(data);

    return newnode;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << " " << root->data;
    inorder(root->right);
}

// PRINT ALL PATHS B/W NODES HAVING SUMOFNODES AS GIVEN SUM K

//  //                  1
//              4      -1
//                -2  3
//              0
//  IF K = 3
//     ANSWER IS:
// 1 4 -2
// 14-2 0
// 1 -1 3
// 3

// APPROACH : -   TAKE A VECTOR STORE ALL NODES FOUND WHILE REACHING TO LEAF NODE
// NOT START TRAVERSING THE LEAF NODE FROM LAST AND CALC SUM  .. PRINT AS FOUND THEN REMOVE THE NODE AND REPEAT SAME FOR OTHER NODES

void Rootwithgivensum(node *root, vector<int> &path, int K)
{
    if (!root)
        return;

           path.push_back(root->data);
    Rootwithgivensum(root->left, path, K);
    Rootwithgivensum(root->right, path, K);

 
    int SUM = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        SUM += path[i];
        if (SUM == K)
        {
            for (int j = i; j < path.size(); j++)
            {
                cout << " -> " << path[j];
            }
            cout<<endl;
        }
    }
    path.pop_back();
}


void KsumPATHS(node* root , int K)
{
    if(!root)
    {return;}
    vector<int> path;
    Rootwithgivensum(root, path ,K);
}

main()
{
    auto root = addnode(NULL, 1);
    root->left = addnode(root, 4);
    root->right = addnode(root, -1);
    root->left->right = addnode(root, -2);
    root->right->left = addnode(root, 3);
    root->left->right->left = addnode(root, 0);

    //                  1
    //              4      -1
    //                -2  3
    //              0

    cout << "tree\n";
    inorder(root);

    int K;
    cout << " \nENTER K VALUE : ";
    cin >> K;

    KsumPATHS(root , K);
}