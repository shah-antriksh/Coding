/*
key value
1 2
1 3
1 4
2 2
2 3
2 4
*/


#include<bits/stdc++.h>
using namespace std;


int main()
{
map< int, list <int>  >mp;
map< int, list <int>  >::iterator iter;

int input;
	while(cin>>input)
	{
		iter=mp.find(input);
		if (iter==mp.end())
		{
			list<int> l;
			l.push_back(input);
			mp.insert(make_pair(input,l));
		}
		else
		{
			iter->second.push_back(input);
		}
	}
list<int>l=mp[3];
cout<<l.front();
cout<<mp.size();

}
// 1 2 3 1 2 3 
