#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef char Type;

typedef struct BiTNode
{
Type data;  //������Type: �û�������������
struct BiTNode *Lchild;  //��ָ����
struct BiTNode *Rchild;  //��ָ����
} BiTNode, *BiTree;

//����һ����ͷ���Ŀն�������
int TreeInit(BiTree &T)
{
	T =(BiTree)malloc(sizeof(BiTNode));
	if(!T)
	{
		return 0;
	}
	T->Lchild= T->Rchild = NULL;
	return 1;
}


char Str[] = "A(B(a,b),C(D(d,^),c))";
int index = 0;
BiTree TreeCreate()
{

	char ch = Str[index];

	if(ch=='^')
	{
		index++;
		return NULL;
	}

	BiTree p ;
	TreeInit(p);
	p->data = ch;
	
	if(Str[index+1]==',' )
	{
		return p;
	}
	if(Str[index+1]==')')
	{
		index++;
		return p;
	}
	
	BiTree pl,pr ;
	TreeInit(pl);
	TreeInit(pr);

	index+=2;
	p->Lchild = TreeCreate();//���
	index+=2;
	p->Rchild = TreeCreate();//�ұ�
	
	return p;
}

//ǰ�����
void PreOrder(BiTree T)
{
	if(T==NULL)
		return;
	printf("%c ",T->data);
	PreOrder(T->Lchild);
	PreOrder(T->Rchild);
}

//�������
void InOrder(BiTree T)
{
	if(T==NULL)
		return;
	InOrder(T->Lchild);
	printf("%c ",T->data);
	InOrder(T->Rchild);
}

//�������
void PostOrder(BiTree T)
{
	if(T==NULL)
		return;
	PostOrder(T->Lchild);
	PostOrder(T->Rchild);
	printf("%c ",T->data);
}

void TreeDistroy(BiTree &T)
{
	if(T==NULL)
		return;

	TreeDistroy(T->Lchild);
	TreeDistroy(T->Rchild);
	free(T);	
	return;
}

int depthMax;

int Search(BiTree T,int depth)
{
	if (T==NULL)
	{
		return  depth;
	}

	if(depth>=depthMax)
	{
		depthMax = depth;
	}
	Search(T->Lchild,depth+1);
	Search(T->Rchild,depth+1);
}


int TreeDepthS(BiTree T)
{
	depthMax = -1;
	Search(T,1);
	return depthMax;
}

//�Ѷ����������ַ���ʽ���
void PrintChar(BiTree T)
{
	if(T== NULL)
	{
		printf("^");
		return;
	}

	printf("%c",T->data);
	
	if(T->Lchild!=NULL || T->Rchild !=NULL)
	{
		printf("(");
		PrintChar(T->Lchild);
		printf(",");
		PrintChar(T->Rchild);
		printf(")");
	}
}

int main()
{
	BiTree Tree;
	
	printf("�����ַ���:\n%s\n����������\n",Str);
	Tree = TreeCreate();
	printf("�������:\n");
	PreOrder(Tree);
	printf("\n");
	printf("�������:\n");
	InOrder(Tree);
	printf("\n");
	printf("�������:\n");
	PostOrder(Tree);
	printf("\n");

	printf("���߶�Ϊ��%d\n",TreeDepthS(Tree));
	printf("�������ַ���ʽ���:\n");
	PrintChar(Tree);


	TreeDistroy(Tree);

	return 0;
}
