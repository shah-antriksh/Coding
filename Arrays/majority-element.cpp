//http://www.geeksforgeeks.org/majority-element/

#include<bits/stdc++.h>
using namespace std;

int main()
{
vector<int> vec;
int element;
//index value
do
{
	cin>>element;
	if(element==-1)
		break;
	else
	{
		vec.push_back(element);
	}
}while(true);

int value=0;
int count=0;
vector<int>::iterator iter;

for(iter=vec.begin();iter!=vec.end();iter++)
{

	if(iter==vec.begin())
	{
	value=*iter;
	count++;
	}
	else
	{
		if(*iter==value)
		count++;
		else 
		count--;

		if(count<=0)
		{
		value=*iter;
		count=0;
		}
	}	
}
count=0;
for(iter=vec.begin();iter!=vec.end();iter++)
{
	if(*iter==value)
	count++;
}

if(count>vec.size()/2)
cout<<value<<" is the max element";
else
cout<<"No max element";
}

/*
Input 1: 1 1 1 3 3 9 3 3 3 -1
Input 2: 7 7 3 5 7 -1
*/
