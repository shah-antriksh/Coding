//http://www.geeksforgeeks.org/compare-two-strings-represented-as-linked-lists/

#include<iostream>
#include<list>
using namespace std;

int main()
{

	list<char> l1;
	list<char> l2;
	list<char>::iterator i1;
	list<char>::iterator i2;

	char temp;
	do
	{
		cin>>temp;
		l1.push_back(temp);
	}while(temp!='.');

	do
	{
		cin>>temp;
		l2.push_back(temp);
	}while(temp!='.');

	i1=l1.begin();
	i2=l2.begin();
	while(i1!=l1.end()&&i2!=l2.end())
	{
		if(*i1==*i2)
		{
		i1++;
		i2++;
		}
		else
		{	
			if(*i1>*i2)
			cout<<-1;
			else
			cout<<1;
		return 0;
		}
	}	

	if(i1!=l1.end()||i2!=l2.end())
	{
		if(*i1>*i2)
			cout<<-1;
			else
			cout<<1;
	}
	cout<<0;	
	return 0;

}
