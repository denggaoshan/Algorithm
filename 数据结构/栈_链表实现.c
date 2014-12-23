#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;

typedef struct Stack
{
	Node * top;
	int count;
}Stack;

Status InitStack(Stack *st)
{
	st->top = (Node *)malloc(sizeof(Node));
	if(!st->top)
		return FALSE;
	st->top->next = NULL;
	st->count = 0;
	return TRUE;
}

Status Push(Stack *st,ElemType e)
{
	Node *p = (Node *)malloc(sizeof(Node));
	if(!p)
		return FALSE;
	p->data = e;
	p->next = st->top->next;
	st->top->next = p ;
	st->count-- ;
	return TRUE;
}

Status Pop(Stack *st,ElemType *e)
{
	Node * p =NULL ;
	if(st->count == 0)
		return FALSE;
	*e = st->top->next->data;
	p = st->top->next;
	st->top->next = st->top->next->next;
	free(p);
	st->count--;
	return TRUE;
}

int StackCount(Stack st)
{
	return st.count;
}

int main()
{
	int i = 0;
	Stack st;
	ElemType e;
	InitStack(&st);
	printf("Stack Count : %d\n",StackCount(st));
	
	for(i=0;i<10;i++)
	Push(&st,i);

	for(i=0;i<10;i++)
	{
		Pop(&st,&e);
		printf("%d ",e);
	}		
	return 0;
}
