#include<iostream>
using namespace std;
int Binary_Search(int a[],int key,int low,int high)
{
	if(low>high)
	{
		return -1;
	}
	int mid=(low+high)/2;
	if(key==a[mid])
	{
		return mid;
	}
	else if(key > a[mid] )
	{
			return Binary_Search(a, key, mid+1, high);
	}
	else
	{
		return 	Binary_Search(a, key,low, mid-1);
	}
}
int main()
{
	int n,a[10],key;
	cout<<"Enter the n value:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter the element:";
		cin>>a[i];
	}
	cout<<"Enter the value to search:";
	cin>>key;
	int result=Binary_Search(a, key,0, n-1);
	if(result!=-1)
	{
		cout<<"The element is found at:"<<result;
	}
	else
	{
		cout<<"The element is not found";
	}
	return 0;
}
