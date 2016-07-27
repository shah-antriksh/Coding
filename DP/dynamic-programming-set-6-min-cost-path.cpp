//http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int min(int a,int b,int c)
{
	if(a<=b && a<=c)
	{
		return a;
	}
	
	else if(b<=a && b<=c)
	{
		return b;
	}
	if(c<=a && c<=b)
	{
		return c;
	}
}

int main()
{
int m,n;
cin>>m>>n;

int arr[m][n];
for (int i=0;i<m;i++)
{
	for (int j=0;j<n;j++)
	{
		cin>>arr[i][j];
	}
}  

int ans[m+1][n+1];

fill(&ans[0][0],&ans[0][0]+(m+1)*(n+1),INT_MAX);

ans[0][0]=0;



for(int i=1;i<=m;i++)
{
	for(int j=1;j<=n;j++)
	{
		ans[i][j]=min(ans[i][j-1],ans[i-1][j],ans[i-1][j-1])+arr[i-1][j-1];
	}

}

for (int i=0;i<=m;i++)
{
	for (int j=0;j<=n;j++)
	{
		cout<<ans[i][j]<<" ";
	}
	cout<<endl;
}  


cout<<endl<<"Ans->";
cout<<ans[m+1][n+1];

return 0;
}
