//http://www.geeksforgeeks.org/full-and-complete-binary-tree-from-given-preorder-and-postorder-traversals/

#include<bits/stdc++.h>
using namespace std;
struct node
{
node *left,*right;
int value;
};

node* create(int value)
{
node* temp = new node();
temp->value=value;
temp->left = NULL;
temp->right = NULL;
return temp;
}

int find(int value,int*post)
{
	for(int i=0;i<=6;i++)
	{
		if(value==post[i])
		{
			return post[i-1];
		}
	}
}

int find_index(int value,int*pre)
{
	for(int i=0;i<=6;i++)
	{
		if(value==pre[i])
		{
			return i;
		}
	}
}

node* build(int i,int j,int *pre,int *post)
{
cout<<i<<j<<endl;
node*root = create(pre[i]);


if(i==j)
return root;

int rchild=find(pre[i],post);
//cout<<rchild;
int rindex=find_index(rchild,pre);
//cout<<rindex;
root->left=build(i+1,rindex-1,pre,post);
root->right=build(rindex,j,pre,post);
return root;
}

void traverse(node*root)
{
if(root==NULL)
return;

traverse(root->left);
cout<<root->value<<" ";
traverse(root->right);
}


int main()
{
int pre[]={1,2,4,5,3,6,7};
int post[]={4,5,2,6,7,3,1};

node*root=build(0,6,pre,post);
traverse(root);
}06
13
22
33
46
55
66
4 2 5 1 6 3 7 
