#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int INFINITY = 100000000;
const int MaxV = 1000;

//邻接点
typedef struct ANode{
	int AdjV;//在顺序表中的位置
	int WN;  //权值
	struct ANode *next;
}*AdjLink;

//顶点
typedef struct
{
	char data;
	AdjLink HAdjV; //邻接点链表头指针;
}VNode;


//邻接图 
typedef struct
{
	VNode vNode[MaxV];
	int vexs[MaxV];
	int vexnum, arcnum; //顶点数，边数
}AdjLGraph;

AdjLGraph adjLGraph; //邻接图 

void streaminit()
{
	freopen("C:/Users/Administrator/Desktop/data.txt","r",stdin);
}


//向顶点添加一个邻接点
void AddVNode(VNode *vex,int AdjV,int weight)
{
	AdjLink linkTmp = NULL, newLink;
	
	if (vex->HAdjV==NULL)
	{
		newLink = (AdjLink)malloc(sizeof(ANode));
		newLink->WN = weight;
		newLink->next = NULL;
		newLink->AdjV = AdjV;
		vex->HAdjV = newLink;
	}
	else{
		linkTmp = vex->HAdjV;
		while (linkTmp->next != NULL)linkTmp = linkTmp->next;
		newLink = (AdjLink)malloc(sizeof(ANode));
		newLink->WN = weight;
		newLink->next = NULL;
		newLink->AdjV = AdjV;
		linkTmp->next = newLink;
	}

}

void CreateAdjGrahp()
{
	int i;
	int addi, addj, addweight;
	scanf("%d %d",&adjLGraph.vexnum,&adjLGraph.arcnum);//读入顶点数，边数
	
	for (i = 1; i <= adjLGraph.vexnum; i++)
	{
		scanf("%c", &adjLGraph.vNode[i].data);
		if (adjLGraph.vNode[i].data == '\n')
		{
			i--; continue;
		}
		adjLGraph.vNode[i].HAdjV = NULL;
	}

	for (i = 1; i <= adjLGraph.arcnum; i++)
	{
		scanf("%d %d %d", &addi, &addj, &addweight);
		AddVNode(&adjLGraph.vNode[addi], addj, addweight);
		AddVNode(&adjLGraph.vNode[addj], addi, addweight);
	}
	
}

//对结点访问:输出
void Visit(int i)
{
	printf("访问：%c\n", adjLGraph.vNode[i].data);
}

//查找是否有邻接点
int IfInclude(int nowvisit,int i)
{
	AdjLink linktmp = adjLGraph.vNode[nowvisit].HAdjV;
	while (linktmp != NULL)
	{
		if (linktmp->AdjV == i)
			return 1;
		linktmp = linktmp->next;
	}
	return 0;
}

int ifVisit[MaxV + 1];

void DFS(int nowvisit)
{
	int i;
	
	ifVisit[nowvisit] = 1;//标记为已访问
	Visit(nowvisit);

	for (i = 1; i < adjLGraph.arcnum; i++)
	{
		if (!ifVisit[i] && IfInclude(nowvisit,i))
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
		
		for (i = 1; i <= adjLGraph.vexnum; i++)
		{
			if (!ifVisit[i] && IfInclude(nowPos,i))
			{
				Visit(i);
				ifVisit[i] = 1;
				EnQueue(&q, i);
			}
		}
	}
	
}

int main()
{
	streaminit();
	CreateAdjGrahp();
	printf("DFS:\n");
	DFS_Visit();
	printf("BFS:\n");
	BFS_Visit();
}