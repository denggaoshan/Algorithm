
/*
荷兰国旗问题：设有一个仅由红、白、蓝三种颜色的条块组成的序列。试设计一个时间复杂度为O(n)的算法，使得这些条块按红、白、蓝的顺序排好，即排成荷兰国旗图案。
*/
#include <stdio.h>

#define RED 1
#define WHITE 2
#define BLUE 3

#define MAXSIZE 100

void ColorSort(int array[MAXSIZE],int n)
{
	int red_index = 0;
	int blue_index = n-1;
	int i=0;
	int ret[MAXSIZE];

	for(i=0;i<n;i++)
	{
		if(array[i]==RED)
		{
			ret[red_index] = RED;
			red_index++;
		}

		if(array[i]==BLUE)
		{
			ret[blue_index]=BLUE;
			blue_index--;
		}
	}

	for(i=red_index ; i<=blue_index;i++)
	{
		ret[i] = WHITE;
	}

	printf("排序之后的数组为: \n");

	for(i=0;i<n;i++)
	{
		if(ret[i]==RED)
			printf("RED ");
		if(ret[i]==BLUE)
			printf("BLUE ");
		if(ret[i]==WHITE)
			printf("WHITE ");
	}
}

int main()
{
	int a[12]={RED,BLUE,WHITE,RED,BLUE,WHITE,RED,BLUE,WHITE,RED,BLUE,WHITE};
	ColorSort(a,12);
}