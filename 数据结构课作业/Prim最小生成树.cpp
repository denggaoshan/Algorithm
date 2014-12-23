#include <stdio.h>
#define X 10000  //INFINITY ∞
#define n 7  //顶点数

// 邻接矩阵初值(权值)
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
	//初值
	for (i = 0; i < n; ++i)
	{
		closest[i] = v;
		lowcost[i] = C[v][i];
	}

	//加点
	q = 0;
	for (i = 0; i < n - 1; ++i)
	{
		//查找加入生成树的下一个顶点k
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

		//将顶点k并入U集，并修改最小边值
		lowcost[k] = 0;
		for (j = 0; j < n; ++j)
		if (C[k][j] < lowcost[j])
		{
			lowcost[j] = C[k][j];
			closest[j] = k;
		}
	}
} // 算法的时间复杂度为O(n*n)

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
// Prim算法结束

