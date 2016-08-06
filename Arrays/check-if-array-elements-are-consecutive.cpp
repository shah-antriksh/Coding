//http://www.geeksforgeeks.org/check-if-array-elements-are-consecutive/

#include<bits/stdc++.h>
using namespace std;

int main()
{

int arr[]={88,89,90,91,92,94,93};
int n = sizeof(arr)/sizeof(int);
int maxv=INT_MIN;
int minv=INT_MAX;
for (int i=0;i<n;i++)
{
	maxv=max(arr[i],maxv);
	minv=min(arr[i],minv);
}
for (int i=0;i<n;i++)
{
	if(arr[arr[i]-minv]>=0)
	{
	cout<<arr[arr[i]-minv]<<endl;
	arr[arr[i]-minv]=-1;
	}
	else
	{
	maxv=INT_MAX;
	}
}
if(maxv-minv+1 == n)
cout<<"yes";
else
cout<<"no";

}
