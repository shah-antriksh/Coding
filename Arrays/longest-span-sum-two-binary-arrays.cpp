#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n=0;
	cin>>n;
	int a1[n],a2[n];
	int index_tb[2*n+1],di=0,p1=0,p2=0,ci=0,ans=0;
	memset(index_tb,-1,sizeof(index_tb));

	for(int i=0;i<n;i++)
	cin>>a1[i];

	for(int i=0;i<n;i++)
	cin>>a2[i];

	for(int i=0;i<n;i++)
	{
		p1+=a1[i];p2+=a2[i];
		ci=p1-p2;
		di=n+ci;
		if(di==0)
		{
			ans++;
		}
		
		else if (index_tb[di]==-1)
		index_tb[di]=i;
		
		else
		{
			int temp_len= i-index_tb[di];
			ans=max(temp_len,ans);
		} 
	}
	cout<<ans;
	return 0;
}
