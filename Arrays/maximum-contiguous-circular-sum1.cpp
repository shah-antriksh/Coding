//http://www.geeksforgeeks.org/maximum-contiguous-circular-sum/

#include<bits/stdc++.h>
using namespace std;

//1 -5 2 3 7
int kadane(int *arr,int n)
{
	int max_sum=INT_MIN,sum_so_far=0;
	for (int i=0;i<n;i++)
	{
		sum_so_far=max(sum_so_far+arr[i],arr[i]);
		max_sum=max(sum_so_far,max_sum);
	}
	return max_sum;
}

int invert(int *arr,int n)
{
	int sum=0;

	for (int i=0;i<n;i++)
	{
		sum+=arr[i];
		arr[i]*=-1;
	}
	return sum;
}


int main()
{
int n=0,i=0;
cin>>n;
int arr[n]={0};

while(cin>>arr[i])
{
i++;
}
int sum1=kadane(arr,n);
int tot_sum=invert(arr,n);
int sum2=kadane(arr,n);
cout<<endl<<sum1<<" "<<sum2<<" "<<tot_sum<<endl;
cout<<max(sum1,sum2+tot_sum);
return 0;
}


//6 -7 2 -9 4 -3 5
//7 8 -8 9 -9 10 -11 12
//8 10 -3 -4 7 6 5 -4 -1
//8 -1 40 -14 7 6 5 -4 -1 
