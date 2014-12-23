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

//������ͷ��������
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