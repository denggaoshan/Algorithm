/*用数组实现队列*/

#include <iostream>

using namespace std;

#define MAXSIZE 6

typedef int ElemType;

typedef struct Queue
{
	ElemType data[MAXSIZE];
	int head;
	int tail;
}Queue;

bool InitQueue(Queue *queue)
{
	queue->head = 0;
	queue->tail = 0;
	return true;
}

//入队
bool EnQueue(Queue *queue,ElemType e)
{
	if( (queue->tail + 1) % MAXSIZE == queue->head)
	{
		return false;
	}
	queue->data[queue->tail] = e;
	queue->tail = (queue->tail + 1)% MAXSIZE ;
	return true;
}

//出队
bool DeQueue(Queue *queue,ElemType *e)
{
	//空队列
	if( queue->head == queue->tail)
	{
		return false;
	}
	
	*e=queue->data[queue->head] ;
	queue->head = (queue->head + 1)%MAXSIZE;
	return true;
}

bool ClearQueue(Queue *queue)
{
	queue->tail = 0;
	queue->head = 0;
	return true;
}

void Print(Queue queue)
{
	int h = queue.head;
	cout<<"当前队列中元素有："<<endl;
	while(h != queue.tail)
	{
		cout<<queue.data[h]<<" ";
		h = (h + 1) % MAXSIZE ;
	}
	cout<<endl;
}

int QueueLength(Queue queue)
{
	return (queue.tail + MAXSIZE - queue.head )%MAXSIZE;
}

int main()
{
	Queue queue;
	InitQueue(&queue);
	for(int i=0;i<MAXSIZE;i++)
	EnQueue(&queue,i);
	Print(queue);
	int e;
	DeQueue(&queue,&e);
	DeQueue(&queue,&e);
	DeQueue(&queue,&e);
	Print(queue);

	EnQueue(&queue,8);
	Print(queue);

	cout<<"当前队列的长度:"<<QueueLength(queue)<<endl;

	cout<<"清空队列:"<<ClearQueue(&queue)<<endl;
	Print(queue);

	return 0;
}