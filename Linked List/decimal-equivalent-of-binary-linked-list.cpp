//http://www.geeksforgeeks.org/decimal-equivalent-of-binary-linked-list/

#include<iostream>
#include<list>
using namespace std;

int main()
{
	int n;
	cin>>n;
	list <int> li;
	int temp;
	for (int i=0;i<n;i++)
	{
		cin>>temp;
		li.push_back(temp);
	}

	list<int>::iterator iter;
	int sum=0;
	for (iter=li.begin();iter!=li.end();iter++)
	{
		if(*iter==1)
		{
		sum*=2;
		sum+=1;
		}
		else
		{
		sum*=2;
		}
	}
	cout<<sum;
	return 0;
}
