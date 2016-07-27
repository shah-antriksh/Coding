//http://www.geeksforgeeks.org/length-of-the-longest-valid-substring/

#include<iostream>
#include<stack>
using namespace std;

int main()
{

	char temp;
	cin>>temp;
	stack <char> s;
	int ans=0,tans=0;
	while(temp!='.')
	{
		if(s.empty())
		{
			if(temp=='(')
			s.push(temp);
			else
			{
			ans=max(tans,ans);
			tans=0;
			}

		}
		else
		{
			if(temp=='(')
			s.push(temp);
			else if (temp==')' && s.top()=='(')
			{
				tans+=2;
				s.pop();
			}
			else
			{
				ans=max(tans,ans);
				tans=0;
				s.push(temp);
			}
		}		
	
	cin>>temp;
	}
	cout<<max(ans,tans);
	return 0;

}
