#include<iostream>
#include<list>
#include<string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int temp;
	list <int> l;
	list <int>::iterator iter;
	int ans1[n+1];
	for (int i=0;i<n;i++)
	{
		cin>>temp;
		l.push_back(temp);
	}
	int i=0;
	for (iter=l.begin();iter!=l.end();iter++)
	{
		cout<<*iter<<endl;
		ans1[i]=*iter;
		i++;
	}

	int carry=1,a,temps;
	for (int i=n-1;i>=0;i--)
	{
		a=ans1[i];
		temps=a+carry;
		if(temps>9)
		{
		carry=1;
		a=temps-10;
		}
		else
		{
		carry=0;
		a=temps;
		}
		ans1[i]=a;
	}
	if(carry==1)
	{
	cout<<1;
	}
	for(int i=0;i<n;i++)
	{
	cout<<ans1[i];
	}
	
}
