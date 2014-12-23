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

/*���Ա����ʽ�洢*/
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;


typedef struct Node
{
	ElemType data;
	struct Node* next;
}Node;

typedef struct LinkList
{
	Node *head;
	int length;
}LinkList;

//������ͷ��������
Status InitList(LinkList *L)
{
	L->head = (Node *)malloc(sizeof(Node));
	if(L->head ==NULL)
		return FALSE;

	L->head->next =NULL;
	L->length = 0;

	return TRUE;
}

Status ListEmpty(LinkList L)
{
	return L.length==0;
}

int ListLength(LinkList L)
{
	return L.length;
}

Status ClearList(LinkList *L)
{
	Node *p = L->head->next;
	Node *q =NULL;
	while(p!=NULL)
	{
		p->next = q;
		free(p);
		p = q ;
	}
	L->length = 0 ;
	return TRUE;
}

int LocateElem(LinkList L,ElemType e)
{
	int i ;
	Node *p = L.head ;
	for(i=0;i<L.length;i++)
	{
		if(p->data == e)
			return i+1;
		p = p ->next ;
	}
	return 0;
}


Status ListInsert(LinkList *L,int i,ElemType e)
{
	Node *p = L->head;
	int k;
	Node *q = NULL;
	if(i> L->length+1 || i<=0)
		return FALSE;

	for(k=0;k<L->length;k++)
	{
		p = p->next;
	}

	q = (Node *)malloc(sizeof(Node));
	if(!q)
		return FALSE;

	q->data = e;
	q->next = p ->next;
	p->next = q;
	L->length++;
	return TRUE;
}

Status ListDelete(LinkList *L,int i,ElemType *e)
{
	Node *p = L->head;
	Node *q = NULL;
	int k;
	
	if(i<=0 || i>L->length)
		return FALSE;
	
	for(k=1;k<i;k++)
	{
		p=p->next;
	}

	*e = p->next->data;
	q = p->next;
	p->next = q->next;
	free(q);
	L->length--;
	return TRUE;
}

ElemType getElem(LinkList L,int i)
{
	Node *p = L.head;
	int k = 0 ;
	if(i<=0 || i > L.length)
		return 0;

	for(k=0;k<i;k++)
	{
		p=p->next;
	}
	return p->data;
}

int main()
{
	LinkList L;
	int i = 0 ;
	ElemType e;
	InitList(&L);
	printf("ListEmpty : %d\n",ListEmpty(L));
	printf("ListInsert 1 3 : %d\n",ListInsert(&L,1,1));
	printf("ListInsert 3 1 : %d\n",ListInsert(&L,3,3));
	ListInsert(&L,2,2);
	ListInsert(&L,3,3);
	ListInsert(&L,4,4);
	printf("LocateElem 2: %d \n",LocateElem(L,4));
	printf("ListDelete 2: %d \n",ListDelete(&L,3,&e));
	for(i=1;i<=L.length;i++)
		printf("%d ",getElem(L,i));

	printf("\nClearList : %d \n",ClearList(&L));
	return 0;
}
