//http://www.geeksforgeeks.org/dynamic-programming-set-1/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int arr[100];
int calc=0;
int fibo(int n)
{
	if(arr[n]==-1)
	{
		arr[n]=fibo(n-1)+fibo(n-2);
		calc++;	
	}
	else
	{
		return arr[n];
	}
return arr[n];
}

int main()
{
	memset(arr,-1,sizeof(arr));
	arr[0]=0;
	arr[1]=1;
	int n;
	cin>>n;
	n = fibo(n);
	cout<<n;
	cout<<"Calc"<<calc;
}
