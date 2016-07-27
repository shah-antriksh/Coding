#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<limits.h>

using namespace std;


struct node
{
	int value;
	int qno;
};

struct comparator
{
	bool operator()(node i,node j)
	{
		if (i.value>j.value)
			return true;
		else
			return false;
	}
};

int main()
{
	int k,n;
	vector < list < node > > arr;
	cin>>k>>n;

	for(int i=0;i<k;i++)
	{
	list <node> row;
		for (int j=0;j<n;j++)
		{
			node temp;
			cin>>temp.value;
			temp.qno=i;
			row.push_back(temp);
		}
	arr.push_back(row);
	}
	
	int min = INT_MAX;
	int max= INT_MIN;
	int range = INT_MAX;
	int min_ans=-1;
	int max_ans=-1;

	priority_queue <node,vector<node>,comparator> pq;
	list <node> *listrow;
	node temp_node;
	for (int i=0;i<k;i++)
	{
		listrow=&arr[i];
		temp_node=listrow->front();
		pq.push(temp_node);
	
		if ( temp_node.value > max)
		{
		max=temp_node.value;
		max_ans=max;
		}
		if (temp_node.value<min)
		{		
		min = temp_node.value;
		min_ans=min;  		
		}
		listrow->pop_front();
		 
	}
	
	range=max-min;
	int step=0;
	while (true)
	{
		temp_node=pq.top();
		min=temp_node.value;
		pq.pop();
		int qno = temp_node.qno;
		int value = temp_node.value;
			
		if(max-value<range)
		{
		range = max-value;
		max_ans=max;
		min_ans=min;
		}

		listrow=&arr[qno];
		
		cout<<"max"<<max<<"min"<<min<<"range"<<range<<endl;
		if(listrow->empty())
		break;
	
		else
		temp_node=listrow->front();
		listrow->pop_front();	

		if (temp_node.value>max)
		max=temp_node.value;
		
		pq.push(temp_node);
	}
	
		cout<<"["<<min_ans<<","<<max_ans<<"]"<<range;	
return 0;
}

