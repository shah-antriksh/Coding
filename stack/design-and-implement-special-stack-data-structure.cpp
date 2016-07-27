//http://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/

#include<iostream>
#include<stack>
using namespace std;

void pop(stack <int> *s, stack <int> *aux)
{
	if(!s->empty())
	{
		if(s->top()<=aux->top())
		{
		aux->pop();
		}
		s->pop();
	}
}

void getMin(stack <int> *s, stack <int> *aux)
{
	if(!aux->empty())
	cout<<aux->top();
}

int main()
{
	stack <int> s,aux;
	int temp;

	cin>>temp;
	s.push(temp);
	aux.push(temp);
	cin>>temp;	
	while(temp!=-1)
	{
		s.push(temp);
		if(temp<=aux.top())
		{
			aux.push(temp);
		}
		cin>>temp;
	}

	getMin(&s,&aux);
	pop(&s,&aux);
	getMin(&s,&aux);
	pop(&s,&aux);

	return 0;
}
