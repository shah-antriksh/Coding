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

void swap(node *a,node *b)
{
int temp;
temp=a->value;
a->value=b->value;
b->value=temp;
}

int main()
{
	int n,m,temp;
	cin>>n>>m;
	
	node* head1, *head2;
	node * list1;
	//Input------------------------------------
	cin>>temp;
	head1 = create (temp);
	list1=head1;
	for (int i=1;i<n;i++)
	{
		cin>>temp;
		list1->next=create(temp);
		list1=list1->next;
	}
	
	cin>>temp;
	head2 = create (temp);
	node*list2=head2;
	for (int i=1;i<m;i++)
	{
		cin>>temp;
		list2->next=create(temp);
		list2=list2->next;
	}
	//Input Over------------------------------------

	//Work------------------------------------------	
	list1=head1;
	list2=head2;
	
	while(list1!=NULL)
	{
		if( (list1->value) > (list2->value) )
		{
			swap(list1,list2);
			node* l2 = list2;
			if (list2->next)
			{
				node* l2next;
				while(l2->next!=NULL)
				{
					l2next = l2->next;
					if(l2->value>l2next->value)
					{
						swap(l2,l2next);
						
					}
					l2=l2->next;
				}
			}
		}
		else
		{
			list1=list1->next;
		}
	
	}

	//Output------------------------------------
	cout<<endl<<"****************************"<<endl;
	list1=head1;
	while(list1!=NULL)
	{
	cout<<list1->value<<" ";
	list1=list1->next;
	}	

	cout<<endl;

	list2=head2;
	while(list2!=NULL)
	{
	cout<<list2->value<<" ";
	list2=list2->next;
	}	

	cout<<endl<<"****************************"<<endl;
	return 0;
}
