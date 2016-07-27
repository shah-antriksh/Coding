//http://www.geeksforgeeks.org/dynamic-programming-set-11-egg-dropping-puzzle/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,f;
	cin>>n>>f;

	int arr[n+1][f+1];
	fill(&arr[0][0],&arr[0][0]+(n+1)*(f+1),0);

	for(int i=1;i<=f;i++)
	{
	arr[1][i]=i;
	}

	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=f;j++)
		{
			int temp=INT_MAX;
			//i= no of eggs
			//j= floor no
			for(int k=1;k<=j;k++)
			{
				temp=min(temp,1+max(arr[i-1][k-1],arr[i][j-k]));
			}
		arr[i][j]=temp;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=f;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	int temp=arr[n][f];
	cout<<endl;
	cout<<f<<" ";
	for(int i=f-1;i>0;i--)
	{
		if(arr[n][i]==temp)
		continue;
		else
		{
			temp=arr[n][i];
			cout<<i<<" ";
		}
	}
	cout<<endl;
	return 0;
}
