/*用数组实现队列*/

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

//入队
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

//出队
Status DeQueue(Queue *queue,ElemType *e)
{
	//空队列
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
	printf("当前队列中元素有：\n");
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

	printf("当前队列的长度: %d\n",QueueLength(queue));
	printf("清空队列: %d\n",ClearQueue(&queue));
	Print(queue);

	return 0;
}
