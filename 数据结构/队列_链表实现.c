#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Status;

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node * next;
}Node;

typedef struct LinkQueue
{
	Node* head;
	Node* tail;
}LinkQueue;

Status InitQueue(LinkQueue *queue)
{
	Node *p = (Node *)malloc(sizeof(Node));
	if(!p)
		return FALSE;
	p->next = NULL ;
	queue->head = p;
	queue->tail = p;
	return TRUE;
}

Status EnQueue(LinkQueue *queue,ElemType e)
{
	Node *p = (Node *)malloc(sizeof(Node));
	if(!p)
		return FALSE;
	p->data = e;
	p->next =NULL;
	queue->tail->next = p;
	queue->tail = queue->tail->next;
	return TRUE;
}

Status DeQueue(LinkQueue *queue,ElemType *e)
{
	Node *p = NULL;
	if(queue->head == queue->tail)
		return FALSE;
	p = queue->head->next;
	*e = p->data;
	queue->head->next = p->next;
	
	//若队尾被删除
	if(queue->tail == p)
		queue->tail = queue->head;
	
	free(p);
	return TRUE;
}

void Print(LinkQueue queue)
{
	Node *h = queue.head->next;
	printf("当前队列中的元素为：");
	while(h!=NULL)
	{
		printf("%d ",h->data);
		h = h->next;
	}
	printf("\n");
}

int main()
{
	LinkQueue queue;
	int e;
	int i;
	InitQueue(&queue);
	for(i=0;i<3;i++)
	EnQueue(&queue,i);

	Print(queue);
	DeQueue(&queue,&e);
	DeQueue(&queue,&e);
	
	Print(queue);
	DeQueue(&queue,&e);
	DeQueue(&queue,&e);
	DeQueue(&queue,&e);
	Print(queue);
	DeQueue(&queue,&e);
	DeQueue(&queue,&e);
	DeQueue(&queue,&e);
	Print(queue);

	return 0;
}
