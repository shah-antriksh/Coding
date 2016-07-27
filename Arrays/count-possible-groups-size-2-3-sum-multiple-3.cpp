#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	int m0[n],m1[n],m2[n];	
	int i0=0,i1=0,i2=0;

	for (int i=0;i<n;i++)
	{
		cin>>arr[i];
		
		if(arr[i]%3==0)
		{
		m0[i0]=arr[i];
		i0++;
		}		
		
		else if (arr[i]%3==1)
		{
		m1[i1]=arr[i];
		i1++;
		}		
		else
		{
		m2[i2]=arr[i];
		i2++;
		}
	}	

	//SIZE = 2  
	//COMBO = M0 + M0
	for (int i=0;i<i0;i++)
	{
		for(int j=i+1;j<i0;j++)
		{
			cout<<"{"<<m0[i]<<","<<m0[j]<<"}";
		}
	}
	cout<<endl;
	//COMBO = M1 + M2
	for (int i=0;i<i1;i++)
	{
		for(int j=0;j<i2;j++)
		{
			cout<<"{"<<m1[i]<<","<<m2[j]<<"}";
		}
	}
	cout<<endl;
	//COMBO = M0 + M1 + M2
	for (int i=0;i<i0;i++)
	{
		for(int j=0;j<i1;j++)
		{
			for (int k=0;k<i2;k++)
			{
				cout<<"{"<<m0[i]<<","<<m1[j]<<","<<m2[k]<<"}";	
			}
		}
	}
	cout<<endl;
	//COMBO = M0 + M0 + M0
	for (int i=0;i<i0;i++)
	{
		for(int j=i+1;j<i0;j++)
		{
			for (int k=j+1;k<i0;k++)
			{
				cout<<"{"<<m0[i]<<","<<m0[j]<<","<<m0[k]<<"}";	
			}
		}
	}
	cout<<endl;
	//COMBO = M1 + M1 + M1
	for (int i=0;i<i1;i++)
	{
		for(int j=i+1;j<i1;j++)
		{
			for (int k=j+1;k<i1;k++)
			{
				cout<<"{"<<m1[i]<<","<<m1[j]<<","<<m1[k]<<"}";	
			}
		
		}
	}
	cout<<endl;
	//COMBO = M2 + M2 + M2
	for (int i=0;i<i2;i++)
	{
		for(int j=i+1;j<i2;j++)
		{
			for (int k=j+1;k<i2;k++)
			{
				cout<<"{"<<m2[i]<<","<<m2[j]<<","<<m2[k]<<"}";	
			}
		}
	}


	return 0;
}
