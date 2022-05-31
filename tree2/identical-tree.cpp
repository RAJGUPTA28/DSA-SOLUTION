   #include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int val;
    Node *left;
    Node *right;

    Node(int d)
    {
        val = d;
        left = right = NULL;
    }
};

   
   
    bool isSameTree(Node* p, Node* q) 
    {
        if(p == NULL && q == NULL){return true;}
       else if(p==NULL || q == NULL){return false;}
        
    return ((p->val == q->val) && isSameTree(p->left,q->left) && 
                isSameTree(p->right ,q->right));
  
    }