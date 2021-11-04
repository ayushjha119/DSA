#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node (int val)
    {
        data = val;
        left = right = NULL;
    }
};

vector<int> mytree;
Node *create_tree(){

    int root_data;
    cout<<"Enter root data"<<endl;
    cin>>root_data;

    if(root_data==-1)
        return NULL;

    Node *root = new Node(root_data);
    queue<Node *> pending_Node;
    pending_Node.push(root);

    while(pending_Node.size()!=0)
    {
        Node *front = pending_Node.front();
        pending_Node.pop();

        cout<<"Enter the left child of "<<front->data<<endl;
        int left_child_data;
        cin>>left_child_data;
        if(left_child_data!=-1)
        {
            Node *child = new Node(left_child_data);
            front->left=child;
            pending_Node.push(child);
        }

        cout<<"Enter the right child of "<<front->data<<endl;
        int right_child_data;
        cin>>right_child_data;
        if(right_child_data!=-1)
        {
            Node *child = new Node(right_child_data);
            front->right=child;
            pending_Node.push(child);
        }

    }

    return root;
}




void dfs(Node *root,vector<int> &mytree)
{
     if(root==NULL)
        return;
    dfs(root->left,mytree);
    mytree.push_back(root->data);
    dfs(root->right,mytree);
}

vector<int> Inorder_traversal(Node *root)
{

    dfs(root,mytree);
    return mytree;

}

int main(){


    Node *root = create_tree();

    Inorder_traversal(root);

    for (int i = 0; i < mytree.size(); i++)
    {
        /* code */

        cout<<mytree[i]<<" ";
    }



return 0;
}

