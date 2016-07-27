//MAX HEAP
#include<iostream>
#include<vector>
using namespace std;

vector<int>vec;
int last=0;

void swap(int index,int par)
{
int temp=vec.at(index);
vec.at(index)=vec.at(par);
vec.at(par)=temp;
}

int flc(int index)
{
if((2*index+1)<last)
return (2*index+1);
else
return -1;

}

int frc(int index)
{
if((2*index+2)<last)
return (2*index+2);
else
return -1;
}

int parent(int index)
{
int ret=((index-1)/2);
if (ret>=0)
return ret;
else
return 0;
}

void bottom_top(int index)
{
	int par = parent(index);
	
	if(par==index)
	return;

	if(vec.at(index)>vec.at(par))
	{
		swap(index,par);
		bottom_top(par);
	}
	else
	return;

}

void heapify(int root)
{
	int lc = flc(root);
	int rc = frc(root);
	if(lc!=-1 && rc!=-1)
	{
		if(vec.at(root)<vec.at(lc) || vec.at(root)<vec.at(rc))
		{
			if(vec.at(lc)>vec.at(rc))
			{
				swap(root,lc);
			}
			else
			{
				swap(root,rc);
			}
		
		}
	}
	else if(lc!=-1 && vec.at(root)<vec.at(lc))
	{
		swap(root,lc);
	}
	else if(rc!=-1 && vec.at(root)<vec.at(rc))
	{
		swap(root,rc);
	}
	else
	{
		return;
	}

}

void increase_key(int value,int up)
{
int ind=-1;
	
	for (int i=0;i<last;i++)
	{
		if(vec.at(i)==value)
		{
		ind=i;
		cout<<"Yes"<<ind<<endl;
		break;
		}
	
	}
	if(ind==-1)
	{
		cout<<"Element not found";
	}
	else
	{
		vec.at(ind)+=up;
		bottom_top(ind);
	}
}

void decrease_key(int value,int down)
{
int ind=-1;
	for (int i=0;i<last;i++)
	{
		if(vec.at(i)==value)
		{
		ind=i;
		break;
		}
	}
	if(ind==-1)
	{
		cout<<"Element not found";
	}
	else
	{
		vec.at(ind)-=down;
		cout<<vec.at(ind);
		heapify(ind);
	}

}

void insert(int val)
{
vec.insert(vec.begin()+last,val);
last++;
bottom_top(last-1);
}

void disp()
{
for (int i=0;i<last;i++)
	{
	cout<<i<<":"<<vec[i]<<endl;
	}
}

void extract(int index)
{
	if(last==0)
	{
		cout<<"No element";
		return;
	}
	else
	{
		cout<<vec.at(0);
		last--;
		swap(index,last);
		vec.erase(vec.begin()+last);
		disp();
		cout<<"Last->"<<last;
		if(last>1)
		heapify(0);
		else
		return;
	}
}

void show()
{
cout<<endl<<"1. Insert element";
cout<<endl<<"2. Delete Max element";
cout<<endl<<"3. Increase Key";
cout<<endl<<"4. Decrease key";
cout<<endl<<"5. Show heap";
cout<<endl<<"Enter choice";
}




int main()
{

int choice=0,c1=0;
show();
cin>>choice;

while(choice!=-1)
{
	if(choice == 1)
	{
		cout<<"Enter value to be inserted";
		cin>>choice;
		insert(choice);
	}
	else if(choice == 2)
	{
		extract(0);
	}
	else if (choice == 3)
	{
		cout<<"Enter value";
		cin>>choice;
		cout<<"Enter up value";
		cin>>c1;
		increase_key(choice,c1);
	}
	else if (choice == 4)
	{
		cout<<"Enter value";
		cin>>choice;
		cout<<"Enter down value";
		cin>>c1;
		decrease_key(choice,c1);
	}
	else if (choice == 5)
	{
		disp();
	}
	cout<<endl;
	show();
	cout<<endl;
	cin>>choice;
}

}
