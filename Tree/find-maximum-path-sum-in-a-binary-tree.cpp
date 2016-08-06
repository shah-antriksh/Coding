//http://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct node
{
node *left, *right;
int value;
};

node* create_node(int value)
{
node *temp = new node();
temp->value=value;
temp->left=NULL;
temp->right=NULL;
return temp;
}

void insert(node* root, int value, char ch)
{
node * temp = create_node(value);
if(ch=='l')
root->left = temp;
else
root->right=temp;
}

node * create_tree()
{
/*
Test 1
node * root=create_node(5);
insert(root,3,'l');
insert(root,10,'r');
insert(root->left,-1,'l');
insert(root->left,50,'r');
insert(root->right,-17,'l');
insert(root->right,89,'r');
*/

/*
Test 2
node * root=create_node(10);
insert(root,-50,'l');
insert(root,60,'r');
insert(root->left,30,'l');
insert(root->left,70,'r');
insert(root->right,-40,'l');
insert(root->right,90,'r');
*/

/*
Test 3
node * root=create_node(-10);
insert(root,-50,'l');
insert(root,-60,'r');
*/


/*
Test 4
node * root=create_node(10);
insert(root,2,'l');
insert(root,10,'r');
insert(root->left,20,'l');
insert(root->left,1,'r');
insert(root->right,-25,'r');
insert(root->right->right,3,'l');
insert(root->right->right,4,'r');
return root;
*/

/*
Test 5
*/

node * root=create_node(10);
insert(root,2,'l');
return root;
}

int ans=INT_MIN;
int f_ans(node * root)
{

if(root==NULL)
return 0;

int l=f_ans(root->left);
int r=f_ans(root->right);
int temp_root=temp_root=max(l+r+root->value,root->value);
int ret_ans=max(max(l,r)+root->value,root->value);
ans=max(ans,temp_root);
ans=max(ans,ret_ans);
return ret_ans;
}


int main()
{
node * root = create_tree();
f_ans(root);
cout<<ans;
}
