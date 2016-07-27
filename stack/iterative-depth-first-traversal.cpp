//http://www.geeksforgeeks.org/iterative-depth-first-traversal/

#include<iostream>
#include<stack>
#include<map>
using namespace std;



class node
{
	public:
	int v;
	list <int> *lst;
	
	node(int value);
	void addEdge(int s,int d);
	void DFS(int s);
};

node::node (int value)
{
	v=value;
	lst = new list<int>[v];	
}

void node::addEdge(int s,int d)
{
lst[v].push_back(d);
}

void node::DFS(int s)
{
	stack <int> st;
	bool visited[v]={0};
	int source=value;
	st.push(s);
	visited[s]=1;

	list<int>::iterator iter;

	while(!s.empty())
	{
			s=st.top();
			cout<<st;
			st.pop();

			for(iter = lst[s].begin();iter!=lst[s].end();iter++)
			{
				if(visited[*iter]==0)
				{
					visited[*iter]=1;
					st.push(*iter);
				}

			}
	
	}	
	
}


int main()
{

node n(5);
n.addEdge(1,0);
n.addEdge(0,2);
n.addEdge(2,1);
n.addEdge(0,3);
n.addEdge(3,4);
n.addEdge(4,0);
n.DFS(0);
return 0;
}
