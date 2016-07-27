
#include<iostream>
using namespace std;

int main()
{

int noa=0;
cin>>noa;
int dim[noa+1];
for (int i=0;i<=noa;i++)
cin>>dim[i];

int mat[noa+1][noa+1];
fill(&mat[0][0],&mat[0][0]+(noa+1)*(noa+1),0);
for(int i=1;i<noa;i++)
{
	mat[i][i]=0;
	mat[i][i+1]=dim[i-1]*dim[i]*dim[i+1];
}

for (int l=2;l<noa+1;l++)
{
	for(int i=1;i<noa-l+1;i++)
	{
		int j=i+l;
		mat[i][j]=min(mat[i][j-1]+dim[0]*dim[j-1]*dim[j],mat[i+1][j]+dim[0]*dim[1]*dim[j]);
	}
}

for (int i=0;i<=noa;i++)
{
	for (int j=0;j<=noa;j++)
	{
		cout<<mat[i][j]<<" ";
	}	
	cout<<endl;
}

}
