//http://www.geeksforgeeks.org/absolute-distinct-count-array-sorted-absolute-values/

#include<iostream>
#include<set>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{
set <int> st;
int n,temp;
cin>>n;

for(int i=0;i<n;i++)
{
cin>>temp;
st.insert(abs(temp));
}

cout<<st.size();

}
