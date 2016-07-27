//http://www.geeksforgeeks.org/convert-a-given-binary-tree-to-doubly-linked-list-set-4/

#include<iostream>
using namespace std;

struct tree
{
int value;
tree* left;
tree* right;
};

struct node
{
int value;
node* left;
node* right;
};

tree* create_t(int value)
{
tree* temp = new tree;
temp->value=value;
temp->right=NULL;
temp->left=NULL;
return temp;	
}


node *head,*head1;

void insert_t(tree* root, int value)
{
	if(root->left==NULL && value<=root->value) 
		{
		root->left=create_t(value);
		return;
		}

	if (root->right==NULL && value>root->value)
		{
		root->right=create_t(value);
		return;
		}

	if(value <= root->value)
	insert_t(root->left,value);

	else
	insert_t(root->right,value);
}

node* create_n(int value)
{
node* temp = new node;
temp->value=value;
temp->right=NULL;
temp->left=NULL;
return temp;
}

void insert_n(node* head, int value)
{
node *temp = create_n(value);
temp->right=head->right;
head->right=temp;
temp->left=head;
temp->right->left=temp;
}

void traverse(tree *root)
{
	if(root==NULL)
	return;

	traverse(root->left);
	cout<<root->value<<" ";
	insert_n(head,root->value);
	head=head->right;
	traverse(root->right);
}


int main()
{

	int n,temp;
	cin>>n;
	
	cin>>temp;
	tree* root=create_t(temp);
	for(int i=1;i<n;i++)
	{
	cin>>temp;
	insert_t(root,temp);
	}
	head=create_n(-1);
	head1=create_n(-1);
	head->right=head->left=head1;
	head1->right=head1->left=head;
	
	traverse(root);

	head=head1->right->right;
	while(head!=head1)
	{
		cout<<head->value;
		head=head->right;
	}
}
