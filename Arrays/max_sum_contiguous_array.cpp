#http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
#Kadane Algorithm

#include<iostream>
using namespace std;

int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}

int max_sum(int n,int *arr)
{
	int max_sum=arr[0];
	int cur_sum=arr[0];
	
	cout<<"i->"<<0<<"max_sum="<<max_sum;
	cout<<" cur_sum="<<cur_sum<<endl;

	for(int i=1;i<n;i++)
	{
		
		max_sum=max(cur_sum+arr[i],max_sum);

		cur_sum=cur_sum+arr[i];

		if(cur_sum<arr[i])
		cur_sum=arr[i];

		if(cur_sum<0)
		cur_sum=0;

	cout<<"i->"<<i<<"max_sum="<<max_sum;
	cout<<" cur_sum="<<cur_sum<<endl;

	}
	return max_sum;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];

	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int sum=0;
	sum=max_sum(n,arr);
	cout<<sum;

	return 0;
}
