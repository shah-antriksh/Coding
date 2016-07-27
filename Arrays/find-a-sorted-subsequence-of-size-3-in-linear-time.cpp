//http://www.geeksforgeeks.org/find-a-sorted-subsequence-of-size-3-in-linear-time/

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	
	for (int i=0;i<n;i++)
	cin>>arr[i];

	for(int i=0;i<=n-3;i++)
	{
		if(arr[i]>arr[i+1])
			continue;
		if(arr[i]<arr[i+1] && arr[i+1]>arr[i+2])
		{
			i++;
			continue;
		}
		if(arr[i]<arr[i+1] && arr[i+1]<arr[i+2])
		{
			cout<<arr[i]<<" "<<arr[i+1]<<" "<arr[i+2];
			return  0;
		}

	}
	cout<<"No sequence found";
}
