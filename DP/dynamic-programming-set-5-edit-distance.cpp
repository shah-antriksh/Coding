//http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
#include<iostream>
#include<string>
using namespace std;

int min(int a, int b,int c)
{
if(a<b && a<c)
return a;

if(b<a && b<c)
return b;

if(c<a && c<b)
return c;
}
int main()
{
	string a,b;
	cin>>a>>b;
	int al=a.length(),bl=b.length();
	int arr[al+1][bl+1];
	
	for (int i=0;i<=al;i++)
	{
		for (int j=0;j<=bl;j++)
		{
			if(i==0)
			{
				arr[i][j]=j;
			}	
			else if(j==0)
			{
				arr[i][j]=i;
			}
			else if (a[i-1]==b[j-1])
			{
				arr[i][j]=arr[i-1][j-1];
			}
			else
			{
				arr[i][j]=1+ min(arr[i][j-1],arr[i-1][j],arr[i-1][j-1]);
			}
		}

	}

	for (int i=0;i<=al;i++)
	{
		for (int j=0;j<=bl;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<arr[al][bl];

}

