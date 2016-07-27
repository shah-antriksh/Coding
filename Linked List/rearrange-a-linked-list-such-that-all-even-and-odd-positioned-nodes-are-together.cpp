//http://www.geeksforgeeks.org/rearrange-a-linked-list-such-that-all-even-and-odd-positioned-nodes-are-together/

#include<iostream>
using namespace std;

struct node
{
int value;
node* next;
};

node* create(int value)
{
node*temp=new node;
temp->value=value;
temp->next=NULL;
return temp;
}

void insert(node *head,int value)
{
	node*temp=create(value);
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
	int temp,count=1;
	cin>>temp;
	node*head = create(temp);

	node*head1=head;	
	cin>>temp;
	
	while(temp!=-1)
	{
	count++;
	insert(head1,temp);	
	head1=head1->next;
	cin>>temp;
	}

	if(count<=2)
	return 0;


	node *l=head;
	node *r=l->next;
	node *t = r;
	//
	while(true)
	{
		if(r->next==NULL)
		break;
		else
		{
			l->next=r->next;
			l=l->next;
		}

		if(l->next==NULL)
		{
		r->next=NULL;
		break;
		}
		else
		{
			r->next=l->next;
			r=r->next;
		}
	}
	l->next=t;
	//

	head1=head;
	while(head1!=NULL)
	{
	cout<<head1->value;
	head1=head1->next;
	}
}
