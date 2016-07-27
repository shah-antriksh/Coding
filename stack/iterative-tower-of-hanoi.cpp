//http://www.geeksforgeeks.org/iterative-tower-of-hanoi/

#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

void move (stack <int> *l, stack<int> *r)
{
int temp;
	if(r->empty())
	{
	temp=l->top();
	l->pop();
	r->push(temp);
	}

	else if(l->empty())
	{
	temp=r->top();
	r->pop();
	l->push(temp);
	}

	else if(l->top() < r->top())
	{
	temp=l->top();
	l->pop();
	r->push(temp);
	}

	else
	{
	temp=r->top();
	r->pop();
	l->push(temp);
	}
}

int main()
{
	int n;
	cin>>n;
	stack <int> s[3];
	for (int i=n;i>0;i--)
	{
		s[0].push(i);
	}

	int moves = pow(2,n)-1;
	for (int i=1;i<=moves;i++)
	{
		if(i%3==1)
		{
			move(&s[0],&s[2]);				
		}
		else if (i%3==2)
		{
			move(&s[0],&s[1]);
		}
		else	
		{
			move (&s[1],&s[2]);
		}
	}
	while(s[2].size()>0)
	{
		cout<<s[2].top()<<" ";
		s[2].pop();
	}
	return 0;
}
