//http://www.geeksforgeeks.org/construct-a-special-tree-from-given-preorder-traversal/

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

node*build(int*pre,char*z,int *i)
{
	if(*i>=5)
	return NULL;

	node*root=create(pre[*i]);
	if(z[*i]=='L')
	{
		(*i)++;
		return root;
	}
	(*i)++;
	root->left=build(pre,z,i);	
	root->right=build(pre,z,i);

	return root;
}

void traverse(node*root)
{
	if(root==NULL)
	return;

	traverse(root->left);
	cout<<root->value;
	traverse(root->right);
}

int main()
{
int pre[] = {10, 30, 20, 5, 15};
char preLN[] = {'N', 'N', 'L', 'L', 'L'};
int * i = new int;
*i=0;
node*root=build(pre,preLN,i);
traverse(root);
}20 30 5 10 15
