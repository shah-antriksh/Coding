//http://www.geeksforgeeks.org/write-a-c-program-to-delete-a-tree/

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

void del(node* root)
{
if(root->left==NULL && root->right==NULL)
{
cout<<root->value<<" ";
delete(root);
return ;
}

del(root->left);
del(root->right);
cout<<root->value<<" ";
delete(root);

return ;
}

int main()
{
node*root = construct();
del(root);
}
