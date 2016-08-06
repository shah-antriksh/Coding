//http://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/

#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
cin>>n;
int arr[n],minv[n],maxv[n];
int element;

int i=0;
while(cin>>arr[i]){i++;}

minv[0]=arr[0];
for (i=1;i<n;i++)
{
	minv[i]=min(arr[i],minv[i-1]);
}


maxv[n-1]=arr[n-1];
for (i=n-2;i>=0;i--)
{
	maxv[i]=max(arr[i],maxv[i+1]);
}
i=0;
int j=0;
int ans=0;
while(i<n && j<n)
{
	if(maxv[j]>minv[i])
	{
		ans=max(ans,j-i);
		j++;
	}
	else
		i++;
	
}
cout<<ans;
}

//10 9 2 3 4 5 6 7 8 18 0
//6 1 2 3 4 5 6
//3 3 2 1
