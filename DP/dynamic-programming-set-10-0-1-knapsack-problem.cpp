//http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/

#include<iostream>
using namespace std;

int main()
{
	int n,w;
	cin>>n>>w;

	int value[n+1]={0};
	int weight[n+1]={0};
	int arr[n+1][w+1];

	fill(&arr[0][0],&arr[0][0]+(n+1)*(w+1),0);

	for(int i=1;i<=n;i++)
	{
		cin>>value[i];
		cin>>weight[i];
	}

	for(int i=0;i<=n;i++)
	{	
		cout<<value[i]<<weight[i]<<" ";
	}
	cout<<endl;

	
	for (int i=1;i<=n;i++)
	{
		int val=value[i];
		int wgt=weight[i];
		for(int j=1;j<=w;j++)
		{
			if(wgt<=j)
			{
				arr[i][j]=max(val+arr[i-1][j-wgt],arr[i-1][j]);	
			}
			else
			{
				arr[i][j]=arr[i-1][j];
			}		
		}

	}
		
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			cout<<arr[i][j]<<" ";
		}		
		cout<<endl;
	}
	cout<<endl<<endl<<"Answer="<<arr[n][w];
}
