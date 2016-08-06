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

node* sucessor(node*root)
{
	node*temp=root;
	root=root->left;

	while(root->right!=NULL && root->right!=temp)
	root=root->right;

	return root;
}

void traverse(node*root)
{
	while(root!=NULL)
	{
		if(root->left==NULL)
		{
			cout<<root->value;
			root=root->right;

		}
		else
		{
			node*temp = sucessor(root);
			
			if(temp->right==NULL)
			{
				temp->right=root;
				root=root->left;
			}

			else
			{
				temp->right==NULL;
				cout<<root->value;
				root=root->right;
			}
			
		}

	}
}

int main()
{
node*root = construct();
traverse(root);
}
