#include <stdio.h>


//������ i~n ����i+1~n��һ�������Ķѣ�iλ�ò���
void HeapAdjust(int data[],int i,int n)
{
	int j;
	int temp =data[i];
	for (j = 2 * i; j <= n; j *= 2)
	{
		if (j < n&&data[j] < data[j + 1])
			++j;
		if (temp >= data[j])
			break;
		data[i] = data[j];
		i = j;
	}
	data[i] = temp;
}

//������
void HeapSort(int data[], int n)
{
	int i;
	for (i = n / 2; i > 0; i--)
		HeapAdjust(data,i,n);

	for (i = n; i > 1; i--)
	{
		int tmp = data[i];
		data[i] = data[1];
		data[1] = tmp;
		HeapAdjust(data,1,i-1);
	}
}

int main()
{
	int data[] = {0,3,5,1,2,4,7,0,10,8};
	HeapSort(data, 9);
}