//http://www.geeksforgeeks.org/how-to-sort-a-linked-list-that-is-sorted-alternating-ascending-and-descending-orders/

#include<iostream>
using namespace std;

struct node
{
int value;
node* next;
};

node* create(int value)
{
node* temp = new node;
temp->value=value;
temp->next=NULL;
return temp;
}

void insert(node*head,int value)
{
node* temp = create(value);
temp->next=head->next;
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
	int temp;
	cin>>temp;
	node* head = create(temp);
// Create Linked List. Take in values
	cin>>temp;
	node*h = head;
	while(temp!=-1)
	{
	insert(h,temp);
	h=h->next;
	cin>>temp;
	}
//Split Linked List into odd and even terms
	h=head;
	node*h1 = head->next;
	node *head1 = h1;
	while (true)
	{
		if(h->next!=NULL && h->next->next!=NULL)
		{
		h->next=h1->next;
		h=h->next;
		}
		else
		break;

		if(h1->next!=NULL && h1->next->next!=NULL)
		{
		h1->next=h->next;
		h1=h1->next;
		}
		else
		break;
	}	
	h->next=NULL;
	h1->next=NULL;
// Two lists are head and head1

	node *a;
	h=head1;

	if(h->next==NULL)
	{
	a=h;
	}

	else if (h->next->next==NULL)
	{
		h->next->next=h;
		node*temp = h->next;
		h->next=NULL;
		h=temp;
		a=temp;
	}
	else
	{
		a =h;
		node *b = h->next;
		a->next=NULL;
		while(b!=NULL)
		{
			node*temp=b->next;
			b->next=a;
			a=b;
			b=temp;
		}
			

	}

	h = head;
/*	
	while (true)
	{
		if(h=NULL)
		{
		break;
		}
		if (a==NULL)
		break;

		if( (h->value) < (a->value) )
		h=h->next;

		else
		{
		node * temp = a->next;
		a->next=h->next;
		h->next=a;
		swap(h,a);
				
		a=temp; 
		h=h->next;	
		}
	}
	if(a!=NULL)
	h->next=a;
	else
	h->next=NULL;
*/	
	h= a;
	while(h!=NULL)
	{
		cout<<h->value;
		h=h->next;
	}	
	return 0;
}
