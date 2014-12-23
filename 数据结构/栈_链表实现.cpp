#include <iostream>

using namespace std;

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	Node* next;
};

typedef struct Stack
{
	Node * top;
	int count;
}Stack;

bool InitStack(Stack *st)
{
	st->top = new Node;
	if(!st->top)
		return false;
	st->top->next = NULL;
	st->count = 0;
	return true;
}

bool Push(Stack *st,ElemType e)
{
	Node *p = new Node;
	if(!p)
		return false;
	p->data = e;
	p->next = st->top->next;
	st->top->next = p ;
	st->count-- ;
	return true;
}

bool Pop(Stack *st,ElemType *e)
{
	if(st->count == 0)
		return false;
	*e = st->top->next->data;
	Node * p = st->top->next;
	st->top->next = st->top->next->next;
	delete p;
	st->count--;
	return true;
}

int StackCount(Stack st)
{
	return st.count;
}

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