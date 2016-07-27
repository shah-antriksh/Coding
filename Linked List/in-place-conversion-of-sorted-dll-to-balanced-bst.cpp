//http://www.geeksforgeeks.org/in-place-conversion-of-sorted-dll-to-balanced-bst/

#include<iostream>
using namespace std;

struct node
{
	int value;
	node* left;
	node* right;
};

node* create(int value)
{
	node* temp=new node;
	temp->value=value;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void insert(node* head,int value)
{
	node* temp=create(value);
	head->right=temp;
	temp->left=head;
}

node* mid_r(node*head)
{
node * h =head;
node * h1 = head;
	while(h1->right!=NULL && h1->right->right!=NULL)
	{
		h=h->right;
		h1=h1->right->right;
	}	
	if(h1->right!=NULL)
	h=h->right;

return h;
}

node* mid_l(node*head)
{
node *h =head;
node *h1 = head;
	while(h1->left!=NULL && h1->left->left!=NULL)
	{
		h=h->left;
		h1=h1->left->left;
	}	
	if(h1->left!=NULL)
	h=h->left;
return h;
}

void build(node *h)
{
	
	node *lmid=mid_l(h);
	node *rmid=mid_r(h);
	cout<<endl<<"h="<<h->value;
	cout<<endl<<"lmid="<<lmid->value;
	cout<<endl<<"rmid="<<rmid->value<<endl;	
	if(lmid==h || rmid==h)
	{
		
		if(h->left!=NULL)
		{
			h->left->left=NULL;
			h->left->right=NULL;
		}

		
		if(h->right!=NULL)
		{
		h->right->right=NULL;
		h->right->left=NULL;
		}
		return;
	}

	else
	{
		if(h->left!=NULL)
		{
		h->left->right=NULL;
		h->left=NULL;
		}		

		if(h->right->left!=NULL)
		{
		h->right->left=NULL;
		h->right=NULL;
		}
	
		h->left=lmid;
		h->right=rmid;
		build(lmid);
		build(rmid);
	}
}

void traverse(node*h)
{
	if(h==NULL || h==NULL)
	{		
		return;
	}	
	cout<<h->value<<" ";
	traverse(h->left);
	traverse(h->right);
}

int main()
{
	int temp;
	cin>>temp;
	node*head=create(temp);
	node*h,*h1;

	h=head;
	cin>>temp;
	while(temp!=-1)
	{
		insert(h,temp);
		h=h->right;		
		cin>>temp;
	}
	
	node * root = mid_r(head);
	build(root);
	//cout<<root->value;
	traverse(root);
			
	return 0;
}
