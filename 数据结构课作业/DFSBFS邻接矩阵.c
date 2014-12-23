
#include <stdio.h>
#include <memory.h>

const int INFINITY = 100000000;
const int MaxV = 1000;

typedef struct
{
	char vexs[MaxV + 1];  //顶点信息
	int arcs[MaxV + 1][MaxV + 1];  //邻接矩阵
	int vexnum, arcnum;  //顶点数,弧(边)数
} AdjGraph;


AdjGraph adjGraph;

void CreateAdjGrahp()
{
	int i;
	int addi, addj, addweight;
	scanf("%d %d", &adjGraph.vexnum, &adjGraph.arcnum);
	for (i = 1; i <= adjGraph.vexnum; i++)
	{
		scanf("%c", &adjGraph.vexs[i]);
		if (adjGraph.vexs[i] == '\n')
		{
			i--;
		}
	}
	memset(adjGraph.arcs, INFINITY, sizeof(adjGraph.arcs));

	for (i = 1; i <= adjGraph.arcnum; i++)
	{
		scanf("%d %d %d", &addi, &addj, &addweight);
		adjGraph.arcs[addi][addj] = addweight;
		adjGraph.arcs[addj][addi] = addweight;
	}

}

//对结点访问:输出
void Visit(int i)
{
	printf("访问：%c\n", adjGraph.vexs[i]);
}

int ifVisit[MaxV + 1];

void DFS(int nowvisit)
{
	int i;
	
	ifVisit[nowvisit] = 1;//标记为已访问
	Visit(nowvisit);

	for (i = 1; i < adjGraph.arcnum; i++)
	{
		if (!ifVisit[i] && adjGraph.arcs[nowvisit][i] != 0)
		{
			DFS(i);
		}
	}
}



void DFS_Visit()
{
	memset(ifVisit, 0, sizeof(ifVisit));
	DFS(1);
}

//实现简易队列
typedef struct{
	int front;
	int rail;
	int data[MaxV];
}Queue;

//入队
void EnQueue(Queue *q,int e)
{
	(*q).data[(*q).rail] = e;
	(*q).rail++;
}
//出队
int OutQueue(Queue *q)
{
	return (*q).data[(*q).front++];
}

int QueueEmpty(Queue q)
{
	if (q.front == q.rail)
		return 1;
	return 0;
}

void InitQueue(Queue *q)
{
	memset(q, 0, sizeof(Queue));
	(*q).front = 0;
	(*q).rail = 0;
}


void BFS_Visit()
{
	Queue q;
	int i, j;
	int nowPos;
	InitQueue(&q);
	memset(ifVisit, 0, sizeof(ifVisit));
	ifVisit[1] = 1; //标记第一个结点已经访问
	Visit(1);
	EnQueue(&q, 1);
	while (!QueueEmpty(q))
	{
		nowPos = OutQueue(&q);
		
		for (i = 1; i <= adjGraph.vexnum; i++)
		{
			if (!ifVisit[i] && adjGraph.arcs[nowPos][i] != 0)
			{
				Visit(i);
				ifVisit[i] = 1;
				EnQueue(&q, i);
			}
		}
	}
	
}

void streaminit()
{
	freopen("C:/Users/Administrator/Desktop/data.txt","r",stdin);
}

//data.txt
/*
6 9
abcdef
1 2 6
1 3 2
1 5 5
2 4 3
2 6 5
5 6 6
3 5 4
3 4 2
4 6 3
*/

int main()
{
	streaminit();
	CreateAdjGrahp();
	printf("DFS:\n");
	DFS_Visit();
	printf("BFS:\n");
	BFS_Visit();
}