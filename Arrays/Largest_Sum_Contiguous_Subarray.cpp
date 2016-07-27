#http://www.geeksforgeeks.org/maximum-absolute-difference-between-sum-of-two-contiguous-sub-arrays/

#include<iostream>
#include<stdlib.h>
using namespace std;

int max(int a,int b)
{
	if(a>b)
	return a;
	else
	return b;
}

void left_max_sum(int n,int *arr, int *l_mx_sum)
{
	int max_sum=arr[0];
	int cur_sum=arr[0];
	l_mx_sum[0]=arr[0];

	for(int i=1;i<n;i++)
	{
	cur_sum=max(cur_sum+arr[i],arr[i]);
	max_sum = max(max_sum,cur_sum);
	l_mx_sum[i]=max_sum;
	}
}

void right_max_sum(int n,int *arr, int *r_mx_sum)
{
	int max_sum=arr[n];
	int cur_sum=arr[n];
	r_mx_sum[n]=arr[n];

	for(int i=n-1;i>=0;i--)
	{
	cur_sum=max(cur_sum+arr[i],arr[i]);
	max_sum = max(max_sum,cur_sum);
	r_mx_sum[i]=max_sum;
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n],arrn[n];
	int l_mx_sum[n],r_mx_sum[n],l_mn_sum[n],r_mn_sum[n];

	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
		arrn[i]=-arr[i];
	}

	left_max_sum(n,arr,l_mx_sum);
	right_max_sum(n-1,arr,r_mx_sum);
	left_max_sum(n,arrn,l_mn_sum);
	right_max_sum(n-1,arrn	,r_mn_sum);
	
	for(int i=0;i<n;i++)
	{
		l_mn_sum[i]=-l_mn_sum[i];
		r_mn_sum[i]=-r_mn_sum[i];
	}
	
/*
	for(int i=0;i<n;i++){
	cout<<l_mx_sum[i]<<" ";}	
	cout<<endl;
	for(int i=0;i<n;i++){
	cout<<r_mx_sum[i]<<" ";}
	cout<<endl;
	for(int i=0;i<n;i++){
	cout<<l_mn_sum[i]<<" ";}
	cout<<endl;
	for(int i=0;i<n;i++){
	cout<<r_mn_sum[i]<<" ";}	
	cout<<endl;
*/
	int answer=0,temp1,temp2;		
	for(int i=0;i<n-1;i++)
	{
		temp1=(abs(l_mx_sum[i]-r_mn_sum[i+1]));
		temp2=(abs(l_mn_sum[i]-r_mx_sum[i+1]));
		temp1=max(temp1,temp2);
		answer=max(answer,temp1);
	}

	cout<<answer;
	return 0;
}
