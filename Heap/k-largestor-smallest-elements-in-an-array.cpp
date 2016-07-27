//http://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{

	int n,k;
	cin>>n>>k;
	int arr[n];

	for (int i=0;i<n;i++)
	cin>>arr[i];

	vector <int> vec(arr,arr+n);
	make_heap (vec.begin(),vec.end());

	for (int i=0;i<k;i++)
	{
		cout<<vec.front();
		pop_heap(vec.begin(),vec.end());
		vec.pop_back();
	}

	return 0;

}
