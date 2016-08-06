//http://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/

#include<iostream>
using namespace std;

struct node
{
int value;
node *left;
node* right;
};

node* create(int value)
{
node * temp = new node;
temp->value=value;
temp->left=NULL;
temp->right=NULL;
return temp;
}

node * construct()
{
node * root = create(20);
root->left=create(8);
root->right=create(22);
root->left->left=create(4);
root->left->right=create(12);
root->left->right->left=create(10);
root->left->right->right=create(14);
root->right->left=create(25);
return root;
}

void left_side(node*root)
{
	if(root->left==NULL && root->right==NULL)
	return;
	cout<<root->value<<" ";
	if(root->left!=NULL)
	left_side(root->left);
	else if(root->right!=NULL)
	left_side(root->right);
	else
	return;
}

void leaf(node*root)
{
	if(root==NULL)
	return;	
	if(root->left==NULL && root->right==NULL)
	{
	cout<<root->value<<" ";
	return;
	}
	leaf(root->left);
	leaf(root->right);
}

void right_side(node*root)
{
	if(root->left==NULL && root->right==NULL)
	return;
	if(root->right!=NULL)
	left_side(root->right);
	else if(root->left!=NULL)
	left_side(root->left);
	cout<<root->value<<" ";
}



int main()
{
node*root=construct();
left_side(root);
leaf(root);
right_side(root);
}20 8 4 10 14 25 22 20 
