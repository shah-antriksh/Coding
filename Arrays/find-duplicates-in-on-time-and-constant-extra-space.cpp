#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for (int i=0;i<n;i++)
	cin>>arr[i];

	int temp;
	for(int i=0;i<n;i++)
	{
		int l=i;
		while ( l!=arr[l])
		{
			if(arr[arr[l]]==arr[l])
			{
			cout<<"YES"<<arr[l];
			return 0;
			}		
			else	
			{	
			temp=arr[arr[l]];
			arr[arr[l]]=arr[l];
			arr[l]=temp;
			}
		}
	}	
	cout<<"no";
	return 0;
}
