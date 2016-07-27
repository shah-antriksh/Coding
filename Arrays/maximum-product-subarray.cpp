//http://www.geeksforgeeks.org/maximum-product-subarray/

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];

	for (int i=0;i<n;i++)
	cin>>arr[i];

	int l=0;
	int max_neg=-9999,min_pos=9999,prod=1,max_prod=arr[0];;

	while(l<n)
	{
		prod=1;
		while(l<n && arr[l]!=0)
		{
			if(arr[l]>=0 && arr[l]<min_pos)
			min_pos=arr[l];

			if(arr[l]<0 && arr[l]>max_neg)
			max_neg=arr[l];
		
			prod*=arr[l];
			l++;	 
		}
		if(prod<0)
		prod/=max_neg;

		max_prod=max(max_prod,prod);
		l++;
	}

	cout<<max_prod;
	return 0;
}
