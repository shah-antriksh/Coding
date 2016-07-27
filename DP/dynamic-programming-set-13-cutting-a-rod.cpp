//http://www.geeksforgeeks.org/dynamic-programming-set-13-cutting-a-rod/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
cin>>n;
int profit[n+1];
for(int i=1;i<=n;i++)
cin>>profit[i];
int arr[n+1][n+1];
fill(&arr[0][0],&arr[0][0]+(n+1)*(n+1),0);
memset(&profit,sizeof(profit),0);


for(int i=1;i<=n;i++)
{

	for(int j=1;j<=n;j++)
	{

		if(i<=j)
		{
			arr[i][j]= max(arr[i-1][j],profit[i]+arr[i][j-i]);
		}
		else
		{
			arr[i][j]=arr[i-1][j];
		}
	}
}
cout<<arr[n][n];


}
