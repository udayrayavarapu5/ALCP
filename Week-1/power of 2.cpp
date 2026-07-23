#include<iostream>
using namespace std;
void power_of_2(int n)
{
	if(n>0 && (n& (n-1))==0)
	{
		cout<<"Number is the power of 2";
	}
	else 
	 {
	 	cout<<"Number is not power of 2";
	 }
}
int main()
{
	int n;
	cout<<"Enter the n value:";
	cin>>n;
	power_of_2( n);
	return 0;
}
