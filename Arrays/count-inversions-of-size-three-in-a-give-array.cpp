//http://www.geeksforgeeks.org/count-inversions-of-size-three-in-a-give-array/

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

bool comparator (pair < int, int > a, pair < int, int > b)
{
	if(a.second<b.second)
	return true;
	else
	return false;
}

void convert(int* arr, int* carr, int n)
{
	//pair < pos, value>
	vector < pair <int, int> > vec;
	for(int i=0;i<n;i++)
	vec.push_back(make_pair(i,arr[i]));
	sort(vec.begin(),vec.end(), comparator);
	
	vector < pair <int,int> > ::iterator iter;
	int i=1,pos=0;
	for(iter=vec.begin();iter!=vec.end();iter++)
	{
		pos=(*iter).first;
		carr[pos]=i;
		i++;	
	}
}


int getSum(int* tree, int n, int index)
{
int sum=0;
	while(index>0)
	{
		sum+=tree[index];
		index-=index&(-index);
	}
return sum;
}

int updateTree(int* tree, int n, int index, int value)
{
	while(index<=n)
	{
		tree[index]+=value;
		index+=index&(-index);
	}
}

int main()
{
	int n;
	cin>>n;

	int arr[n],carr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];

	convert(arr,carr,n);
	cout<<endl<<"Converted array-> \n";
	for(int i=0;i<n;i++)
	cout<<carr[i]<<" ";
	cout<<"\n";

	int smaller[n];	
	int tree[n+1]={0};

	for(int i=n-1;i>=0;i--)
	{
		smaller[i]=getSum(tree,n,carr[i]-1);
		updateTree(tree,n,carr[i],1);			
	}
	cout<<"Elements on the right smaller than present"<<endl;
	for(int i=0;i<n;i++)
	cout<<smaller[i]<<" ";
	cout<<endl;

	int bigger[n];
	int tree1[n+1]={0};
	for(int i=0;i<n;i++)
	{
		bigger[i]=i-getSum(tree1,n,carr[i]);
		updateTree(tree1,n,carr[i],1);
	}	
	
	cout<<"Elements on the left bigger than present\n"<<endl;	
	for (int i=0;i<n;i++)
	cout<<bigger[i]<<" ";
	cout<<endl;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=bigger[i]*smaller[i];
	}
	cout<<ans;
}
