#include<stdio.h>
#include<stdlib.h>
#include <memory.h>
#include<math.h>
#include <limits.h>

#define INFINITY INT_MAX

void TreeSelectionSort(int data[],int n)
{
	int answer[100];
	int deep = log2((double)n) + 2; //计算树高
	int size = pow(2.0, deep) - 1;  //计算总共的空间
	int i,j;
	int now = 1;
	int* tmp = (int *)malloc(sizeof(size)+1);
	
	for (i = 0; i <= (int)pow(2.0, deep - 1) - 1; i++)
	{
		tmp[i] = INFINITY;
	}

	for (j = 1; j <= n; i++, j++)
	{
		tmp[i] = data[j];
	}

	while (i <= size)
	{
		tmp[i] = INFINITY;
		i++;
	}

	while (now<=n)
	{
	
		for (i = size; i>1; i -= 2)
		{
			if (tmp[i] < tmp[i - 1])
			{
				tmp[i / 2] = tmp[i];
			}
			else
			{
				tmp[i / 2] = tmp[i - 1];
			}
		}

		answer[now] = tmp[1];
		int k=i;
		int key = tmp[1];
		for (i = 1; i < (int)pow(2.0, deep - 1) - 1 ;)
		{
			if (tmp[i * 2] == key)
			{
				i = i * 2;
			}
			else
			{
				i = i * 2 + 1;
			}
		}

		tmp[i] = INFINITY; //置为无穷大
		now++;
	}
	
	for (i = 1; i <= n;i++)
	printf("%d ", answer[i]);
}

int main()
{
	int data[] = {0,3,5,4,2,1};
	printf("排序\n");
	TreeSelectionSort(data, 5);
	return 0;
}