//http://www.geeksforgeeks.org/point-arbit-pointer-greatest-value-right-side-node-linked-list/

#include<iostream>
#include<stack>
using namespace std;

struct node
{
int value;
node *right;
node *arbit;
};

node* create(int value)
{
node *temp = new node;
temp->value=value;
temp->right=NULL;
temp->arbit=NULL;
return temp;
}

void insert(node *head,int value)
{
node *temp=create(value);
head->right=temp;
}

int main()
{
	int n,temp;
	cin>>n;
	cin>>temp;	
	
	node*head=create(temp);

	node *head1=head;		
	for (int i=1;i<n;i++)
	{
		cin>>temp;
		insert(head1,temp);
		head1=head1->right;
	}
	stack <int> st;
	head1=head;	
	while(head1!=NULL)
	{
		cout<<head1->value;
		st.push(head1->value);
		head1=head1->right;
	}

	cout<<endl;
	node* nhead=create(st.top());
	st.pop();
	node*nhead1=nhead;
	while(st.size()!=0)
	{
	insert(nhead1,st.top());
	st.pop();
	nhead1=nhead1->right;
	}
	
	stack <int> st,st1;
	int mx=nhead->value;

	st.push(nhead->value);
	st1.push(-1);
	head1=nhead->right;
		
	while(head1!=NULL)
	{
		st.push(head1->value);
		st1.push(max(head1->value,mx)));
		head1=head1->right;
	}
	
	
	
	
}
