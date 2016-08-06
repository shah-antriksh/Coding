//http://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/

#include<bits/stdc++.h>
using namespace std;

int main()
{

int n;
cin>>n;
int arr[n];
int i=0;
while(cin>>arr[i])
{
i++;
}

int incl=arr[0];
int excl=0;
int ans=0;

for (i=1;i<n;i++)
{
	int prev_incl = incl;
	int prev_excl= excl;
	incl=max(prev_excl+arr[i],arr[i]);
	excl=max(prev_excl,prev_incl);
}
cout<<endl<<max(incl,excl);
}

//6 5 5 10 100 10 5
//5 -1 -2 -3 -4 7
//6 -1 7 -11 -15 19 12
//3 -1 -2 -3

