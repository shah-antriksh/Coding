//http://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/

#include<iostream>
#include<string>
using namespace std;


int mat[1000][1000];

int fpl(int i,int j,string str)
{
cout<<i<<j<<endl;
	if(str[i]==str[j])
	{
		if(j-i!=0)
		{
			if(mat[i+1][j-1]==0)
			{
				mat[i][j]=2+fpl(i+1,j-1,str);
				return mat[i][j];
			}
			else
			{
				mat[i][j]=2+mat[i-1][j-1];
				return mat[i][j];
			}
			
		}
		else
		{
			mat[i][i]=1;
			return 1;
		}
	}
	else
	{
		int a=0,b=0;
		if(mat[i+1][j]!=0)
		a=mat[i+1][j];
		else
		a=fpl(i+1,j,str);

		if(mat[i][j-1]!=0)
		b=mat[i][j-1];
		else
		b=fpl(i,j-1,str);
		
		mat[i][j]=max (a,b) ;
		return mat[i][j];
	}

}

int main()
{
string temp;
cin>>temp;
string str="0"+temp;
int len=temp.length();

//fill(&mat[0][0],&mat[0][0]+(len+1)*(len+1),-1);
len=fpl(1,len,str);
cout<<len;
return 0;
}
