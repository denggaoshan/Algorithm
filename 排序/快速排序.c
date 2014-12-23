
#include <stdio.h>

int split(int x[],int first,int last)
{
	int split_point,pivot;
	int unknown,tmp;
	pivot = x[first];
	split_point = first;
	
	for(unknown = first+1 ; unknown <=last ; unknown++)
	{
		if(x[unknown] < pivot)
		{
			split_point++;
			tmp = x[split_point];
			x[split_point] = x[unknown];
			x[unknown] = tmp;
		}
	}
		x[first] = x[split_point];
		x[split_point] = pivot;
		return split_point;
	
}

void quick_sort(int x[],int first,int last)
{
	if(first<last)
	{
		int split_point;
		split_point = split(x,first,last);
		quick_sort(x,first,split_point - 1);
		quick_sort(x,split_point+1,last);
	}
}



int main(int argc,char *argv[])
{
	int i = 0;

	int a[10]={4,2,1,3,9,0,8,5,7,6};
	quick_sort(a,0,9);

	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	getchar();
}
