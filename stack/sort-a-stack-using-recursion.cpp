//http://www.geeksforgeeks.org/sort-a-stack-using-recursion/

#include<iostream>
#include<stack>
using namespace std;

void stackSort(stack<int> *s, int val)
{
int temp;
	if(s->empty() || val>(s->top()))
	{
		s->push(val);
	}
	else
	{
		temp=s->top();
		s->pop();
		stackSort(s,val);
		s->push(temp);
	}

}


void sort(stack <int> *s)
{
int temp=-999;
	if(!s->empty())
	{
	temp=s->top();
	s->pop();
	sort(s);
	}
	if(temp!=-999)
	stackSort(s,temp);
}

int main()
{

	int temp;
	cin>>temp;
	stack <int> s;
	while(temp!=-1)
	{
		s.push(temp);
		cin>>temp;
	}
	sort(&s);
	while(s.size()>0)
	{
		cout<<s.top()<<" "	;
		s.pop();
	}
	return 0;
}
