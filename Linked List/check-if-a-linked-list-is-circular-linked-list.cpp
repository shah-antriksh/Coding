//http://www.geeksforgeeks.org/check-if-a-linked-list-is-circular-linked-list/

#include<iostream>
#include<list>
using namespace std;

struct node
{
int value;
node *next;
};

node* create(int value)
{
node *temp = new node;
temp->value=value;
temp->next=NULL;
return temp;
}

int main()
{
	int n;
	cin>>n;
	node *list = create(0);
	node *head = list;	
	int temp;

	for (int i=0;i<n;i++)
	{
		cin>>temp;
		list->next=create(temp);
		list=list->next;
	}
	//list->next=head;
	list = head;
	while(list->next!=NULL)
	{
		if (list->next==head)
		{
		cout<<"Yes";
		break;
		}	
	list = list->next;
	}



}
