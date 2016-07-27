//http://www.geeksforgeeks.org/find-zeroes-to-be-flipped-so-that-number-of-consecutive-1s-is-maximized/

#include<iostream>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int arr[n];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int l=0,r=0,nz=0,len=0,maxlen=0,maxl=0,maxr=0;
	while(r<n && l<n)
	{
		while(nz<=m && r<n)
		{
			if(arr[r]==0)
			{
				r++;
				nz++;
			}
			else
			{
			r++;
			}
			
		}
		len=r-l;
			if(len>maxlen)
			{
			maxlen=len;
			maxl=l;
			maxr=r-1;
			}
		cout<<"l="<<l<<" r="<<r<<endl;
		while(nz>m && l<=r)
		{
			if(arr[l]==0)
			{
			l++;
			nz--;
			}
			else
			{
			l++;
			}
		}
			cout<<"l="<<l<<" r="<<r<<endl;

	}
	for(int i=maxl;i<maxr;i++)
	{
		if(arr[i]==0)
		cout<<i<<" ";
	}
	return 0;
}
