//http://www.geeksforgeeks.org/merging-intervals/

#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int> a , const pair<int, int> b)
{
	if(b.first>a.first)
	return true;
	else
	return false;
}

int main()
{
	vector < pair<int,int> >vec;
	int st,e;
	while(cin>>st)
	{
		cin>>e;
		vec.push_back({st,e});
	}
	sort(vec.begin(),vec.end(),cmp);
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i].first<<vec[i].second<<endl;
	}
	int flag=0;
	stack < pair<int,int> >s;
	
	s.push(vec[0]);
	for(int i=1;i<vec.size();i++)
	{
		pair <int,int> p = vec[i];
		pair <int,int> top = s.top();
		if(top.second>=p.first)
		{
			top.second=max(top.second,p.second);
			s.pop();
			s.push(top);			
		}
		else
		{
			s.push(p);
		}

	}	
	while(!s.empty())
	{
		pair <int,int> top = s.top();
		s.pop();
		cout<<"{"<<top.first<<","<<top.second<<"}";
		cout<<endl;
	}
	return 0;

}



//6 8 1 9 2 4 4 7 
