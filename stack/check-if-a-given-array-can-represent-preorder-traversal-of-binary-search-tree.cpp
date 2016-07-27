//http://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/

#include<iostream>
#include<stack>
#include<climits>
using namespace std;
int main()
{
	int n=0,flag=0;
	cin>>n;
	int arr[n]={0};
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	stack <int> s;
	
	int root=INT_MIN;

	for(int i=0;i<n;i++)
	{
		if(arr[i]<root)
		{
			flag=1;
			break;
		}
		while(!s.empty() && arr[i]>s.top())
		{
			root=s.top();
			s.pop();
		}	
			
		s.push(arr[i]);
	}
	if(flag==0)
	cout<<"yes";
	else
	cout<<"no";

	return 0;
}
