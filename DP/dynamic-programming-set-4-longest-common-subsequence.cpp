//http://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence/

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int main()
{
	string a,b;
	cin>>a>>b;
	int al,bl;
	al=a.length();
	bl=b.length();
	cout<<al<<bl;
	int arr[al+1][bl+1];
	memset(arr,0,sizeof(arr[0][0]*al*bl));

	for(int i=0;i<=al;i++)
	{
		for(int j=0;j<=bl;j++)
		{
			if(i==0||j==0)
			{
			arr[i][j]=0;
			}
			else if(a[i-1]==b[j-1])
			{
				arr[i][j]=1+arr[i-1][j-1];
			}
			else
			{
				arr[i][j]=max(arr[i][j-1],arr[i-1][j]);
			}

		}
	}
	for (int i=0;i<=al;i++)
	{	
		for (int j=0;j<=bl;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<arr[al][bl];
}
