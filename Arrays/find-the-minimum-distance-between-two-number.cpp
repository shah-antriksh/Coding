//http://www.geeksforgeeks.org/find-the-minimum-distance-between-two-numbers/

#include<bits/stdc++.h>
using namespace std;

int main()
{

int x,y,input;
vector<int>vec;
cin>>x>>y;

int f1=-1,f2=-1;
int ans=INT_MAX;
int li=-1,ri=-1;

int index=0;
while(cin>>input)
{
	if(input==x)
	{
		if(f1==-1)
		f1=1;
		else
		{
			if(f2!=-1)
			{
			cout<<li<<ri<<endl;
			ans=min(ans,max(li,ri)-min(li,ri));
			}	
		}
		li=index;
		if(f2!=-1)
		{
			cout<<li<<ri<<endl;
			ans=min(ans,max(li,ri)-min(li,ri));
		}
	}
	if(input==y)
	{
		if(f2==-1)
		f2=1;
		else
		{
			if(f1!=-1)
			{
			cout<<li<<ri<<endl;
			ans=min(ans,max(li,ri)-min(li,ri));
			}	
		}
		ri=index;
		if(f1!=-1)
		{
			cout<<li<<ri<<endl;
			ans=min(ans,max(li,ri)-min(li,ri));
		}
	}
index++;
}
cout<<ans;
}

//3 5 3 4 5
//3 6 3 5 4 2 6 5 6 6 5 4 8 3
//3 2 2 5 3 5 4 4 2 3 
