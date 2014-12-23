#include <iostream>

using namespace std;

int THanno[100];


int FourHanno(int n)
{
	if(n==0)return 0;
	if(n==1)return 1;

	int min=50000000;
	for(int k=1;k<n;k++)
	{
		int time=0;
		time+=2*FourHanno(k);
		time+=THanno[n-k];
		if(time<=min)
		{
			min=time;
		}
	}

	return min;
}

int main()
{
	int n;
	cin>>n;

	THanno[0]=0;
	THanno[1]=1;
	for(int i=2;i<=n;i++)
		THanno[i]=2*THanno[i-1]+1;
	
	cout<<FourHanno(n);
}

