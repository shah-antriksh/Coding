#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector <int> vec;
	vector <int>::const_iterator iter;
	int n=0,k=0,temp=0;
	cin>>n>>k;
	int arr[n];

	for (int i=0;i<n;i++)
		cin>>arr[i];

	for (int i=0;i<k;i++)
	{
		temp=arr[i];
		vec.push_back(temp);	
	}

	make_heap(vec.begin(),vec.end(),greater<int>());
	for(int i=k;i<n;i++)
	{
		cout<<endl;
		for (iter=vec.begin();iter!=vec.end();iter++)
		{
			cout<<*iter;	
		}
		cout<<endl;
		cout<<vec.front();
		pop_heap(vec.begin(),vec.end(),greater<int>());
		vec.pop_back();
		temp=arr[i];
		vec.push_back(temp);
		push_heap(vec.begin(),vec.end(),greater<int>()); 
	}
	while(vec.size()>0)
	{
		cout<<vec.front();
		pop_heap(vec.begin(),vec.end(),greater<int>());
		vec.pop_back();
	}
	return 0;
}
