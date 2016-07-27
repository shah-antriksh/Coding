#include<iostream>
using namespace std;

struct node
{
int value;
node * next;
};

struct node* XOR (node*a , node*b)
{
	return (struct node*) ((unsigned long) (a) ^ (unsigned long) (b));
}

void insert(node**head, int value)
{

	node * temp = new node;
	temp->value=value;
	temp->next=XOR(*head,temp);

	if((*head)!=NULL)
	{
	
	node* next = XOR((*head)->next,NULL);
	(*head)->next = XOR(temp,next);
	}
	*head=temp;
}

void printList (struct node *head)
{
    struct node *curr = head;
    struct node *prev = NULL;
    struct node *next;
  
    while (curr != NULL)
    {
        // print current node
        cout<< curr->value;
 
        // get address of next node: curr->npx is next^prev, so curr->npx^prev
        // will be next^prev^prev which is next
        next = XOR (prev, curr->next);
 
        // update prev and curr for next iteration
        prev = curr;
        curr = next;
    }
}

int main()
{
	int temp;
	cin>>temp;
	node * head = NULL;
	cin>>temp;

	while(temp!=-1)
	{
		cin>>temp;
		insert(&head,temp);		
	}

	printList(head);

}
