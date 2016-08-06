//http://www.geeksforgeeks.org/find-number-of-triangles-possible/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i=0;
	cin>>n;
	int arr[n];
	while(cin>>arr[i++]){}
	sort(arr,arr+n);
	
	int count=0;
	for(int i=0;i<n-2;i++)
	{
		int k=i+2;
		for(int j=i+1;j<n;j++)
		{
			while(arr[k]<arr[i]+arr[j] && k<n)
			{
				k++;
			}
			cout<<i<<j<<k;			
			count+=k-j-1;
			cout<<k-j-1<<endl;
		}
	}
	cout<<count;
}

//5 5 4 3 2 1
//4 4 6 3 7
//7 10 21 22 100 101 200 300

//3 4 6 7
