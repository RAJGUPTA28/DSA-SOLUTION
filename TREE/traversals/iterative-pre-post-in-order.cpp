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

// iterative

// trick

// stack   pair {node* , state}
// states 1 2 3
// state   valuepush   operation  check and push()
// 1  ->  preporder   state++   left
// 2  ->  inorder     state++  rigth
// 3. ->  postorder   pop()

void pre_in_post_order_traversal(node *root)
{
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    stack<pair<node *, int>> st; // node and state

    st.push({root, 1});

    while (!st.empty())
    {
        int state = st.top().second;
        node *temp = st.top().first;

        if (state == 1)
        {
            preorder.push_back(temp->data);
            st.top().second++; // state

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

    cout << "\npreorder " << endl;
    for (int i = 0; i < preorder.size(); i++)
    {
        cout << " " << preorder[i];
    }
    cout << "\ninorder " << endl;
    for (int i = 0; i < preorder.size(); i++)
    {
        cout << " " << inorder[i];
    }
    cout << "\npostorder " << endl;
    for (int i = 0; i < preorder.size(); i++)
    {
        cout << " " << postorder[i];
    }
}



void morristraverasalinorder(node *root)
{
    if (!root)
    {
        return;
    }

    vector<int> inorder;

    node *curr = root;

    while (curr)
    {
        if (curr->left == NULL)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {//inorder sucessor
            node *prev = curr->left;     //2nd time break m kaam aayegi
            while (prev->right != NULL && prev->right != curr)
            {
                prev = prev->right;
            };
            // link bna do 
            if(prev->right==NULL)
            {
                prev->right = curr;
                curr= curr->left;
            }//link hta do 
            else{
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }


    for(auto i : inorder){cout<<i<<" ";}
}



void morrispreorder(node* root)
{
    vector<int> preorer;

    node* curr = root ;

    while (curr)
    {
       if(curr->left == NULL)
       {
           preorer.push_back(curr->data);
           curr = curr->right;
       }
       else{
           node* prev = curr->left;
           while(prev->right !=NULL && prev->right!= curr)
           {
               prev = prev->right;
           }

           if(prev->right == NULL)
           {  prev->right = curr;
               preorer.push_back(curr->data);
               curr = curr->left;
           }
           else{
               prev->right  =NULL;
               curr = curr->right;
           }
       }
    }

cout<<"preorder ";
    for(auto i : preorer){cout<<i<<" ";}
    
}

main()
{
    auto root = addnode(NULL, 12);
    root->left = addnode(root, 13);
    root->right = addnode(root, 14);
    root->left->right = addnode(root, 25);
    root->right->left = addnode(root, 11);
    root->left->right->left = addnode(root, 115);

    //      12
    // 13        14
    //    25  11
    // 115

    cout << "tree\n";
    pre_in_post_order_traversal(root);

    cout<<endl;

    morristraverasalinorder(root);
    morrispreorder(root);
}