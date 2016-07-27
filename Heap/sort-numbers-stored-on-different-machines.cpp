//http://www.geeksforgeeks.org/sort-numbers-stored-on-different-machines/

#include<iostream>
#include<list>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

struct node
{
int value;
int q;
node* next;
};

struct cmp
{
	bool operator()(node** a,node **b)
	{
		if((*a)->value>=(*b)->value)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

node* create_node(int value,int q)
{
node* temp= new node;
temp->value=value;
temp->q=q;
temp->next=NULL;
return temp;
}

void insert(node *head,int value,int q)
{
	while(head->next!=NULL)
	{
		head=head->next;
	}
	head->next=create_node(value,q);
}

int main()
{	
	node*li[3];
	li[0]=create_node(1,0);
	li[1]=create_node(1,1);
	li[2]=create_node(1,2);

	insert(li[0],1,1);
	insert(li[0],17,1);
	insert(li[0],99,1);

	insert(li[1],2,2);
	insert(li[1],3,2);
	insert(li[1],4,2);

	insert(li[2],13,3);
	insert(li[2],14,3);
	insert(li[2],19,3);

	insert(li[0],INT_MAX,1);
	insert(li[1],INT_MAX,2);
	insert(li[2],INT_MAX,3);

	vector<node**> vec;
	vec.push_back(&li[0]);
	vec.push_back(&li[1]);
	vec.push_back(&li[2]);

	make_heap(vec.begin(),vec.end(),cmp());
	while(vec.size()>0)
	{
		pop_heap(vec.begin(),vec.end(),cmp());
		node** temp=vec.back();
		if((*temp)->value==INT_MAX)
		{
			int q = (*temp)->q;
			vec.pop_back();
			push_heap(vec.begin(),vec.end(),cmp());
		}
		else
		{
		cout<<(*temp)->value<<" "<<(*temp)->q;
		cout<<endl;
		*temp=(*temp)->next;
		push_heap(vec.begin(),vec.end(),cmp());		
		}
	}		
}
