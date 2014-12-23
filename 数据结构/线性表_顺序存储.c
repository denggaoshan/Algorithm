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


/*
*	顺序存储，通过数组实现。
*/
#include <stdio.h>

#define MAXSIZE 100
#define FALSE 0
#define TRUE 1
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;


typedef struct SqList
{
	ElemType Data[MAXSIZE];
	int length;
}SqList;

Status InitList(SqList *L)
{
	L->length = 0;
	return OK;
}

Status ListEmpty(SqList L)
{
	if(L.length == 0)
		return TRUE;
	else
		return FALSE;
}

Status ClearList(SqList *L)
{
	L->length = 0 ; 
	return TRUE;
}

int ListLength(SqList L)
{
	return L.length;
}

int LocateElem(SqList L,ElemType e)
{
	int i;
	for(i=0;i<L.length ; i++)
	{
		if(L.Data[i] == e)
			return i+1;
	}
	return 0;
}

Status ListInsert(SqList *L,int i,ElemType e)
{
	int k;
	if(L->length +1 >= MAXSIZE)
		return FALSE;
	if(i > L->length || i < 0)
		return FALSE;
	
	for(k=L->length;k>i;k--)
	{
		L->Data[k] = L->Data[k-1];
	}
		L->Data[k] = e;
		L->length++;
		return TRUE;
}

Status ListDelete(SqList *L,int i,ElemType *e)
{
	int k;

	if(ListEmpty(*L)==TRUE)
		return FALSE;
	if(i >= L->length)
		return FALSE;

	*e = L->Data[i-1];

	for(k=i-1 ; k < L->length ; k++)
	{
		L->Data[k] = L->Data[k+1];
	}
	L->length--;
	return TRUE;
}

int main()
{
	int i;
	SqList L;
	ElemType e = 10;
	
	InitList(&L);
	printf("ListEmpty = %d \n",ListEmpty(L));

	printf("ListInsert 0 10 : %d\n",ListInsert(&L,0,e));
	printf("ListEmpty = %d \n",ListEmpty(L));

	printf("ListInsert 5 3 : %d\n",ListInsert(&L,5,3));
	printf("ListLength = %d \n",ListLength(L));
	
	for(i=0;i<10;i++)
	{
		ListInsert(&L,i,i);
	}

	printf("LocateElem 3 = %d",LocateElem(L,5));
	
}
