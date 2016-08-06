//http://www.geeksforgeeks.org/find-the-two-numbers-with-odd-occurences-in-an-unsorted-array/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>vec;
	vector<int>::iterator iter;
	int element;
	while(cin>>element)
	{
	vec.push_back(element);
	}

	int ans1=0;

	for(iter=vec.begin();iter!=vec.end();iter++)
	{
	ans1=ans1^(*iter);
	}

	ans1^=0;
	cout<<ans1;
	
	int rsbit = (ans1) & (~(ans1-1));
	cout<<rsbit;
	int x=0,y=0;
	for(iter=vec.begin();iter!=vec.end();iter++)
	{
		if(((*iter)&rsbit) == 0)
		{
			cout<<endl<<"inside if";
			cout<<*iter;
			cout<<endl;
			x=x^(*iter);
		}
		else
		{
			cout<<endl<<"inside else";
			cout<<*iter<<rsbit;
			cout<<endl;

			y=y^(*iter);
		}
	}
	x=x^0;
	y=y^0;

	cout<<x<<" "<<y;
}

/*
3 3
*/
