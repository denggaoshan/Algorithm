#include <stdio.h>
#define X 10000  //INFINITY ��
#define n 7  //������

// �ڽӾ����ֵ(Ȩֵ)
int C[n][n] =
{  //	 1  2  3  4  5  6  7
	/*1*/	 X, 19, X, X, 14, X, 18,
	/*2*/	19, X, 5, 7, 12, X, X,
	/*3*/	 X, 5, X, 3, X, X, X,
	/*4*/	 X, 7, 3, X, 8, 21, X,
	/*5*/	14, 12, X, 8, X, X, 16,
	/*6*/	 X, X, X, 21, X, X, 27,
	/*7*/	18, X, X, X, 16, 27, X
};

void prim(int v, int tree[][3])
{
	int i, j, k, q, min, closest[n], lowcost[n] = { 0 };
	//��ֵ
	for (i = 0; i < n; ++i)
	{
		closest[i] = v;
		lowcost[i] = C[v][i];
	}

	//�ӵ�
	q = 0;
	for (i = 0; i < n - 1; ++i)
	{
		//���Ҽ�������������һ������k
		min = X;
		for (j = 1; j < n; ++j)
		if (lowcost[j] && lowcost[j] < min)
		{
			min = lowcost[j];
			k = j;
		}
		tree[q][0] = closest[k];
		tree[q][1] = k;
		tree[q][2] = min;
		q++;

		//������k����U�������޸���С��ֵ
		lowcost[k] = 0;
		for (j = 0; j < n; ++j)
		if (C[k][j] < lowcost[j])
		{
			lowcost[j] = C[k][j];
			closest[j] = k;
		}
	}
} // �㷨��ʱ�临�Ӷ�ΪO(n*n)

void main()
{
	int tree[n][3];
	prim(0, tree);
	printf("Minimum-cost spanning tree(prim):\n\n");
	printf("vertexs\tweight\t\n");
	for (int i = 0; i < n - 1; ++i)
		printf(" v%d-v%d\t  %d\n", tree[i][0] + 1, tree[i][1] + 1, tree[i][2]);
	printf("\n");
}
// Prim�㷨����

