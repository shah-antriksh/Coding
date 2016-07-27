//http://www.geeksforgeeks.org/dynamic-programming-set-17-palindrome-partitioning/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{

string temp;
cin>>temp;
string str="0"+temp;
int len=temp.length();

int arr[len+1][len+1];
fill(&arr[0][0],&arr[0][0]+(len+1)*(len+1),0);

for(int l=0;l<=len;l++)
{
	for(int i=1;i<=len-l;i++)
	{
		int j=i+l;
		if(i==j)
		{
			arr[i][i]=1;
			continue;
		}
		if(str[i]==str[j])
		{
			if(l==1)
			arr[i][j]=1;
			else if(arr[i+1][j-1]==1)
			{
				//Yes it is palindrome
				arr[i][j]=1;
			}	
		}
	}
}

int c[len+1];
fill(&c[0],&c[0]+(len+1),INT_MAX);

for(int i=1;i<=len;i++)
{
	for(int j=1;j<=i;j++)
	{
		if(arr[1][i]==1)
		c[i]=0;
		else
		{
			if(arr[j][i]==1)
			{
				c[i]=min(c[i],1+c[j-1]);
			}	
		}
	}
	cout<<"i->"<<i<<" "<<c[i]<<" ";

}

cout<<"Answer->"<<c[len]<<endl;

for(int i=1;i<=len;i++)
{
	for(int j=1;j<=len;j++)	
	{
		cout<<arr[i][j]<<" ";
	}
	cout<<endl;	
}	


return 0;
}

/*
abcd
*/
