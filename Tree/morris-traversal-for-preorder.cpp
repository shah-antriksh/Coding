//http://www.geeksforgeeks.org/morris-traversal-for-preorder/

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
	if(root->left==NULL)
	return root;
	else
	{
//		cout<<"Finding for"<<root->value<<endl;
		node*temp=root->left;
		while(temp->right!=root && (temp->right!=NULL || temp->left!=NULL))
		{	
			if(temp->right!=NULL)
			temp=temp->right;
			else if (temp->left!=NULL)
			temp=temp->left;
		}
//	cout<<"Sucessor is"<<temp->value<<endl;
	return temp;
	}
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
//			cout<<endl<<root->value<<" "<<root->left->value<<" "<<root->right->value<<" "<<endl;
			node*temp=sucessor(root);
//<<"Successor is "<<temp->value<<endl;
			if(temp->right==NULL)
			{
				cout<<root->value;
				temp->right=root;
				root=root->left;
			}
			else
			{
				temp->right=NULL;
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
