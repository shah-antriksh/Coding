//http://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/
#include<iostream>

using namespace std;

void push(int sn, int x, int* arr,int *l,int n,int *size)
{
	if(size[sn]==n)
	{
		cout<<"Overflow";
		return;
	}
	else
	{
		arr[l[sn]]=x;
		size[sn]++;
		l[sn]++;
	}
	cout<<"Inserted"<<x<<" at pos"<<l[sn]-1<<" with size ="<<size[sn]<<endl;
}


void pop(int sn, int* arr,int *l,int n,int *size)
{
	if (size[sn]==0)
	{
		cout<<"Underflow";
		return;
	}
	else
	{
	cout<<arr[l[sn]-1];
	l[sn]--;
	size[sn]--;
	}
}

void print(int sn, int* arr,int *l,int n,int *size)
{
int iter=size[sn];
int pos=l[sn]-1;
while(iter>0)
{
	cout<<arr[pos]<<" ";
	pos--;
	iter--;
}
	cout<<endl;
}


int main()
{
	int n=0,k=0;
	cin>>n>>k;
	int arr[n*k]={0};
	int l[k]={0},size[k]={0};

	for (int i=0;i<k;i++)
	{
	l[i]=i*n;
	}

	int choice,p1,p2;
	cin>>choice;
	while (choice!=-1)
	{
		if(choice==0)
		{
			cin>>p1>>p2;
			push(p1,p2,arr,l,n,size);
		}
		if(choice==1)
		{
			cin>>p1;
			pop(p1,arr,l,n,size);
		}
		if(choice==2)
		{
			cin>>p1;	
			print(p1,arr,l,n,size);
		}
		cin>>choice;
	}
	return 0;
}

