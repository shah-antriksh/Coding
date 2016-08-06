//http://www.geeksforgeeks.org/stock-buy-sell/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int element=0;
	int max_so_far=0;
	int profit=0;
	int count=1;
	int sum=0;	
	cin>>element;
	max_so_far=element;
	sum=element;
	int buy=element;	
	while(cin>>element)
	{
		if(element>=max_so_far)
		{
			count++;
			max_so_far=element;
			sum+=element;
		}
		else if (element<max_so_far && count>1)
		{
			profit+=sum-buy-buy;
			cout<<"sell "<<sum<<" buy "<<buy;
			max_so_far=element;
			count=1;
			sum=element;	
			buy=element;		
		}
		else
		{
			max_so_far=element;
			count=1;
			sum=element;
			buy=element;
		}	
	}
	element=INT_MIN;
	if (element<max_so_far && count>1)
	{
		profit+=sum-buy-buy;
		cout<<"sell "<<sum<<" buy "<<buy;
	}
	cout<<endl<<profit;
}

//1 10 5 9 4 2
//5 4 3 2 1
//1 2 3 4 5
//100 180 260 310 40 535 695
