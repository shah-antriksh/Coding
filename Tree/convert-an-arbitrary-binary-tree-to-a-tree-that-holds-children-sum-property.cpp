//http://www.geeksforgeeks.org/convert-an-arbitrary-binary-tree-to-a-tree-that-holds-children-sum-property/

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
/*
node * root = create(4);
root->left=create(2);
root->right=create(6);
root->left->left=create(1);
root->left->right=create(3);
root->right->left=create(5);
root->right->right=create(8);
*/

/*
node * root = create(17);
root->left=create(20);
root->right=create(11);
root->left->left=create(1);
root->left->right=create(5);
root->right->left=create(3);
root->right->right=create(2);
*/
/*
node * root = create(100);
root->left=create(20);
root->left->left=create(10);
*/
node * root = create(1000000);
root->left=create(20);
root->left->left=create(10000);


return root;
}

void fix(node * root)
{
int lc=0,rc=0;
if(root->left==NULL && root->right==NULL)
return;

if(root->left!=NULL)
lc = root->left->value;
if(root->right!=NULL)
rc = root->right->value;

int diff = root->value-lc-rc;
if(root->left!=NULL)
{
	root->left->value+=diff;
	fix(root->left);
}

else
{
	root->right->value+=diff;
	fix(root->right);

}

}

int traverse(node*root)
{
	int lc=0,rc=0;
	if(root==NULL)
	return 0;
	if(root->left==NULL && root->right==NULL)
	return root->value;

	lc=traverse(root->left);
	rc=traverse(root->right);

	if(lc+rc>root->value)
	{
	int diff=lc+rc-root->value;
	root->value+=diff;
	return root->value;
	}

	else
	{
	fix(root);
	return root->value;
	}
}

void ldr(node*root)
{
	if(root==NULL)
	return;
	
	cout<<root->value<<" ";
	ldr(root->left);
	ldr(root->right);
}

int main()
{
node*root=construct();
traverse(root);
ldr(root);
}
//Case 1 17 4 1 3 13 5 8 
//Case 2 31 20 15 5 11 9 2 
//case 3 100 100 100 
//Case 4 1000000 1000000 1000000 
