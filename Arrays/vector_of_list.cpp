#include<iostream>
#include<list>
#include<vector>
using namespace std;
/*
struct node
{
int label;
int no;
};
*/
int main()
{
	vector < list <int> > node_vector;

	for(int i=0;i<5;i++)
	{
	list< int > temp;
	temp.push_back(10*i);
	temp.push_back(20*i);
	temp.push_back(30*i);	
	node_vector.push_back(temp);
	}

	for(int i=0;i<node_vector.size();i++)
	{
		list <int > temp= node_vector[i];
		while(!temp.empty())
		{
			cout<<temp.front()<<" ";
			temp.pop_front();
		}	
	cout<<endl;
	}


return 0;
}
