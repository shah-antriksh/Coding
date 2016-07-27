//http://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/

#include<iostream>
using namespace std;

int main()
{
int n=0,k=0;
cin>>n>>k;
n++;
int mat[n+1][n+1];
fill(&mat[0][0],&mat[0][0]+(n+1)*(n+1),1);
mat[1][1]=1;
for (int i=1;i<=n;i++)
{
	for(int j=1;j<=i;j++)
	{
		if(j==1||j==i)
		mat[i][j]=1;
		else
		mat[i][j]=mat[i-1][j-1]+mat[i-1][j];
	}
}

for(int i=1;i<=n;i++)
{
	for(int j=1;j<=i;j++)
	cout<<mat[i][j]<<" ";
	cout<<endl;
}
return 0;
}
