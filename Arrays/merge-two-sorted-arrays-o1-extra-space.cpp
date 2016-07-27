#include<iostream>
using namespace std;

int swap(int *a1,int *a2)
{
	int temp;
	temp=*a1;
	*a1=*a2;
	*a2=temp;
}

int main()
{

	int n1,n2;
	cin>>n1>>n2;
	int a1[n1],a2[n2];

	for(int i=0;i<n1;i++)
		cin>>a1[i];

	for(int i=0;i<n2;i++)
		cin>>a2[i];

	int l1=0,l2=0;
	
	while(l1<n1 && l2<n2)
	{
		if(a1[l1]==a2[l2])
		l1++;
		
		else if(a1[l1]>a2[l2])
		{
			swap(a1[l1],a2[l2]);
			while(a2[l2]>a2[l2+1] && l2+1<n2)
			{
			swap(a2[l2],a2[l2+1]);			
			l2++;
			}
			while(a2[l2]>a1[l1] && l2>0)
			l2--;	
		
		}
		
		else
		{
			l1++;
		}	
	//cout<<l1<<l2;
	}
	
	for(int i=0;i<n1;i++)
	cout<<a1[i]<<" ";

	cout<<endl;	

	for(int i=0;i<n2;i++)
	cout<<a2[i]<<" ";

return 0;
}
