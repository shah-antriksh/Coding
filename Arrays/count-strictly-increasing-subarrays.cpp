#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int answer=0;
	int low=0,high=0;
	int m;
	while(high<n-1)
	{
		while(arr[high+1]>arr[high] && high!=n-1)
		{
			high++;
		}
		m=high-low+1;
		if(m>1 && high!=n)
		{
			answer+=(m*(m-1))/2;
			high=high+1;
			low=high;
		}
	}
	cout<<answer;
	return 0;	
}
