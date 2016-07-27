//http://www.geeksforgeeks.org/count-minimum-steps-get-given-desired-array/

#include<iostream>
#include<limits.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n]={0},tarr[n];
	int sum=0,flag=0;
	int tmin=INT_MAX,mini=0;

	for(int i=0;i<n;i++)
	{
		cin>>tarr[i];
		if(tarr[i]==0)
		{
			flag=1;
		}
		if(tarr[i]<tmin)
		{
			tmin=tarr[i];			
			sum+=tarr[i];
		}
	}
	if(flag==1)
	{
		cout<<sum;
	}

	else
	{
	sum=0;
		if(tmin==1)
		{
			for(int i=0;i<n;i++)
			{
			sum+=tarr[i]-arr[i];		
			}
		}
		else
		{
			
			for(int i=0;i<n;i++)
			{
			arr[i]+=1;	
			sum++;	
			}
			
			int multiplier=1;
			mini=1;
			do
			{
				mini=mini*2;
				multiplier*=2;
				sum+=1;
			}while(mini<tmin);		

			for(int i=0;i<n;i++)
			{
			sum+=tarr[i]-(arr[i]*multiplier);		
			}		
		}
	}
	cout<<sum;
	return 0;
}
