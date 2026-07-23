#include<iostream>
using namespace std;
int Sum(int n)
{
	int s=0;
	for(int i=0;i<=n;i++)
	{
		s=s+i;
	}
	return s;
}
void average(int n)
{
	int s=Sum(n);
	float avg=(s)/n;
	cout<<"The avg:"<<avg;
}
int main()
{
	int n;
	cout<<"Enter n value:";	
	cin>>n;
    average(n);
	return 0;
}
