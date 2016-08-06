//http://www.geeksforgeeks.org/maximum-length-bitonic-subarray/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> vec;
	int element;
	deque<int>q;		
	int flag=0;
	int count=0,ans=0;
	cin>>element;
	q.push_back(element);

	while(cin>>element)
	{
		if (flag==0 && element>=q.back())
		{
			q.push_back(element);	
		}
		else if (flag==0 && element<q.back())
		{
			flag=1;
			q.push_back(element);	
		}		
		else if (flag==1 && element<=q.back())
		{
			q.push_back(element);
		}
		else
		{
			int qs=q.size();
			ans=max(ans,qs);
			flag=0;
			int top=q.front();
			q.pop_front();
			while(q.front()>top && q.size()!=0)
			{
				top=q.front();
				q.pop_front();
			}
			while(q.front()>element && q.size()!=0)
			q.pop_front();

			q.push_back(element);
		}
	}
	int qs=q.size();
	ans=max(ans,qs);
cout<<ans;	
}


//12 4 78 90 45 23
//1 2 3 4 5
//5 4 3 2 1
//5 1 6 2 7



/*	
	for(iter=vec.begin();iter!=vec.end();iter++)
	{
		
		if(iter==vec.begin())
		q.push_back(*iter);
		else
		{	
			//the sequence is still increasing
			if(*iter>q.back())
			{
				q.push_back(*iter);
				count++;
			}
			//the sequence has just started to decrease
			else if(*iter<q.back() && flag==0)
			{
				flag=1;
				q.push_back(*iter);
				count++;
			}
			else
			{
				count=0;
				ans=max(count,ans);
				int front = q.front();
				q.pop_front();
				flag=0;
				while(true)
				{
					if(q.size()==0)
					break;
					else if (flag==0 && q.front()>front)
					{
						front=q.front();
						q.pop_front();
					}
					else
					{
						flag=1;
						while(true)
						{
							if(q.size==0)
							break;
							else if(q.front()<*iter)
							break;
							else
							q.pop_front();
						}
					}
				}
				
			}
		}	

	}
*/
