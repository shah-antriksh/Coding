//http://www.geeksforgeeks.org/reorder-a-array-according-to-given-indexes/

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n],index[n];

	for (int i=0;i<n;i++)
	cin>>arr[i];

	for (int i=0;i<n;i++)
	cin>>index[i];
	
	int old_val,old_index;
	for (int i=0;i<n;i++)
	{
		while(index[i]!=i)
		{
			old_val = arr[i];
			old_index=index[i];

//			cout<<"old_val"<<old_val<<" old_index"<<old_index<<endl;

			arr[i]=arr[old_index];
			index[i]=index[old_index];

//			cout<<"arr[0]"<<arr[i]<<" index[0]"<<index[i]<<endl;

			arr[old_index]=old_val;
			index[old_index]=old_index;
//			cout<<"arr[old_index]"<<arr[old_index]<<"index[old_index]"<<index[old_index]<<endl;
		}

	}
		
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)
	cout<<index[i]<<" ";

}
