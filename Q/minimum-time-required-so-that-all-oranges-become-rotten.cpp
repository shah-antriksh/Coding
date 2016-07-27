//http://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten/

#include<iostream>
#include<queue>
#include<utility>
using namespace std;

const int c_const=1000;
int arr[1000][1000];
int count=0;
void mark(int r, int c, int i,int j,queue < pair <int, int> > *q)
{
	if(i-1>=0 && i-1<r)
	{
		if(arr[i-1][j]==1)
		{
			arr[i-1][j]=2;
			q->push(make_pair(i-1,j));
			cout<<i-1<<j;
			count--;
		}
	}
	
	if(i+1>=0 && i+1<r)
	{
		if(arr[i+1][j]==1)
		{
			arr[i+1][j]=2;
			q->push(make_pair(i+1,j));
			cout<<i+1<<j;	
			count--;
		}
	}

	if(j-1>=0 && j-1<c)
	{
		if(arr[i][j-1]==1)
		{
			arr[i][j-1]=2;
			q->push(make_pair(i,j-1));
			cout<<i<<j-1;
			count--;
		}
	}

	if(j+1>=0 && j+1<c)
	{
		if(arr[i][j+1]==1)
		{
			arr[i][j+1]=2;
			q->push(make_pair(i,j+1));
			cout<<i<<j;
			count--;
		}
	}

}

int main()
{
	int r,c;
	cin>>r>>c;

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>arr[i][j];
		}
	}

	queue < pair <int, int> > q;
	int ans=-1;

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(arr[i][j]==2)
			{
				q.push(make_pair(i,j));
			}
			if(arr[i][j]==1)
				count++;
		}
	}
	q.push(make_pair(-1,-1));
	int i=0,j=0;
	cout<<q.size()<<endl;

	pair <int,int> cur_value = make_pair(-1,-1);
	while(!q.empty())
	{

		cout<<"q.size->"<<q.size();

		cur_value=q.front();
		q.pop();
		i=cur_value.first;
		j=cur_value.second;
		cout<<" "<<i<<j<<" ";
	
		if(i==-1)
		{
			if(q.empty())
			{
			ans++;
			break;
			}
			else
			{
				q.push(make_pair(-1,-1));
				ans++;
			}
		}	
		else
		{
			mark(r,c,i,j,&q);
		}

		cout<<"q.size->"<<q.size()<<endl;
	}
	cout<<endl;
	if(count!=0)
	cout<<"no";
	else
	cout<<ans;
	return 0;
}
