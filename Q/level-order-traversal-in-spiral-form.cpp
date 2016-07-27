//http://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/

#include<iostream>
#include<deque>
using namespace std;

struct tree
{
	int value;
	tree* left;
	tree* right;
};

tree * create(int val)
{
	tree * temp= new tree;
	temp->value=val;
	temp->left=NULL;
	temp->right=NULL;
}

void traverse(tree * root)
{

deque<tree*>dq;
dq.push_front(root);
tree * deli = create(-1);
dq.push_front(deli);	
int i=1;
cout<<root->value<<root->left->value<<root->right->value;
	while(!dq.empty())
	{	
	cout<<"dq size->"<<dq.size()<<endl;
		if(i%2==1)
		{
			tree * temp = dq.front();
			dq.pop_back();
			cout<<temp->value;
			if(temp->value!=-1)
			{
				if(temp->left!=NULL)
				dq.push_back(temp->left);
				if(temp->right!=NULL)
				dq.push_back(temp->left);
			}
			else
			{
				i++;
				dq.push_back(temp);
			}
		}
		else
		{
			tree * temp = dq.front();
			dq.pop_back();
			cout<<temp->value;
			if(temp->value!=-1)
			{
				if(temp->left!=NULL)
				dq.push_back(temp->left);
				if(temp->right!=NULL)
				dq.push_back(temp->left);
			}
			else
			{
				i++;
				dq.push_back(temp);
			}
		}				
	}
}
	

int main()
{

tree* root=create(5);
root->left=create(3);
root->right=create(7);
root->left->left=create(1);
root->left->right=create(4);
root->right->left=create(6);
root->left->right=create(8);

traverse(root);
}


