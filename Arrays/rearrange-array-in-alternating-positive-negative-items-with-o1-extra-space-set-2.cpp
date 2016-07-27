#include<iostream>
using namespace std;

void swap(int*a1,int*a2)
{
int *temp;
temp=a1;
a1=a2;
a2=temp;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	int flag=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	int right=0;

	for(int i=0;i<n-1;i++)
	{
		//cout<<"i:"<<i<<endl;
		if(arr[i]>=0 && arr[i+1]>=0)
		{
			right=n-1;
			while(i<=right)
			{
				if(i==right)
				{
					flag=1;
					break;
				}
		
				if(arr[right]>=0)
					right--;

				else
				{
					//cout<<arr[i]<" "<<arr[right]<<endl;
					swap(arr[i+1],arr[right]);
					//cout<<arr[i]<" "<<arr[right]<<endl;						
					break;
				}
			}
		}
	
		else if (arr[i]<0 && arr[i+1]<0)
		{
			right=n-1;
			while(i<=right)
			{
				if(i==right)
				{
					flag=1;
					break;
				}
				if(arr[right]<0)
					right--;

				else
				{
					swap(arr[i+1],arr[right]);
					break;
				}
			}
		}
	
		else
		continue;

		if(flag==1)
		{
		//cout<<"Complete"<<endl;
		break;
		}
		/*	
		cout<<endl<<"------------------*****------------------"<<endl;
		for(int i=0;i<n;i++)
		{	
			cout<<arr[i]<<" ";
		}
		cout<<endl<<"------------------*****------------------"<<endl;	
		*/		
	}
	
	for(int i=0;i<n;i++)
	{	
		cout<<arr[i]<<" ";
	}

}
