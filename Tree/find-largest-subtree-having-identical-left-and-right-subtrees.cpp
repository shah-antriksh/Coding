//http://www.geeksforgeeks.org/find-largest-subtree-having-identical-left-and-right-subtrees/

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
int mx=0,ans=0;
int f (node * root)
{
	if(root==NULL)
	return 0;
	else
	{
	int l = f(root->left);
	int r = f(root->right);
		if(l==r && l>mx)
		{
			ans=root->value;
			mx=l;
		}
	return l+r+1;
	}
}

int main()
{
node * root = create(50);

root->left = create(10);
root->right = create(60);
root->left->left = create(5);
root->left->right = create(20);
root->right->left = create(70);
root->right->right = create(70);
root->right->left->left = create(65);
root->right->left->right = create(80);
root->right->right->left = create(65);
root->right->right->right = create(80);

f(root);
cout<<ans;
}
