#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define VertexNum 100

// �ڽӱ�洢�ṹ
typedef struct ANode
{
	int AdjV; //�ڽӵ���˳����е�λ��
	int weight;	//�洢����Ȩֵ
	struct ANode *next; //ָ����һ���ڽӵ�
} *AdjLink;

// ��ͷָ��ṹ
typedef struct
{
	int data;
	AdjLink HAdjV; //�ڽӵ�����ͷָ��
} VNode;

VNode AdjL[VertexNum];

int Vn, En;

// ͨ�����롰�ߡ�����ͼ���ڽӱ�洢�ṹ
void GraphAdjCreate()
{
	// �ڽӱ��ʼ��
	FILE *fp = fopen("data.txt", "r");  //�������ļ�
	if (fp == NULL)return;
	fscanf(fp, "%d %d", &Vn, &En);  //��ȡ�������ͱ���
	if (Vn > VertexNum) Vn = VertexNum;
	fscanf(fp, "%c");  //�������з�
	printf("\nVn=%d, En=%d\n", Vn, En);

	// �����ڽӱ�洢�ṹ
	for (int k = 1; k <= Vn; k++) AdjL[k].data = k;
	int j1 = 0, j2 = 0; //������ź�Ȩֵ
	int weight;//�ߵ�Ȩֵ
	AdjLink p, q;
	for (int k = 0; k < En; k++)
	{
		fscanf(fp, "%c,%c,%d", &j1, &j2,&weight);  //��ȡ��
		fscanf(fp, "%c");//��������
		j1 -= 'a';//ת���ɱ��
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
	printf("����ͼ���ڽӱ�ɹ���\n");
} //GraphAdjCreate


typedef struct QueueNode
{
	int AdjV;//�����λ��
	int weightSum; //�����������ܺ�
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


//��ӣ�����Ȩֵ
void EnQueue(Queue *queue,int v,int weight)
{
	queue->data[queue->tail].AdjV = v;

	queue->data[queue->tail].weightSum += weight;//�����µıߵ�Ȩֵ
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

//����v1,v2��2�������Ƿ���ڣ�����Ϊlen��·�� 
//����ҵ� ����1 ���򷵻�0
int FindLenth(char v1,char v2,int len)
{
	int begin = v1 - 'a';
	int end = v2 - 'a';
	int vNow = begin,wNow;
	
	//����Ƿ񱻷���
	int IfVisit[VertexNum];

	for (int i = 0; i < Vn; i++)
	{
		IfVisit[i] = 0;
	}

	Queue queue;
	InitQueue(&queue); //����һ����������

	//�������
	EnQueue(&queue, begin, 0);
	IfVisit[begin] = 1;//��Ƕ����Ѿ�����

	while (0==EmptyQueue(queue))
	{
		DeQueue(&queue, &vNow, &wNow);//��һ��Ԫ�س���
		if (vNow==end && wNow == len) //����ҵ���������·��
		{
			return 1;
		}
		else{
			IfVisit[vNow] = 1;//��Ǹö����Ѿ�����
			AdjLink p = AdjL[vNow].HAdjV;
			while (p != NULL)
			{
				//����õ�û�����ʣ��������
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
