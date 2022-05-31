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

// LEETCODE NOT DONE



void inorder(Node* root)
{
    if(!root){return;}
    
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}



void allinone(Node *root)
{
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    stack<pair<Node *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        int state = st.top().second;
        Node *temp = st.top().first;

        if (state == 1)
        {
            preorder.push_back(temp->data);
            st.top().second++;

            if (temp->left)
            {
                st.push({temp->left, 1});
            }
        }
        else if (state == 2)
        {
            inorder.push_back(temp->data);
            st.top().second++;

            if (temp->right)
            {
                st.push({temp->right, 1});
            }
        }
        else
        {

            postorder.push_back(temp->data);
            st.pop();
        }
    }




    for(auto v:inorder)
    {       cout<<v<<" ";}
       cout<<endl;
    for(auto v1:preorder)
    {cout<<v1<<" ";}
    cout<<endl;
    for(auto v :postorder)
    {cout<<v<<" ";}
}



void getverticalorder(Node*root, int h ,map<int ,vector<int>> &mp)
{

    if(!root){return;}

    mp[h].push_back(root->data);
    getverticalorder(root->left , h-1 , mp);
    getverticalorder(root->right , h+1 ,mp);

}



void verticalord(Node* root)
{
    map<int ,vector<int>> mp;

    getverticalorder(root, 0 , mp);



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
  allinone(root);
}