//http://www.geeksforgeeks.org/increasing-subsequence-of-length-three-with-maximum-product/

#include<iostream>
using namespace std;
int main()
{

	int n;
	cin>>n;
	int arr[n];
	
	for (int i=0;i<n;i++)	
	cin>>arr[i];
	
	int lb[n],rb[n];

	int temp=arr[0];
	lb[0]=temp;
	
	for (int i=1;i<n;i++)
	{
		if(arr[i-1]>temp)
		{
		temp=arr[i-1];
		}
		if(temp>arr[i])
		{
			int j=i-1;
			while(j>=0 && lb[j]>arr[i])
			{
				j--;
			}		

			if(j<0)
			lb[i]=-1;
			else
			{
				if (arr[i-1]< arr[i] && arr[i-1]>lb[j])
				{
					lb[i]=arr[i-1];
				}
				else
				{
					lb[i]=lb[j];	
				}
			}

		}
		else
		{	
		lb[i]=temp;
		}
	cout<<endl<<i<<":"<<lb[i]<<":"<<temp<<endl;
	}

	temp=arr[n-1];
	rb[n-1] = temp;
	for (int i=n-2;i>=0;i--)
	{
		if(arr[i+1]>temp)
		{
		temp=arr[i+1];
		}

		if(temp<arr[i])
		{
			int j=i+1;
			while(j<n && rb[j]<arr[i])
			{
				j++;
			}		

			if(j>=n)
			rb[i]=-1;
			else
			{
				if (arr[i+1]> arr[i] && arr[i+1]<rb[j])
					{
						rb[i]=arr[i+1];
					}
					else
					{
						rb[i]=rb[j];	
					}
		
			}

		}	
		else
		{
		rb[i]=temp;
		}
	}
	int a=0,b=0,c=0;
	temp=0;
	cout<<endl;
	for (int i=0;i<n;i++)
	cout<<lb[i]<<" ";
	cout<<endl;

	for (int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
	
	for (int i=0;i<n;i++)
	cout<<rb[i]<<" ";
	cout<<endl;

	for (int i=1;i<=n-2;i++)
	{
		if( (lb[i]*arr[i]*rb[i]) > temp )
		{
			if(lb[i]<=arr[i] && arr[i]<=rb[i])
			{
			a=lb[i];
			b=arr[i];
			c=rb[i];
			temp=lb[i]*arr[i]*rb[i];
			}
		cout<<a<<" "<<b<<" "<<c<<endl;	
		}		
	}
	cout<<a<<" "<<b<<" "<<c;
	return 0;
}	
