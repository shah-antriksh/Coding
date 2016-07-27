//http://www.geeksforgeeks.org/stock-buy-sell/

#include<iostream>
using namespace std;

int main()
{

	int n;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++)
	cin>>arr[i];
	/*
	int maxval[n],minval[n],maxi[n],mini[n];
	maxval[n-1]=-1;
	maxi[n-1]=n-1;

	for (int i=n-1;i<=0;i--)
	{
	
	
	}
	*/

	int profit=0;
	int buy=arr[0];
	int max=0,maxi=0;
	for (int i=1;i<n;i++)
	{
		while (arr[i]<buy && i<n)
		{
			buy=arr[i];
			i++;
		}		
		while(arr[i]>buy && i<n)
		{
			if(arr[i]>max)
			{
			max=arr[i];
			maxi=i;
			}
			i++;
		}
		profit+=max-buy;
		if (max-buy>0)
		{
		cout<<"buy"<<buy<<"sell"<<max<<endl	;	
		i=maxi+1;
		buy=arr[i];
		max=0;
		}
	}
}
