//http://www.geeksforgeeks.org/ugly-numbers/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
long long int ugly[150];
memset (ugly,-1,sizeof(ugly));
int c2=0;
int c3=0;
int c5=0;

long long int nc2,nc3,nc5;
ugly[0]=1;

for (int i=1;i<150;i++)
{
nc2=ugly[c2]*2;
nc3=ugly[c3]*3;
nc5=ugly[c5]*5;

	if(nc2<=nc3 && nc2<=nc5)
	{
		ugly[i]=nc2;
		c2++;
	}
	else if (nc3<=nc2 && nc3<=nc5)
	{
		ugly[i]=nc3;
		c3++;
	}
	else
	{
		ugly[i]=nc5;
		c5++;
	}

}
cout<<ugly[149];
}
