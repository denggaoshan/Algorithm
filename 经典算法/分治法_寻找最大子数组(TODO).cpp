#include <stdio.h>
#include <limits>

void Find_Max_Crossing_Subarray(int a[],int begin,int mid,int end,int &left,int &right,int &arraymax)
{
	int ileft = mid;
	int max = INT_MIN;
	int sum = 0 ;
	int i = ileft;
	arraymax = 0 ;
	while(i >=0)
	{
		sum += a[i];
		if(sum > max)
		{
			max = sum;
			ileft = i;
		}
		i--;
	}
	sum = 0;
	arraymax += max;
	max = INT_MAX;
	int iright = mid +1 ;
	int j = iright;
	while(j <= end){
		sum+=a[j];
		if(sum > max)
		{
			max = sum;
			iright = j;
		}
	}
	arraymax += max;
	left = ileft;
	right = iright;
	return ;
}

void Find_Maximum_Subarray(int a[],int begin,int end)
{
		int left,mid,right;
		int mid = begin + (end - begin)/2 ;
		left = Find_Maximum_Subarray(a,begin, mid );

}