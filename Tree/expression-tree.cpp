//http://www.geeksforgeeks.org/expression-tree/

#include<bits/stdc++.h>
using namespace std;

struct node
{
int value;
char op;
node* left,*right;
};

node* create_operand(int value)
{
node *temp= new node();
temp->value=value;
temp->op='.';
temp->left=NULL;
temp->right=NULL;
return temp;
}

node* create_operator(char value)
{
node *temp= new node();
temp->op=value;
temp->value=0;
temp->left=NULL;
temp->right=NULL;
return temp;
}

int ans(int l,int r,char op)
{
if(op=='+')
return (l+r);

else if (op=='-')
return (l-r);

else if (op=='*')
return (l*r);

else
return (l/r);

}

int solve(node * root)
{
if(root->left==NULL || root->right==NULL)
return root->value;

int l=solve(root->left);
int r = solve(root->right);

int temp = ans(l,r,root->op);
return temp;
}


int main()
{
node* root= create_operator('+');
root->left=create_operator('*');
root->right=create_operator('-');
root->left->left=create_operand(5);
root->left->right=create_operand(4);
root->right->left=create_operand(100);
root->right->right=create_operator('/');
root->right->right->left=create_operand(20);
root->right->right->right=create_operand(2);
cout<<solve(root);

}
