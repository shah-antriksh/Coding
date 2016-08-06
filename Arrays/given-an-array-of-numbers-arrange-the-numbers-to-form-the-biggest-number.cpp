//http://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/

#include<bits/stdc++.h>
using namespace std;

	bool cmp (const string x,const string y)
	{
		string xs,ys;
		xs.append(x);
		ys.append(y);
		if(xs.compare(ys)>0)
		return true;
		else
		return false;
	}

int main()
{
	string s;
	vector<string>vec;
	vector<string>::iterator iter;
	while(cin>>s)
	{
		vec.push_back(s);
	}

	sort(vec.begin(),vec.end(),cmp);
	for(iter=vec.begin();iter!=vec.end();iter++)
		cout<<*iter;
}

//1 2 3

