//http://www.geeksforgeeks.org/find-the-first-missing-number/

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	
	for (int i=0;i<n;i++)
	cin>>arr[i];

	int l=0,r=n,i;
	
	while(l<=r)
	{
		if(l==r || r-l==1)
		{
		break;
		}

		i=(l+r)/2;

		if(arr[i]>i)
		r=i;

		else
		l=i;

	}
	if(arr[l]!=l)
	cout<<l;
	else
	cout<<r;
	
}
