//http://www.geeksforgeeks.org/pair-with-given-product-set-1-find-if-any-pair-exists/

#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
	int n,no,element;
	unordered_set<int> st;
	bool flag=false;
	cin>>n>>no;

	for (int i=0;i<n;i++)
	{
		cin>>element;	
		
		if(element==0 && no ==0)
		{
		flag = true;
		break;
		}

		if(no%element!=0)
			continue;
		else
		{
			if (st.find(no/element) !=st.end())
			{
				flag = true;
				break;
			}
			else
			st.insert(element);
		}
	}
	if(flag==true)
	cout<<"Yes";
	else
	cout<<"No";

	return 0;
}
