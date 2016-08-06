//http://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/

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

void traverse(node*root)
{
stack<node*>s;
node*temp = root;
	do
	{
		while(temp->left!=NULL)
		{
			s.push(temp->left);
			temp=temp->left;
		}
		
		if(!s.empty())
		{
			temp=s.top():
			s.pop();
			cout<<temp->value;
			temp=temp->right;
		}
	}while(!s.empty() || temp!=NULL);
}

int main()
{
node*root = construct();
traverse(root);
return 0;
}
