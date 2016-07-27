//http://www.geeksforgeeks.org/form-minimum-number-from-given-sequence/

#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;

queue<int> q;
stack<int> s;

void func_D(int count)
{
cout<<"CountD="<<count<<endl;
	for(int i=0;i<count;i++)
	{
		int temp;
		temp=q.front();
		q.pop();
		s.push(temp);
	}
	for(int i=0;i<count;i++)
	{
		cout<<s.top();
		s.pop();
	}
}

void func_I(int count)
{
//cout<<"CountI="<<count<<endl;
	for(int i=0;i<count-1;i++)
	{
		int temp;
		temp=q.front();
		q.pop();
		s.push(temp);
	}
	cout<<q.front();
	q.pop();
	for(int i=0;i<count-1;i++)
	{
		cout<<s.top();
		s.pop();
	}
}


int main()
{
	string arr_temp,arr;
	cin>>arr_temp;
	if(arr_temp[0]=='D')
	{
	arr='D'+arr_temp;
	}
	else
	arr='I'+arr_temp;
	int len1=arr.length();
	//cout<<"Length="<<len1<<" ";	
	int left=0,right=0;

	for(int i=1;i<=9;i++)
	{
	q.push(i);
	}

	while(left<len1)
	{
		char ch = arr[left];
		//cout<<"CH="<<ch<<endl;
		if (ch=='D')
		{
			right=left;
			while(arr[right+1]=='D')
			{
			right++;
			}
			func_D(right-left+1);	
			left=right;
			left++;		
		//	cout<<"left="<<left;		
		}
		else
		{
		//	cout<<"else_left"<<left;
			right=left;
			while(arr[right+1]=='D')
			{
			right++;
			}
			func_I(right-left+1);
			left=right;	
			left++;		
		//	cout<<"left="<<left;		
		}
	}

	return 0;
}
