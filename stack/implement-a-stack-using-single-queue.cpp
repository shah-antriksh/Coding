//http://www.geeksforgeeks.org/implement-a-stack-using-single-queue/
#include<iostream>
#include<queue>
using namespace std;

class stack
{
	queue<int>q;
	public:
	void push(int val);
	void pop ();
	int top();
	bool empty();
};

void stack::push(int val)
{

	int s = q.size();
	q.push(val);
	for (int i=0;i<s;i++)
	{
		q.push(q.front());
		q.pop();
	}
}

void stack::pop()
{
if(!q.empty())
q.pop();
else
cout<<"Q empty";
}

int stack::top()
{
return q.front();
}

bool stack::empty()
{
if(!q.empty())
return false;
else
return true;
}

int main()
{
	stack s;
	s.push(10);
	s.push(20);
	cout<<s.top();
	s.push(30);
	cout<<s.top();
	s.pop();
	s.pop();
	cout<<s.top();
	s.pop();
	
	return 0;
}	

