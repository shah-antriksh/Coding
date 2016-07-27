//http://www.geeksforgeeks.org/dynamic-programming-set-16-floyd-warshall-algorithm/

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n+1][n+1];
	fill(&arr[0][0],&arr[0][0]+(n+1)*(n+1),0);

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>arr[i][j];
		}
	}

	for(int i=1;i<=n;i++)
	{		
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(k==i)
				continue;
				else
				arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
			}
		}
	}

	for(int i=1;i<=n;i++)
	{		
		for(int j=1;j<=n;j++)
		{
			if(arr[i][j]==99999)
			cout<<-1<<" ";
			else
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
