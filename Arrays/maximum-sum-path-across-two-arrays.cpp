#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr1[n],arr2[n];
	
	for(int i=0;i<n;i++)
	cin>>arr1[i];

	for(int i=0;i<n;i++)
	cin>>arr2[i];

	int psum1=0,psum2=0,l1=0,l2=0,ans=0;

	while(l1<n && l2<n)
	{
	
		if(arr1[l1]==arr2[l2])
		{
			ans+=max(psum1,psum2);
			ans+=arr1[l1];	
			psum1=psum2=0;
			l1++;l2++;
		}
		else if(arr1[l1]<arr2[l2])
		{
			psum1+=arr1[l1];
			l1++;
		}
		else
		{
			psum2+=arr2[l2];
			l2++;
		}

	}
	while(l1<n)
	{
	psum1+=arr1[l1];
	l1++;
	}	
	while(l2<n)
	{
	psum2+=arr2[l2];
	l2++;
	}
	ans+=max(psum1,psum2);
	cout<<ans;
	return 0;
}
