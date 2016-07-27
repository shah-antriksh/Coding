//http://www.geeksforgeeks.org/the-stock-span-problem/

#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int ans[n];
	ans[0]=1;
	stack<int> s;
	s.push(0);
	for(int i=1;i<n;i++)
	{
		while(!s.empty() && arr[i]>arr[s.top()])
		{
			s.pop();
		}

		if(s.empty())
		{
			ans[i]=i+1;
		}
		else
		{
			ans[i]=i-s.top();
		}
		s.push(i);
	}

	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}

	return 0;
}
