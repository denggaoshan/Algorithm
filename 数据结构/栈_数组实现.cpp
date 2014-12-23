/*栈的数组实现*/
#include <iostream>

#define MAXSIZE 100

typedef int ElemType;


typedef struct Stack
{
	ElemType Data[MAXSIZE];
	int top;
}Stack;

bool InitStack(Stack *S)
{
	S->top = -1 ;
	return true;
}

int StackCount(Stack S)
{
	return S.top+1;
}

bool Push(Stack *S,ElemType e)
{
	if( S->top+1 >= MAXSIZE)
		return false;

	S->top++;
	S->Data[S->top] = e;
	return true;
}

bool Pop(Stack *S,ElemType *e)
{
	if(S->top == -1)
		return false;

	*e = S->Data[S->top];
	S->top--;
	return true;
}

using namespace std;

int main()
{
	Stack st;
	ElemType e;
	InitStack(&st);
	cout<<"Stack Count : "<<StackCount(st)<<endl;
	
	for(int i=0;i<10;i++)
	Push(&st,i);

	for(int i=0;i<10;i++)
	{
		Pop(&st,&e);
		cout<<e<<" ";
	}		
	return 0;
}
