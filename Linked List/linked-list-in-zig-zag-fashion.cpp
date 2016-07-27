#include<iostream>
using namespace std;

struct node
{
int value;
node* next;
};

node* create(int value)
{
node* temp= new node;
temp->value=value;
temp->next=NULL;
}

void insert(node *head,int value)
{
node* temp= create(value);
head->next=temp;
}

void swap(node*a,node*b)
{
int temp;
temp=a->value;
a->value=b->value;
b->value=temp;
}

int main()
{

	int n,temp;
	cin>>n;
	int flag=0;

	cin>>temp;
	node* head= create(temp);
	node *head1=head;
	for (int i=1;i<n;i++)
	{
		cin>>temp;
		insert(head1,temp);
		head1=head1->next;
	}

	head1 = head;

	while(head1->next!=NULL)
	{
		if(flag==0)
		{
			if(head1->value>head1->next->value)
			{
				swap(head1,head1->next);
			}
			flag=1;
		}
		else
		{
			if(head1->value<head1->next->value)
			{
				swap(head1,head1->next);
			}
			flag=0;
		}
		head1=head1->next;

	}
	head1=head;
	while(head1!=NULL)
	{
		cout<<head1->value;
		head1=head1->next;
	}
}
