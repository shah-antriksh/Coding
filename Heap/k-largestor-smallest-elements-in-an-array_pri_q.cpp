//http://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct cmp
{
    bool operator()(int a, int b)
    {
        if(a<b)
	return true;
	else
	return false;
    }
};


int main()
{

	int n,k;
	cin>>n>>k;
	int arr[n];

	priority_queue<int, vector<int>, cmp> pq;

	for (int i=0;i<n;i++)
	{
	cin>>arr[i];
	pq.push(arr[i]);
	}
	
	for (int i=0;i<k;i++)
	{
		cout<<pq.top();
		pq.pop();
	}

	return 0;

}
