#include<iostream>
#include<algorithm>
using namespace std;
int partision(int a[],int low,int high)
{
	int pivot=a[low];
	int i=low+1;
	int j=high;
	while(i<j)
	{
		while(i<=high && a[i]<=pivot)
		i++;
		while(a[j]>pivot)
		 j--;
		if(i<j)
		{
		         	swap(a[i],a[j]);
		}
	}
	swap( a[j], a[low]);
	return j;
}
void quick_sort(int a[],int low,int high)
{
	if(low<high)
	{
		int pi=partision(a,low,high);
		quick_sort(a,low,pi-1);
		quick_sort(a,pi+1,high);
	}
}
void print_array(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	int n,a[10];
	cout<<"Enter n value:";
	cin>>n;
	cout<<"enter the array elements:";
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		cin>>a[i];
	}
	cout<<"The original elements are:";
	print_array( a, n);
	 quick_sort( a, 0,n-1);
	 cout<<"\nThe sorted array:";
	 	print_array( a, n);
	 return 0;
}
