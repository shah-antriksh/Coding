#include<iostream>
#include<utility>
#include<list>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,sum;
	cin>>n>>sum;
	int tno;
	//value,count
	list < pair <int, int> > q;
	list < pair<int,int> >::iterator qit;
	for (int i=0;i<n;i++)
	{
		cin>>tno;	
		list < pair <int , int> > tq;

		int size=q.size();		
		for(int i=0;i<size;i++)
		{
		pair <int,int> tp = q.front();
			if(tp.second<=2)
			{	
				if(tno+tp.first < sum)
				{
					int tempval,tempno;
					tempval=tno+tp.first;
					tempno=tp.second+1;
					tq.push_back(make_pair(tempval,tempno));
				}
			}
			tq.push_back(tp);
			q.pop_front();
		} 

		size=tq.size();
		q.clear();
		for(int i=0;i<size;i++)
		{
			pair <int,int> tp = tq.front();
			tq.pop_front();
			q.push_back(tp);
		}
		if(tno<sum)
		q.push_back(make_pair(tno,1));
		/*
		cout<<endl<<"Contents of q"<<endl;
		for(qit=q.begin();qit!=q.end();qit++)
		{
			cout<<(*qit).first<<":"<<(*qit).second<<endl;
		}
		cout<<endl;
		*/
	}

	int size=q.size();
	int ans=0;
	for(int i=0;i<size;i++)
	{
		pair <int,int> tp = q.front();
		q.pop_front();
		if(tp.second==3)
			ans++;
	}
	cout<<ans;
	return 0;
}
