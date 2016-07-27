//http://www.geeksforgeeks.org/dynamic-programming-set-18-word-wrap/

#include<bits/stdc++.h>
using namespace std;

int main()
{
int n,wl;
cin>>n>>wl;
string str[n+1];

for(int i=1;i<=n;i++)
{
	cin>>str[i];
}

int mat[n+1][n+1];
fill(&mat[0][0],&mat[0][0]+(n+1)*(n+1),-1);

for (int i=1;i<=n;i++)
{
int rem=wl;

	for(int j=i;j<=n;j++)
	{
		if(str[j].length()<=rem)
		{
			mat[i][j]=(rem-str[j].length())*(rem-str[j].length());
			rem-=(str[j].length());
			rem-=1;			
		}
		if(rem<=0)
		break;
	}
}

int cost[n+1],bk[n+1];
fill(&cost[0],&cost[0]+(n+1),99999);
memset(bk,sizeof(bk),0);
cost[0]=0;

for (int j=1;j<=n;j++)
{
	for(int i=1;i<=j;i++)
	{
		if(mat[i][j]!=-1 && cost[i-1]+mat[i][j]<cost[i])
		{
			cost[j]=cost[i-1]+mat[i][j];
			bk[j]=i;
		}
	}

}

for (int i=1;i<=n;i++)
{
	cout<<bk[i]<<" ";
}
cout<<endl;
int ln=1;
for(int i=1;i<=n;i++)
{
	if(bk[i]>ln)
	{
		ln=bk[i];
		cout<<endl<<str[i]<<" ";
	}
	else
	{
		cout<<str[i]<<" ";
	}
}

cout<<endl;
for(int i=1;i<=n;i++)
{
	for(int j=i;j<=n;j++)
	{
		cout<<mat[i][j]<<" ";
	}
	cout<<endl;
}
return 0;
}


/*
9 10
antriksh shah
likes coding
HE is a goodyaz boy

*/
