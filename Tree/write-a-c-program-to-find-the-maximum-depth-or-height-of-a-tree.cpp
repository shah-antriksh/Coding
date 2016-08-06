//http://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/

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
node * root = create(1);
root->left=create(2);
root->right=create(3);
root->left->left=create(4);
root->left->right=create(5);
return root;
}

int find_h(node* root)
{
if(root->left==NULL && root->right==NULL)
return 1;

int l = find_h(root->left);
int r = find_h(root->right);

int h = max(l,r)+1;
return h;
}

int main()
{

node*root = construct();
cout<<find_h(root);
}
