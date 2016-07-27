//http://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/

#include<iostream>
using namespace std;

struct node
{
int value;
node *left;
node* right;
};

node* create(int value)
{
node * temp = new node;
temp->value=value;
temp->left=NULL;
temp->right=NULL;
return temp;
}

int posi;

int find(int val,int l,int r,int *in)
{
	int i=l;
	for (;i<r;i++)
	{
		if(in[i]==val)
		break;
	}	
	return i;
}
int counter=15;
node* build (int l, int r, int* in, int *post)
{
cout<<l<<r<<endl;
	if(l>r || posi<0)
	{
	return NULL;
	}
	if(l-r==0)
	{
		posi--;
		node * temp= create(in[l]);
		return temp;
	}	
	else
	{
		
		node *root = create(post[posi]);
		posi--;
		int index= find(root->value,l,r,in);
		cout<<root->value<<l<<index<<r<<endl;
		if(index<=r)
		{
			cout<<"calling right"<<index+1<<r<<endl;
			root->right=build(index+1,r,in,post);
		}
		if(index>=l)
		{
			cout<<"calling left"<<l<<index-1<<endl;	
			root->left=build(l,index-1,in,post);
		}
	}
}


void preOrder(node* root)
{
if (root==NULL)
return ;

cout<<root->value<<" ";
preOrder(root->left);
preOrder(root->right);
}

int main()
{
	int in[]   = {1,2,3,4,5,6,7};
	int post[] = {1,3,2,5,7,6,4};
	int n = sizeof(in)/sizeof(in[0]);
	posi=n-1;
	node *root = build(0,n-1,in, post);
	cout  << "Preorder of the constructed tree : \n";
	preOrder(root);
}
