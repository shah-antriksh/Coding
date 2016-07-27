//http://www.geeksforgeeks.org/count-all-distinct-pairs-formed-by-contiguous-sub-array/

#include<iostream>
#include<set>
using namespace std;

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}



int main()
{
	int n;
	cin>>n;
	int arr[n];
	set <int> st;		
	for(int i=0;i<n;i++)
	{
	cin>>arr[i];
	}
	int count=0,left=0,answer=0;
	for(int i=0;i<n;i++)
	{
		if(st.find(arr[i])!=st.end())
		{
			//cout<<(factorial(n)/factorial(n-2)/factorial(2));
			if(count>=2)			
			answer+=(factorial(count)/factorial(count-2)/factorial(2));
			
			while(st.find(arr[i])!=st.end())
			{
				st.erase(arr[left]);
				left++;
				count--;
			}
			st.insert(arr[i]);
			count++;	
					
		}
		else
		{
		st.insert(arr[i]);
		count++;
		}
		cout<<endl<<"Step:"<<i<<"count="<<count<<"answer="<<answer<<endl;
		cout<<"Set is:->";
		
		set<int>::iterator si;
		for(si=st.begin();si!=st.end();si++)
		{
		cout<<*si<<" ";
		}
		
	}
	if(count>=2)
	answer+=(factorial(count)/factorial(count-2)/factorial(2));
	cout<<endl<<"Answer="<<answer;

return 0;	
}

