//http://www.geeksforgeeks.org/the-great-tree-list-recursion-problem/

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

void traverse1(node*root,deque<node*>*dq,deque<node*>*dq1)
{
if(root==NULL)
return;

traverse1(root->left,dq,dq1);
dq->push_back(root);
dq1->push_back(root);
//cout<<root->value;
traverse1(root->right,dq,dq1);
}

int main()
{
	node* root= construct();

	deque<node*>dq;	
	deque <node*>dq1;
	traverse1(root,&dq,&dq1);
		
	node * front = dq1.front();
	dq1.pop_front();
	dq1.push_back(front);
	
	while(!dq.empty())
	{
		node*a = dq.front();
		node*b = dq1.front();
		dq.pop_front();
		dq1.pop_front();
		a->right=b;
		b->left=a;
//		cout<<a->value<<b->value<<endl;
	}

	
	node *it = root;
	do
	{
		cout<<it->value<<" ";
		it=it->right;
	}while(it!=root);
}
