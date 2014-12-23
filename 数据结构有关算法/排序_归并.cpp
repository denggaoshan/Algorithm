/*
*	归并排序
*	注意 OBOB 特别恶心~~
*/
#include <stdio.h>
#include <limits>

#define N 100

void Merge(int a[N] , int begin ,int mid , int end){
	int left[N];
	int right[N];
	int i,j; 
	for( i=0;i<=mid-begin;i++){
		left[i] = a[begin + i];
	}
	left[i] = INT_MAX; 
	for( i = 0; i < end-mid ;i++){
		right[i] = a[mid + 1 + i];
	}
	right[i] = INT_MAX;
	int k;
	i=j=k=0;
	for(k=0;k< end-begin +1 ; k++)
	{
		if(left[i]<=right[j])
		{
			a[begin + k] = left[i];
			i++;
		}else{
			a[begin + k] = right[j];
			j++;
		}
	}
}

void MergeSort(int a[N],int begin,int end){
	if(end - begin <= 0 )
	{
		return ;
	}
	int mid = begin + (end - begin)/2;
	MergeSort(a,begin,mid);
	MergeSort(a,mid+1,end);
	Merge(a,begin,mid,end);
}

int main()
{
	int a[N]={4,6,1,2,8,4,7,1,10,42,3,5,1,2};//14
	MergeSort(a,0,13);
	for(int i=0;i<14;i++)
		printf("%d ",a[i]);
	return 0;
}