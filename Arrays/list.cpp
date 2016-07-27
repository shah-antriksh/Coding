#include<iostream>
#include<list>
using namespace std;

int main()
{
	list <int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);

/*
	list <int>::iterator li;
	for (li=l.begin();li!=l.end();li++)
	{
		
	}
*/

	for(int i=0;i<l.size();i++)
	{
	cout<<l.front();
l.pop_front();

cout<<l.front();
l.pop_front();

cout<<l.front();
l.pop_front();


	}

	return 0;

}

