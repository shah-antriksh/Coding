#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct node
{
int value;
string name;
};

struct comparator
{
	bool operator()(node i, node j)
	{
		if (i.value < j.value)
		return true;
		else
		return false;
	}

};

int main()
{

	priority_queue<node,vector<node>,comparator> pq;

	for (int i=0;i<5;i++)
	{
	int temp=i*10;
	node n;
	n.value=temp;
	n.name=i;
	pq.push(n);	
	}

	for(int i=0;i<5;i++)
	{
	node temp=pq.top();
	cout<<temp.value<<endl;
	pq.pop();
	}

}
