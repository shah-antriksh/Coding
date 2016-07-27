//http://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-complete-tree-or-not/

#include<iostream>
#include<queue>
using namespace std;

struct tree
{
int value;
tree *left;
tree * right;
};

tree* create(int value)
{
tree *temp = new tree;
temp->value=value;
temp->right=NULL;
temp->left=NULL;
}


int main()
{

	tree * root = create(5);
	root->left=create(2);
	root->right=create(7);
	root->left->left=create(1);
	root->left->right=create(3);
	root->right->left=create(6);
	root->right->right=create(8);

/*
	tree * root = create(1);
	root->left=create(2);
	root->left->left=create(4);
*/

	queue <tree*> q;
	q.push(root);
	tree *temp;
	bool flag=false;

	while(!q.empty())
	{
		temp=q.front();
		q.pop();

		if(temp->left==NULL)
		{
			flag=true;
		}


		if(temp->right==NULL)
		{
			flag=true;
		}

		if(temp->left!=NULL)
		{
			if(flag==false)
			{
				q.push(temp->left);
			}
			else
			{
				cout<<"No";
				return 0;
				}		
		}

		if(temp->right!=NULL)
		{
			if(flag==false)
			{
				q.push(temp->right);
			}
			else
			{
				cout<<"No";
				return 0;
			}		
		}
	}
	cout<<"YES";			

}
