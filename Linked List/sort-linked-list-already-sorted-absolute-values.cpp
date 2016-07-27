//http://www.geeksforgeeks.org/sort-linked-list-already-sorted-absolute-values/
#include<iostream>
#include<climits>
using namespace std;

struct node
{
int value;
node* left;
node* right;
};

node* create (int value)
{
node * temp = new node;
temp->value= value;
temp->left = NULL;
temp->right=NULL;
return temp;
}

void insert(node *head,int value)
{
node *temp=create(value);

temp->right=head->right;
temp->left=head;
head->right=temp;

if(temp->right!=NULL)
temp->right->left=temp;
else
temp->right=head;

if(head->left==NULL)
head->left=temp;

}

void swap(node *a, node *b)
{
int temp;
temp=a->value;
a->value=b->value;
b->value=temp;
}

int main()
{
	int n,temp;
	node *head,*th,*l;
	head=create(INT_MIN);
	insert(head,INT_MIN);

	cin>>n;

	th=head;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		insert(th,temp);
		th=th->right;
	}

	th=head->right;
	while(th!=head)
	{
		l=th;
		cout<<"value-"<<l->value<<endl;
		if(l->value>l->left->value)
		th=th->right;
		else
		{
			while( (l->value) < (l->left->value) )
			{
				swap(l,l->left);
				l=l->left;
			}
		th=th->right;
		}
		
	}
	

	th=head->right->right;
	while (th!=head)
	{
	cout<<th->value<<" ";
	th=th->right;
	}
}
