#include <iostream>

using namespace std;

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	Node * next;
}Node;

typedef struct LinkQueue
{
	Node*head;
	Node*tail;
}LinkQueue;


bool InitQueue(LinkQueue *queue)
{
	Node *p = new Node;
	if(!p)
		return false;

	p->next =NULL;
	queue->head = p;
	queue->tail = p;
	return true;
}

bool EnQueue(LinkQueue *queue,ElemType e)
{
	Node *p = new Node;
	if(!p)
		return false;
	p->data = e;
	p->next =NULL;
	queue->tail->next = p;
	queue->tail = queue->tail->next;
	return true;
}

bool DeQueue(LinkQueue *queue,ElemType *e)
{
	if(queue->head == queue->tail)
		return false;
	Node *p = queue->head->next;
	*e = p->data;
	queue->head->next = p->next;
	
	//若队尾被删除
	if(queue->tail == p)
		queue->tail = queue->head;
	
	delete p;

	return true;
}

void Print(LinkQueue queue)
{
	Node *h = queue.head->next;
	cout<<"当前队列中的元素为："<<endl;
	while(h!=NULL)
	{
		cout<<h->data<<" ";
		h = h->next;
	}
	cout<<endl;
}

int main()
{
	LinkQueue queue;
	int e;

	InitQueue(&queue);
	for(int i=0;i<3;i++)
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