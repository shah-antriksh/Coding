//http://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/

/*
Test Cases:
1. Node has no children
2. Node has only left child
3. Node has only right child
4. Node has both left and right
*/

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

void mirror(node* root)
{
deque<node*>dq;
dq.push_back(root);

	while(!dq.empty())
	{
		node * temp = dq.front();
		dq.pop_front();
		
		if(temp->left==NULL && temp->right==NULL)
		{
			continue;
		}
		else if (temp->right==NULL)
		{
			temp->left=temp->right;
			temp->right=NULL;
			dq.push_back(temp->left);

		}
		else if (temp->left==NULL) 
		{
			temp->right=temp->left;
			temp->left=NULL;
			dq.push_back(temp->right);

		}
		else
		{
			node * temp1;
			temp1=temp->left;
			temp->left=temp->right;
			temp->right=temp1;
			dq.push_back(temp->left);
			dq.push_back(temp->right);
		}

	}


}

void ldr(node * root)
{
	if(root==NULL)
	return;

	ldr(root->left);
	cout<<root->value;
	ldr(root->right);
}

int main()
{
node* root = construct();
ldr(root);
cout<<endl;
mirror(root);
ldr(root);
return 0;
}
42513
31524
