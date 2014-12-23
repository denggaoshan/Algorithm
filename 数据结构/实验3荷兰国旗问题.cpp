
/*
�����������⣺����һ�����ɺ졢�ס���������ɫ��������ɵ����С������һ��ʱ�临�Ӷ�ΪO(n)���㷨��ʹ����Щ���鰴�졢�ס�����˳���źã����ųɺ�������ͼ����
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

	printf("����֮�������Ϊ: \n");

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