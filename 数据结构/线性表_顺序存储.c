/*
*	ADT ���Ա�
*	
*	Data ���Ա����ݶ��󼯺�Ϊ {a1,a2,a3����an} , ÿ��Ԫ������Ϊ DataType �� 
*	���г��˵�һ��a1�⣬ÿ��Ԫ�����ҽ���һ��ֱ��ǰ��Ԫ�ء�
*	�������һ��Ԫ��an�⣬ÿ��Ԫ������ֻ��һ�����Ԫ�ء�
*	����Ԫ��֮��Ĺ�ϵ��һ��һ�Ĺ�ϵ
*
*	Operation
*		InitList(*L):	��ʼ������������һ���յ����Ա�L��
*		ListEmpty(L):	�����Ա�Ϊ�գ�����true,���򷵻�false��
*		ClearList(*L):	�����Ա����
*		LocateElem(L,e):�����Ա�L�в��������ֵe��ȵ�Ԫ�أ�������ҳɹ������ظ�Ԫ��λ�򣬷��򷵻�0;
*		ListInsert(*L,i,e);	�����Ա�L�еĵ�i��λ�ò�����Ԫ��e��
*		ListDelete(*L,i,*e):ɾ�����Ա�L�еĵ�i��λ�õ�Ԫ�أ�����e������ֵ
*		ListLength(L):		�������Ա�L��Ԫ�ظ�����
*
*	endADT
*/


/*
*	˳��洢��ͨ������ʵ�֡�
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
