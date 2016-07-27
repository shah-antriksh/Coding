#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++)
	cin>>arr[i];

	int cur_sum=0,max_sum=0,index=0;;
	for (int i=0;i<n;i++)
	{
		if(arr[i]<0)
		continue;

		cur_sum=arr[i];
		max_sum=max(cur_sum,max_sum);
		for (int j=i+1;j<n || j%n<i;j++)
		{
			index=j%n;
			if(arr[index]+cur_sum>0)
			{
				cur_sum+=arr[index];
				if(cur_sum > max_sum)
				{
				max_sum=cur_sum;
				}

			}
			else
			break;
			
		}
	
	}
	cout<<max_sum;
	return 0;
}
