//http://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced/

#include<iostream>
#include<stack>
using namespace std;

int main()
{
	stack <char> s;
	char ch;
	cin>>ch;
	while(ch!='.')
	{
		if(s.empty())
		{
		s.push(ch);
		cin>>ch;
		continue;
		}
		
		if(ch =='}' && s.top()=='{')
		s.pop();

		else
		{
		s.push(ch);
		}
		cin>>ch;
	}
	int count=0;
	if(s.empty())
	cout<<"Yes"<<count;
	else
	{
	char a,b;
		while(!s.empty())
		{
			a=s.top();
			s.pop();

			if(s.empty())
			{
				cout<<"No";
				return 0;
			}
			else
			{
				b=s.top();
				s.pop();
			}
			if(a=='{' && b=='}')
			count+=2;
			else
			count+=1;
		}
			cout<<"Yes"<<count;
	}
	return 0;

}
