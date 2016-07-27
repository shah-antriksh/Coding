//http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

#include<iostream>
#include<stack>
using namespace std;

int main()
{
int n=0;
cin>>n;
int arr[n]={0};

for (int i=0;i<n;i++)
cin>>arr[i];
int ans=0;

stack<int> s;
int temp_ans=0;
int i=0;
while(i<n)
{

	if(s.empty() || arr[i]>=arr[s.top()])
	{
	cout<<"Pushed index "<<i<<" value="<<arr[i]<<endl;
	s.push(i);
	i++;
	}
	else
	{
			int temp_i = s.top();
			s.pop();

			if(s.empty())
			{
				temp_ans=((arr[temp_i])*i);
			}
			else
			{
				temp_ans=arr[temp_i]*(i-s.top()-1);
			}
			ans=max(ans,temp_ans);
			cout<<"Popped index "<<temp_i<<" value="<<arr[temp_i]<<" temp_ans "<<temp_ans<<" Max ans "<<ans<<endl;
	}
}	

while(!s.empty())
{
			int temp_i = s.top();
			s.pop();

			if(s.empty())
			{
				temp_ans=((arr[temp_i])*n);
			}
			else
			{
				temp_ans=arr[temp_i]*(n-s.top()-1);
			}
			ans=max(ans,temp_ans);
			cout<<"Popped index "<<temp_i<<" value="<<arr[temp_i]<<" temp_ans "<<temp_ans<<" Max ans "<<ans<<endl;
}
cout<<ans;

}
