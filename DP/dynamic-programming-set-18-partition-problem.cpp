//http://www.geeksforgeeks.org/dynamic-programming-set-18-partition-problem/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=0,sum=0;
	cin>>n;
	int mat[n+1][n+1];
	int arr[n+1];
	arr[0]=0;
	for(int i=1;i<n+1;i++)
	{
	cin>>arr[i];
	sum+=arr[i];
	}
	
	if(sum%2!=0)
	{
	cout<<"False";
	return 0;
	}
	else
	{
		int s=sum/2;
		int mat[n+1][s+1];
		fill(&mat[0][0],&mat[0][0]+(n+1)*(s+1),0);
		
		mat[0][0]=1;
		
		for(int i=0;i<=n;i++)
		mat[i][0]=1;
		
		
		for(int i=1;i<=n;i++)
		{
		int val=arr[i];
			for(int j=1;j<=(sum/2);j++)
			{
				if(val<=j)
				{
					if(mat[i-1][j-val]==1)
					mat[i][j]=1;
				}
			
			}
		}
	cout<<mat[n][s];	
	}
	return 0;
}
/*
Input:
2
6 2
*/
