//http://www.geeksforgeeks.org/diameter-of-a-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct node
{
node *left,*right;
int value;
};

node* create(int value)
{
node* temp = new node();
temp->value=value;
temp->left = NULL;
temp->right = NULL;
return temp;
}

node * construct()
{
node * root = create(0);

root->left=create(0);
root->left->left=create(0);
root->left->right=create(0);
root->left->right->left=create(0);
root->left->right->left->left=create(0);
root->left->right->left->right=create(0);
root->left->right->right=create(0);
root->right=create(0);
root->right->left=create(0);
root->right->right=create(0);
root->right->right->right=create(0);
root->right->right->right->left=create(0);
root->right->right->right->left->left=create(0);
root->right->right->right->left->right=create(0);
root->right->right->right->right=create(0);
return root;
}

int diam(node*root,int * mx)
{
if(root==NULL)
return 0;

if(root->left==NULL && root->right==NULL)
return 1;

int lc = diam(root->left,mx);
int rc = diam(root->right,mx);
if(lc+rc+1>*mx)
*mx=lc+rc+1;

return (max(lc,rc)+1);
}

int main()
{
node*root=construct();
int * mx = new int;
*mx=0;
diam(root,mx);
cout<<*mx;
}10
