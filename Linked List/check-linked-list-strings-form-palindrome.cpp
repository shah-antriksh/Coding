//http://www.geeksforgeeks.org/check-linked-list-strings-form-palindrome/

#include<iostream>
#include<string>
#include<list>
using namespace std;

int main()
{
	list <string> lst;
	list <string>::iterator iter;
	string temp;
	cin>>temp;
	while(temp!="NULL")
	{
		lst.push_back(temp);
		cin>>temp;
	}
	temp="";
	for (iter=lst.begin();iter!=lst.end();iter++)
	{
	temp+=*iter;
	}
	cout<<temp;

	int l=0,r=temp.size()-1;
	
	while(l<r)
	{
		if(temp[l]==temp[r])
		{
			l++;
			r--;
		}
		else
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
