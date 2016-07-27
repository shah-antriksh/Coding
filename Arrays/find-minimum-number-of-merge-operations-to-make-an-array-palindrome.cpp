#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	int flag=0;
	for (int i=0;i<n;i++)
	{
	cin>>arr[i];
	}
	int left=0,right=n-1,merge=0;

	while(left<=right)
	{
		if(left==right)
			break;

		else if(arr[left]==arr[right])
		{
			left++;
			right--;
		}
		
		else
		{
			int lsum=arr[left],rsum=arr[right];
			while(true)
			{
				if(lsum<rsum)
				{				
				left++;
				lsum+=arr[left];
				merge++;
				}				
				else if(lsum>rsum)
				{
				right--;
				rsum+=arr[right];
				merge++;
				}
				else
				break;

				if(left>=right)
				{
					flag=1;
					break;
				}
			
				else if(lsum==rsum)
				{
				left++;
				right--;
				}			
			}

		}
		
		if(flag==1)
		break;

	}

cout<<merge;	
return 0;
}
