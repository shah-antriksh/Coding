//http://www.geeksforgeeks.org/given-a-binary-tree-print-out-all-of-its-root-to-leaf-paths-one-per-line/
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

node * construct()
{
node * root = create(1);
root->left=create(2);
root->right=create(3);
root->left->left=create(4);
root->left->right=create(5);
return root;
}

void finds(node*root,string s)
{
	if(root->left==NULL && root->right==NULL)
	{
		s.append(to_string(root->value));
		cout<<s<<endl;
		return;
	}

	s.append(to_string(root->value));
	finds(root->left,s);
	finds(root->right,s);	
}

int main()
{
node * root = construct();
string s = "";
finds(root,s);
}124
125
13

