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

void ldr(node*root)
{
	if(root==NULL)
	return;

	ldr(root->left);
	cout<<root->value;
	ldr(root->right);
}

int main()
{
node*root=construct();
ldr(root);
}42513
