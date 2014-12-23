/*栈的数组实现*/
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int ElemType;
typedef int Status;


typedef struct Stack
{
	ElemType Data[MAXSIZE];
	int top;
}Stack;

Status InitStack(Stack *S)
{
	S->top = -1 ;
	return TRUE;
}

int StackCount(Stack S)
{
	return S.top+1;
}

Status Push(Stack *S,ElemType e)
{
	if( S->top+1 >= MAXSIZE)
		return FALSE;

	S->top++;
	S->Data[S->top] = e;
	return TRUE;
}

Status Pop(Stack *S,ElemType *e)
{
	if(S->top == -1)
		return FALSE;

	*e = S->Data[S->top];
	S->top--;
	return TRUE;
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
