//http://www.geeksforgeeks.org/create-doubly-linked-list-ternary-ree/

#include<iostream>
using namespace std;

struct tnode
{
int value;
tnode* l;
tnode* m;
tnode* r;
};

struct node
{
int value;
node* l;
node* r;
};

tnode* create_t(int value)
{
tnode* temp = new tnode;
temp->value = value;

temp->l = NULL;
temp->m = NULL;
temp->r = NULL;

return temp;
}

node *create_n(int value)
{
node* temp = new node;
temp->value=value;
temp->l= NULL;
temp->r = NULL;
return temp;
}

void insert(node* head, int value)
{
//cout<<head->value<<endl;
node* temp=create_n(value);
temp->r=head->r;
temp->l=head;
head->r=temp;
}

node* nh;

void traverse_tree(tnode* head)
{
	
	if(head == NULL)
	{
	return;
	}

	insert(nh,head->value);
	nh = nh->r;
	traverse_tree(head->l);
	traverse_tree(head->m);
	traverse_tree(head->r);


	

}

int main()
{

tnode* tree_h = create_t(30);

tree_h->l=create_t(5);
tree_h->m=create_t(11);
tree_h->r=create_t(63);

tree_h->l->l=create_t(1);
tree_h->l->m=create_t(4);
tree_h->l->r=create_t(8);

tree_h->m->l=create_t(6);
tree_h->m->m=create_t(7);
tree_h->m->r=create_t(15);

tree_h->r->l=create_t(31);
tree_h->r->m=create_t(55);
tree_h->r->r=create_t(65);
//traverse_tree(tree_h);

node* dbl = new node;
dbl->value=-1;
dbl->l = dbl->r= NULL;
insert(dbl,-1);

nh = dbl;
traverse_tree(tree_h);
while(dbl!=NULL)
{
cout<<dbl->value<<" ";
dbl=dbl->r;
}
}
