//http://www.geeksforgeeks.org/rearrange-a-given-linked-list-in-place/

#include <iostream>
using namespace std;

struct node
{
int value;
node* next;
};

node* create(int value)
{
node* temp=new node;
temp->value=value;
temp->next=NULL;
return temp;
}

void insert(node*head,int value)
{
node* temp=create(value);
temp->next=head->next;
head->next=temp;
}

int main()
{
	int temp;
	cin>>temp;
	node*head= create(temp);
	node*h = head; 
	
	int count=1;		
	cin>>temp;
	h=head;
	while(temp!=-1)
	{
		count++;
		insert(h,temp);
		h=h->next;
		cin>>temp;
	}

	if(count==2)
	return 0;
	
	node *l=head;
	node *r=head->next;
	node *head1=r;

	while(true)
	{
		if(l->next->next==NULL || l->next==NULL)
		{
			break;
		}
		else
		{
		l->next=r->next;
		l=l->next;
		}
		if(r->next->next==NULL || r->next==NULL)
		{
			break;
		}
		else
		{
		r->next=l->next;
		r=r->next;
		}
	}
	cout<<"Outside while";
	r->next=NULL;
	l->next=NULL;

	h=head1;
	/*
	while(h!=NULL)
	{
		cout<<h->value<<" ";	
		h=h->next;
	}
	*/
		
	if(h->next!=NULL)
	{
	l=h->next;
	h->next=NULL;
		if(l->next!=NULL)
		{
		r=l->next;
		
			while(l!=NULL )
			{
				l->next=h;
				h=l;
				l=r;
				if(r==NULL)
				break;
				r=r->next;	
			}
		}
		else
		{
			l->next=h;
			h=l;
		}		
	}
	l=h;
	while(l!=NULL)
	{
		cout<<l->value;
		l=l->next;
	}

	
	l=head;	
	while(h!=NULL)
	{
		node* temp=h->next;
		h->next=l->next;
		l->next=h;
		l=h->next;
		h=temp;
	}

	l=head;
	while(l!=NULL)
	{
		cout<<l->value<<" ";
		l=l->next;
	}

		
	
	return 0;
}

