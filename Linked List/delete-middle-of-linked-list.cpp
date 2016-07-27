//http://www.geeksforgeeks.org/delete-middle-of-linked-list/

#include<iostream>
using namespace std;

struct node
{
int value;
node* next;
};

node* create(int value)
{
node *temp = new node;
temp->value = value;
temp->next=NULL;

return temp;
}

int main()
{
	int n,temp;
	cin>>n;
	
	cin>>temp;
	node* head = create(temp);
	node* list=head;

	for (int i=1;i<n;i++)
	{
		cin>>temp;
		list->next=create(temp);
		list=list->next;					
	} 

	list = head;
	node* list1=head;

	while(list1!=NULL)
	{

		list1=list1->next->next;		
		list=list->next;
		if (list1->next ==NULL || list1->next->next == NULL)
		break;
	}
	list->next=list->next->next;
	
	/*
	int count=0;
	while(list->next!=NULL)
	{
		count++;
		list=list->next;
	}

	count/=2;
	
	list = head;
	for (int i=0;i<count;i++)
	{
		list=list->next;	
	}	
	list->next=list->next->next;
	*/
	list=head;
	while(list	!=NULL)
	{
		cout<<list->value;
		list=list->next;
	}

}
