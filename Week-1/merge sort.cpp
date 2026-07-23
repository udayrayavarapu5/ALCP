#include<iostream>
using namespace std;
void merge(int a[],int low,int high)
{
    int b[10];
    int k=low;
    int l[10];
    int r[10];
    int mid=(low+high)/2;
	for(int i=low;i<=mid;i++)
	  l[i]=a[i];
	for(int j = mid+1;j<=high;j++)
	  r[j]=a[j];
	int i=low;
	int j= mid+1;
	while(i<=mid && j <=high)
	{
		if(l[i]<r[j])
		{
			b[k]=l[i];
			i++;
		}
		else
		{
			b[k]=r[j];
			j++;
		}
		k++;
	}
	while(i<= mid)
	{
		b[k]=l[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		b[k]=r[j];
		j++;
		k++;
	}
	for(int i=low ;i<=high;i++)
	{
		a[i]=b[i];
	}
}
void merge_sort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,high);
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
	cout<<"Enter the array elements:";
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		cin>>a[i];
	}
	cout<<"The original array:";
	print_array(a, n);
	merge_sort( a, 0,n-1);
	cout<<"\nThe sorted array:";
	print_array(a, n);
}
