#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define VertexNum 100

// 邻接表存储结构
typedef struct ANode
{
	int AdjV; //邻接点在顺序表中的位置
	int weight;	//存储距离权值
	struct ANode *next; //指向下一个邻接点
} *AdjLink;

// 表头指针结构
typedef struct
{
	int data;
	AdjLink HAdjV; //邻接点链表头指针
} VNode;

VNode AdjL[VertexNum];

int Vn, En;

// 通过输入“边”建立图的邻接表存储结构
void GraphAdjCreate()
{
	// 邻接表初始化
	FILE *fp = fopen("data.txt", "r");  //打开数据文件
	if (fp == NULL)return;
	fscanf(fp, "%d %d", &Vn, &En);  //读取顶点数和边数
	if (Vn > VertexNum) Vn = VertexNum;
	fscanf(fp, "%c");  //跳过换行符
	printf("\nVn=%d, En=%d\n", Vn, En);

	// 建立邻接表存储结构
	for (int k = 1; k <= Vn; k++) AdjL[k].data = k;
	int j1 = 0, j2 = 0; //顶点序号和权值
	int weight;//边的权值
	AdjLink p, q;
	for (int k = 0; k < En; k++)
	{
		fscanf(fp, "%c,%c,%d", &j1, &j2,&weight);  //读取弧
		fscanf(fp, "%c");//跳过换行
		j1 -= 'a';//转换成编号
		j2 -= 'a';
		p = (AdjLink)malloc(sizeof(VNode));
		p->AdjV = j2;
		p->weight = weight;
		p->next = NULL;
		if (!AdjL[j1].HAdjV) AdjL[j1].HAdjV = p;
		else
		{
			q = AdjL[j1].HAdjV;
			while (q->next) q = q->next;
			q->next = p;
		}
	}
	fclose(fp);
	printf("创建图的邻接表成功！\n");
} //GraphAdjCreate


typedef struct QueueNode
{
	int AdjV;//顶点的位置
	int weightSum; //距离出发点的总和
}QueueNode;

typedef struct Queue
{
	QueueNode data[VertexNum + 1];
	int front, tail;
}Queue;

void InitQueue(Queue *queue)
{
	memset(queue, 0, sizeof(queue));
	for (int i = 0; i < VertexNum + 1;i++)
	{
		queue->data[i].weightSum = 0;
	}
	queue->front = 0;
	queue->tail = 0;
}


//入队，加上权值
void EnQueue(Queue *queue,int v,int weight)
{
	queue->data[queue->tail].AdjV = v;

	queue->data[queue->tail].weightSum += weight;//加上新的边的权值
	queue->tail++;
}

void DeQueue(Queue *queue, int *v,int *weight)
{
	*v = queue->data[queue->front].AdjV;
	*weight = queue->data[queue->front].weightSum;
	queue->front++;
}

int EmptyQueue(Queue queue)
{
	if (queue.front == queue.tail)
	{
		return 1;
	}
	return 0;
}

//查找v1,v2，2个点中是否存在，长度为len的路径 
//如果找到 返回1 否则返回0
int FindLenth(char v1,char v2,int len)
{
	int begin = v1 - 'a';
	int end = v2 - 'a';
	int vNow = begin,wNow;
	
	//标记是否被访问
	int IfVisit[VertexNum];

	for (int i = 0; i < Vn; i++)
	{
		IfVisit[i] = 0;
	}

	Queue queue;
	InitQueue(&queue); //创建一个辅助队列

	//顶点入队
	EnQueue(&queue, begin, 0);
	IfVisit[begin] = 1;//标记顶点已经访问

	while (0==EmptyQueue(queue))
	{
		DeQueue(&queue, &vNow, &wNow);//第一个元素出队
		if (vNow==end && wNow == len) //如果找到，输出最短路径
		{
			return 1;
		}
		else{
			IfVisit[vNow] = 1;//标记该顶点已经访问
			AdjLink p = AdjL[vNow].HAdjV;
			while (p != NULL)
			{
				//如果该点没被访问，加入队列
				if (IfVisit[p->AdjV] == 0)
				{
					int wt = p->weight;
					wt += wNow;
					EnQueue(&queue, p->AdjV, wt);
				}
				
				
				p = p->next;
			}
		}
	}
	return 0;
}

int main()
{
	GraphAdjCreate();
	printf("%d\n", FindLenth('a', 'c', 20));
	printf("%d\n",FindLenth('a', 'c', 24));

}
