//http://www.geeksforgeeks.org/maximum-of-all-subarrays-of-size-k/
#include<iostream>
#include<deque>
using namespace std;

int main()
{
	int n=0,k=0;
	cin>>n>>k;
	int arr[n]={0};

	for (int i=0;i<n;i++)
	cin>>arr[i];

	deque <int> dq;
	int i=0;
	for (;i<k;i++)
	{
		//cout<<arr[dq.front()];
		while(!dq.empty() && arr[i]>=arr[dq.back()])
		{
			dq.pop_back();
		}
		dq.push_back(i);
	}	

	for (;i<n;i++)
	{
		cout<<arr[dq.front()];
		while(!dq.empty() && (dq.front() <= (i-k)))
		{
			dq.pop_front();
		}
		while(!dq.empty() && arr[i]>=arr[dq.back()])
		{
			dq.pop_back();
		}
		dq.push_back(i);
	}
	cout<<arr[dq.front()];
	return 0;
}

