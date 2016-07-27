//http://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/

#include<iostream>
using namespace std;

int main()
{
int n,k;
cin>>n>>k;
int arr[k+1]={0};
arr[0]=1;

for(int i=1;i<=n;i++)
{
	for(int j=min(i,k);j>0;j--)
	{
			arr[j]=arr[j]+arr[j-1];
			cout<<arr[j];
	}	
	cout<<endl;
}

cout<<arr[k];


}
