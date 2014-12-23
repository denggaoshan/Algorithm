/*
*	ADT 线性表
*	
*	Data 线性表数据对象集合为 {a1,a2,a3……an} , 每个元素类型为 DataType 。 
*	其中除了第一个a1外，每个元素有且仅有一个直接前驱元素。
*	除了最后一个元素an外，每个元素有且只有一个后继元素。
*	数据元素之间的关系是一对一的关系
*
*	Operation
*		InitList(*L):	初始化操作，建立一个空的线性表L。
*		ListEmpty(L):	若线性表为空，返回true,否则返回false。
*		ClearList(*L):	将线性表清空
*		LocateElem(L,e):在线性表L中查找与给定值e相等的元素，如果查找成功，返回该元素位序，否则返回0;
*		ListInsert(*L,i,e);	在线性表L中的第i个位置插入新元素e。
*		ListDelete(*L,i,*e):删除线性表L中的第i个位置的元素，并用e返回其值
*		ListLength(L):		返回线性表L的元素个数。
*
*	endADT
*/

/*线性表的链式存储*/
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	Node* next;
}Node;

typedef struct LinkList
{
	Node *head;
	int length;
}LinkList;

//建立带头结点的链表
bool InitList(LinkList *L)
{
	L->head = new Node;
	if(L->head ==NULL)
		return false;

	L->head->next =NULL;
	L->length = 0;

	return true;
}

bool ListEmpty(LinkList L)
{
	return L.length==0;
}

int ListLength(LinkList L)
{
	return L.length;
}

bool ClearList(LinkList *L)
{
	Node *p = L->head->next;
	Node *q =NULL;
	while(p!=NULL)
	{
		p->next = q;
		delete p;
		p = q ;
	}
	L->length = 0 ;
	return true;
}

int LocateElem(LinkList L,ElemType e)
{
	Node *p = L.head  ;
	for(int i=0;i<L.length;i++)
	{
		if(p->data == e)
			return i+1;
		p = p ->next ;
	}
	return 0;
}


bool ListInsert(LinkList *L,int i,ElemType e)
{
	if(i> L->length+1 || i<=0)
		return false;

	Node *p = L->head;
	int k;
	for(k=0;k<L->length;k++)
	{
		p = p->next;
	}

	Node *q = new Node;
	if(!q)
		return false;

	q->data = e;
	q->next = p ->next;
	p->next = q;
	L->length++;
	return true;
}

bool ListDelete(LinkList *L,int i,ElemType *e)
{
	if(i<=0 || i>L->length)
		return false;
	
	Node *p = L->head;
	int k;
	for(k=1;k<i;k++)
	{
		p=p->next;
	}

	*e = p->next->data;
	Node *q = p->next;
	p->next = q->next;
	delete q;
	L->length--;
	return true;
}

ElemType getElem(LinkList L,int i)
{
	if(i<=0 || i > L.length)
		return 0;

	Node *p = L.head;
	for(int k=0;k<i;k++)
	{
		p=p->next;
	}
	return p->data;
}

int main()
{
	LinkList L;
	ElemType e;
	InitList(&L);
	cout<<"ListEmpty : "<<ListEmpty(L)<<endl;
	cout<<"ListInsert 1 3 :"<<ListInsert(&L,1,1)<<endl;
	cout<<"ListInsert 3 1 :"<<ListInsert(&L,3,3)<<endl;
	ListInsert(&L,2,2);
	ListInsert(&L,3,3);
	ListInsert(&L,4,4);
	cout<<"LocateElem 2: "<<LocateElem(L,4)<<endl;
	cout<<"ListDelete 2: "<<ListDelete(&L,3,&e)<<endl;
	for(int i=1;i<=L.length;i++)
		cout<<" "<<getElem(L,i)<<endl;

	cout<<"ClearList : "<<ClearList(&L)<<endl;
	return 0;
}