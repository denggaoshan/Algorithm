/*������ʵ�ֶ���*/

#include <stdio.h>

#define MAXSIZE 6

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct Queue
{
	ElemType data[MAXSIZE];
	int head;
	int tail;
}Queue;

Status InitQueue(Queue *queue)
{
	queue->head = 0;
	queue->tail = 0;
	return TRUE;
}

//���
Status EnQueue(Queue *queue,ElemType e)
{
	if( (queue->tail + 1) % MAXSIZE == queue->head)
	{
		return FALSE;
	}
	queue->data[queue->tail] = e;
	queue->tail = (queue->tail + 1)% MAXSIZE ;
	return TRUE;
}

//����
Status DeQueue(Queue *queue,ElemType *e)
{
	//�ն���
	if( queue->head == queue->tail)
	{
		return FALSE;
	}
	
	*e=queue->data[queue->head] ;
	queue->head = (queue->head + 1)%MAXSIZE;
	return TRUE;
}

Status ClearQueue(Queue *queue)
{
	queue->tail = 0;
	queue->head = 0;
	return TRUE;
}

void Print(Queue queue)
{
	int h = queue.head;
	printf("��ǰ������Ԫ���У�\n");
	while(h != queue.tail)
	{
		printf("%d ",queue.data[h]);
		h = (h + 1) % MAXSIZE ;
	}
}

int QueueLength(Queue queue)
{
	return (queue.tail + MAXSIZE - queue.head )%MAXSIZE;
}

int main()
{
	int e,i;
	Queue queue;
	InitQueue(&queue);
	for(i=0;i<MAXSIZE;i++)
	EnQueue(&queue,i);
	Print(queue);
	DeQueue(&queue,&e);
	DeQueue(&queue,&e);
	DeQueue(&queue,&e);
	Print(queue);

	EnQueue(&queue,8);
	Print(queue);

	printf("��ǰ���еĳ���: %d\n",QueueLength(queue));
	printf("��ն���: %d\n",ClearQueue(&queue));
	Print(queue);

	return 0;
}
