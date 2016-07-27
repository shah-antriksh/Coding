//http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n],ans[n];
	memset(arr,0,sizeof(arr));
	memset(ans,1,sizeof(ans));
	
	for (int i=0;i<n;i++)
	cin>>arr[i];

	int temp_max=0,fin_ans=0;
	for(int i=0;i<n;i++)
	{
		temp_max=0;
		for(int j=i-1;j>=0;j--)
		{
			if(arr[j]<arr[i])
			{
			temp_max=max(temp_max,ans[j]);
			}
		}
	ans[i]=temp_max+1;
	fin_ans=max(fin_ans,ans[i]);
	}	
	cout<<fin_ans;
}
