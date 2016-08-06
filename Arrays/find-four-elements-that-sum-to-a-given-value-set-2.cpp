//http://www.geeksforgeeks.org/find-four-elements-that-sum-to-a-given-value-set-2/

#include<bits/stdc++.h>
using namespace std;

struct obj
{
int f;
int s;
int sum;
};

bool check(obj a,obj b)
{

if(a.f==b.f || a.s==b.f || a.f==b.s || a.s==b.s)
	return false;
else
	return true;
}

bool cmp (const obj x, const obj y)
{
	if(x.sum<y.sum)
	return true;
	else
	return false;
}

int main()
{
	int n,i=0,req=0;
	cin>>n>>req;
	int arr[n];
	while(cin>>arr[i++]){}
	
	int xs=0;
	obj xarr[n*n];
	for (i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			xarr[xs].f=arr[i];
			xarr[xs].s=arr[j];
			xarr[xs].sum=arr[i]+arr[j];
			xs++;
		}	
	}
	sort(xarr,xarr+xs,cmp);	
	//for (i=0;i<xs;i++)
	//cout<<xarr[i].sum<<endl;

	i=0;
	int j=xs-1;
	while(i<j)
	{
		if(xarr[i].sum+xarr[j].sum==req && check(xarr[i],xarr[j]) )
		{
			cout<<"yes";
			break;
		}
		else if (xarr[i].sum+xarr[j].sum>req)
		j--;
		else
		i++;
	}
	if(i>=j)
	cout<<"no";
}
//6 91 10 20 30 40 1 2 
