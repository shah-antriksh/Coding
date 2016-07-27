#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int compare(const void *a, const void *b)
{
if (*(int *)a > *(int*)b)
return 1;
else
return 0;
}

int main()
{

	int n,max;
	cin>>n;
	int arr[n];
	int neg_count=0;
	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]<0)	
		neg_count++;
	}

	qsort(arr,n,sizeof(int),compare);
	
	int answer = arr[n-1]*arr[n-2]*arr[n-3];
	if(neg_count>=2)
	{
	int temp1=arr[0]*arr[1]*arr[n-1];
	answer=std::max(answer,temp1);
	}
	cout<<answer;
	return 0;
}
