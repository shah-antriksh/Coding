//http://www.geeksforgeeks.org/next-greater-element/

#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int n=0;
	cin>>n;
	int arr[n]={0},ans[n]={0};

	for (int i=0;i<n;i++)
	cin>>arr[i];

	stack <int> s;

	int i=0,temp=0;
	while(true)
	{
		if(i==n-1)
		{
			ans[i]=-1;
			break;
		}
		else
		{

			if(s.empty() || arr[i]<=arr[s.top()])
			{
			s.push(i);
			i++;	
			}

			else
			{
				temp=s.top();
				s.pop();
				ans[temp]=arr[i];

			}
		}
	}
	while(!s.empty())
	{
	int temp=s.top();
	ans[temp]=-1;
	s.pop();
	}
	for(i=0;i<n;i++)
	{
		cout<<ans[i];
	}
}
