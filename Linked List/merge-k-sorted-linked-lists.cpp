#include<iostream>
#include<list>
using namespace std;

void swap (list <int> &l1, list <int> &l2)
{
list <int>::iterator i1;
list <int>::iterator i2;

i1=l1.begin();
i2=l2.begin();
	while (i1!=l1.end() && i2!=l2.end())
	{
		if(*i1<*i2)
		{
		i1++;
		}
		else
		{
		l1.insert(i1,*i2);
		i2++;
		}
	}
	while (i2!=l2.end())
	{
		l1.push_back(*i2);
		i2++;
	}
}

int main()
{

int k,n;
cin>>k>>n;

list < list <int> > lst;

	for (int i=0;i<k;i++)
	{	
		list <int> temp_list;
		temp_list.clear();
		for (int j=0;j<n;j++)
		{
			int temp_no;
			cin>>temp_no;
			temp_list.push_back(temp_no);
		}
		lst.push_back(temp_list);	
	}
	
		
	list <int> l1 = lst.front();
	lst.pop_front();
	while(lst.size()>0)
	{
		list <int> l2 = lst.front();
		lst.pop_front();
		swap(l1,l2);
	}
	
	list <int>::iterator i1;

	for (i1=l1.begin();i1!=l1.end();i1++)
	{
		cout<<*i1;
	}
	return 0;
}


