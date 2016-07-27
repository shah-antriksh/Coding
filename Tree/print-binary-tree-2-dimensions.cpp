//http://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
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

void print_t(int value,int count)
{
	for(int i=0;i<=count*6;i++)
	{	
		cout<<" ";
	}
	cout<<value<<endl;
}

void disp(node*root,int count)
{
	if(root==NULL)
	return;

	disp(root->right,count+1);
	print_t(root->value,count);
	disp(root->left,count+1);
}


int main()
{
node * root = create(1);
root->left = create(2);
root->right = create(3);
root->left->left = create(4);
root->left->right = create(5);
root->right->left = create(6);
root->right->right = create(7);
disp(root,0);
return 0;
}
