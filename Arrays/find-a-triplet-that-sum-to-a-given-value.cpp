//http://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/

#include<bits/stdc++.h>
using namespace std;

bool find_value(int i, int j, int rs, vector<int>vec)
{
	cout<<i<<" "<<j<<endl;
	if(i==j && vec[i]==rs)
	{

		return true;
	}
	if(i>j)
		return false;
	
	int mid=(i+j)/2;

	if(vec[mid]==rs)
		return true;
	cout<<"mid"<<mid;
	if(vec[mid]>rs)
	{
		find_value(0,mid-1,rs,vec);
	}
	else
	{
		find_value(mid+1,j,rs,vec);
	}

}

int main()
{
	vector<int>vec;
	int element;
	int sum=0;
	cin>>sum;
	bool status;

	while(cin>>element)
	{
	vec.push_back(element);
	}
	
	vector<int>vcc;
	for(int i=0;i<vec.size();i++)
	{
		for(int j=i+1;j<vec.size();j++)
		{
			vcc.push_back(vec[i]+vec[j]);
		}
	}

	sort(vec.begin(),vec.end());
	sort(vcc.begin(),vcc.end());
	for (int i=0;i<vcc.size();i++)
	{	
		cout<<vcc[i]<<" ";
	}	
	

	for (int i=0;i<vec.size();i++)
	{
	int ts=vec[i];
	int rs= sum-ts;
	status = find_value(0,vcc.size()-1,rs,vcc);
	}

	if (status==true)
	cout<<"yes";
	else
	cout<<"no";
}
/*
24 12 3 4 1 6 9
*/
/*
15 1 3 5 9 10
*/
