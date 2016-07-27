//Using STL library vector class
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector <int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	cout<<vec.front();
	cout<<vec.back();
	for (;!vec.empty();)
	{
	cout<<vec.back();
	vec.pop_back();
	}

return 0;
}
