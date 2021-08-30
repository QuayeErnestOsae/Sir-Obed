#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int );
Node* Insert(Node*,int);
bool Search(Node*,int);
void levelOrder(Node*);

int main(void)
{
    Node* root=NULL;
    root= Insert(root,15);
    root= Insert(root,10);
    root= Insert(root,20);
    root= Insert(root,8);
    root= Insert(root,17);

   /* int C;
    cout<<"Input search value: ";
    cin>>C;

    if(Search(root,C)==true)
    {
        cout<<" Result Found";
    }
    else
        cout<<" Result Not Found";

*/
levelOrder(root);
}



Node* Insert(Node* root,int data)
{
    if(root==NULL)
        root=newNode(data);

    else if(data>root->data)
    {
        root->right=Insert(root->right, data);
    }

    else
    {
        root->left=Insert(root->left,data);
    }
    return root;
}

Node* newNode(int data)
{
    Node* node=new Node();
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

bool Search(Node* root, int data)
{
    if(root==NULL)
        return false;

    else if(root->data==data)
        return true;

    else if(data<=root->data)
    {
        return Search(root->left,data);
    }
    else
        return Search(root->right,data);

}


void levelOrder(Node* root)
{
    if(root==NULL)
        return;
    queue<Node*> Q;
    Q.push(root);
    while(! Q.empty())
    {
        Node*current=Q.front();
        cout<<current->data<<" ";

        if(current->left !=NULL)
        {
            Q.push(current->left);
        }
        if(current->right !=NULL)
        {
            Q.push(current->right);
        }
        Q.pop();
    }
}
