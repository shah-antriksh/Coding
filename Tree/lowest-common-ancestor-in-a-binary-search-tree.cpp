//http://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/

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
node * root = create(4);
root->left=create(2);
root->right=create(6);
root->left->left=create(1);
root->left->right=create(3);
root->right->left=create(5);
root->right->right=create(8);
return root;
}

string finds(node*root,int val)
{
	if(root->left==NULL && root->right==NULL && root->value!=val)
	return "";
	if(root->value==val)
	{
		return (to_string(val)+",");
	}	
	else if (root->value>val)
	{
		string temp=finds(root->left,val);
		if(temp.compare("")==0)
		return "";
		else
		{
		temp.append(to_string(root->value)+",");
		return temp;
		}
	}
	else
	{
		string temp=finds(root->right,val);
		if(temp.compare("")==0)
		return "";
		else
		{
		temp.append(to_string(root->value)+",");
		return temp;
		}
	}
}

void match(string s1,string s2)
{
cout<<s1<<" "<<s2<<endl;
map<string,bool>mp;
string key="";
	for(int i=0;i<s1.length();i++)
	{
//		cout<<i<<" "<<key<<endl;
		if(s1[i]==',')
		{
		mp[key]=true;
		key="";
		}
		else
		key+=s1[i];
	}
key="";
	for(int i=0;i<s2.length();i++)
	{
		if(s2[i]==',')
		{
			if(mp[key]==true)
			{
				cout<<key;
				return;
			}
			else
			{
				key="";
			}
		}
		else
		key+=s2[i];
	}
	
}

int main()
{

node*root=construct();
int val1=6,val2=8;
string s1 = finds(root,val1);
string s2 = finds(root,val2);
match(s1,s2);
}

