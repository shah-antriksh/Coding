
#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
using namespace std;

struct min_s
{
	bool operator()(int a,int b)
	{
		if (a>b)
		return true;
		else
		return false;
		
	}
};

int main()
{

priority_queue<int, vector<int>, min_s> MH;

MH.push(7);
MH.push(5);
MH.push(6);
cout<<MH.top();MH.pop();
cout<<MH.top();MH.pop();
cout<<MH.top();MH.pop();
return 0;
}
