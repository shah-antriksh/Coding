//http://www.geeksforgeeks.org/minimum-length-subarray-sum-greater-given-value/

#include<iostream>
using namespace std;

int main()
{
	int n,req_sum;
	cin>>n>>req_sum;
	int arr[n];
	
	for (int i=0;i<n;i++)
	cin>>arr[i];

	int l=0,r=0,ansl=0,ansr=0,sum=0,len=n;

	while(l<n && r<n)
	{
		while(sum<=req_sum)
		{
		sum+=arr[r];
		r++;
		}
		if((r-l+1)<len)
		{
		len=r-l+1;
		ansl=l;
		ansr=r-1;
		}
		sum-=arr[l];
		l++;
	}

	for(int i=ansl;i<=ansr;i++)
	{
		cout<<arr[i]<<" ";
	}

	
	
}
