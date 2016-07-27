//http://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/

#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
using namespace std;

struct min_s
{
	bool operator()(int a,int b)
	{
		if (a>b)
		return true;
		else
		return false;
		
	}
};

struct max_s
{
	bool operator()(int a,int b)
	{
		if (a<b)
		return true;
		else
		return false;		
	}
};

priority_queue <int,vector<int>,min_s> minH;
priority_queue <int,vector<int>,max_s> maxH; 

float median(int value,int m)
{

	if(minH.size()<maxH.size())
	{
	//We need to insert into minHeap as in the right side
		if(value>m)
		{
			minH.push(value);
		}
		else
		{
			minH.push(maxH.top());
			maxH.pop();
			maxH.push(value);
		}
		return (minH.top()+maxH.top())/2;
	}
	else if(maxH.size()<minH.size())
	{
	//We need to insert into maxHeap as in the left side
		if(value<m)
		{
			maxH.push(value);
		}
		else
		{
			maxH.push(minH.top());
			minH.pop();
			minH.push(value);
		}
		return (minH.top()+maxH.top())/2;

	}
	else
	{
	//We need to insert in either of them
		if(value>m)
		{
			minH.push(value);
			m=minH.top();
		}
		else
		{
			maxH.push(value);
			m=maxH.top();
		}
		return m;
	}

}

int main()
{

	int temp;
	cin>>temp;
	float m=0;
	while(temp!=-1)
	{
		m=median(temp,(int)m);
		cout<<"median->"<<m;
		if (!maxH.empty())
		cout<<",MaxH.top->"<<maxH.top();		
		if(!minH.empty())
		cout<<",MinH.top->"<<minH.top()<<endl;
		
		cin>>temp;
	}
	return 0;

}
