#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];

	for (int i=0;i<n;i++)
	cin>>arr[i];

	int exp_sum=1,tot_sum=0;
	for(int i=0;i<n;i++)
	{
		if(tot_sum>= exp_sum)
		{
			exp_sum++;
			i--;
		}
		else
		{
			tot_sum+=arr[i];
		}
	
	}
	cout<<exp_sum+1;
	return 0;
}
