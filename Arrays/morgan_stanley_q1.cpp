#include<bits/stdc++.h>
using namespace std;

int min(int a,int b,int c)
{
	if(a<=b && a<=c)
	return a;
	if(b<=a && b<=c)
	return b;
	else 
	return c;
}
int max(int a,int b,int c)
{
	if(a>=b && a>=c)
	return a;
	else if (b>=a && b>=c)
	return b;
	else 
	return c;
}

	int main()
	{
	int n;
	cin>>n;
	int arr[n];
	int i=0;
	while(cin>>arr[i]){i++;}
	int min_prod=0,max_prod=0,ans=0,temp_ans=0;

	for (int i=0;i<n;i++)
	{
		cout<<"i:"<<i;
		int temp_min_prod=min(arr[i],arr[i]*min_prod,arr[i]*max_prod);
		int temp_max_prod=max(arr[i],arr[i]*min_prod,arr[i]*max_prod);
		min_prod=temp_min_prod;
		max_prod=temp_max_prod;
		cout<<" min prod:"<<min_prod<<" max_prod:"<<max_prod;
		temp_ans=max(ans,min_prod,max_prod);
		cout<<"temp_ans"<<temp_ans<<endl;
		ans=max(ans,temp_ans,INT_MIN);
	}

	cout<<ans;
}

/*5 -2 -3 0 -2 -40
6400
6400
i:0 min prod:-2 max_prod:0temp_ans0
i:1 min prod:-3 max_prod:6temp_ans6
i:2 min prod:0 max_prod:0temp_ans6
i:3 min prod:-2 max_prod:0temp_ans6
i:4 min prod:-40 max_prod:80temp_ans80
80
*/

/*
5 -1 -3 -10 0 60
i:0 min prod:-1 max_prod:0temp_ans0
i:1 min prod:-3 max_prod:3temp_ans3
i:2 min prod:-30 max_prod:30temp_ans30
i:3 min prod:0 max_prod:0temp_ans30
i:4 min prod:0 max_prod:60temp_ans60
60*/

/*
5 6 -3 -10 0 2
i:0 min prod:0 max_prod:6temp_ans6
i:1 min prod:-18 max_prod:0temp_ans6
i:2 min prod:-10 max_prod:180temp_ans180
i:3 min prod:0 max_prod:0temp_ans180
i:4 min prod:0 max_prod:2temp_ans180
180
*/
