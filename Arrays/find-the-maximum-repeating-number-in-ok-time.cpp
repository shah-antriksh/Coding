//http://www.geeksforgeeks.org/find-the-maximum-repeating-number-in-ok-time/

#include<bits/stdc++.h>
using namespace std;

int main()
{
int n,k;
cin>>n>>k;
int arr[n];
int i=0;
	while(cin>>arr[i])
	{
	i++;
	}

	for(int i=0;i<n;i++)
	{
		arr[arr[i]%k]+=k;
	}
	int max=0;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[max])
		max=i;
	}
	cout<<arr[max]%k;
}

//14 10 1 2 2 2 0 2 0 2 3 8 0 9 2 3
