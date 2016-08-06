//http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/

//http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/

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
node * root = create(4);
root->left=create(2);
root->right=create(6);
root->left->left=create(1);
root->left->right=create(3);
root->right->left=create(5);
root->right->right=create(8);
return root;
}

int finds(node*root,int val1,int val2)
{
	if(root->left==NULL && root->right==NULL)
	{
		cout<<"Not Present";
		return -1;
	}
	if(val1<root->value && val2<root->value)
		finds(root->left,val1,val2);
	else if (val1>root->value && val2>root->value)
		finds(root->right,val1,val2);
	else
		return root->value;	
}


int main()
{

node*root=construct();
int val1=2,val2=8;
cout<<finds(root,val1,val2);
}

