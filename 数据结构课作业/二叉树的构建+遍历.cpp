#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef char Type;

typedef struct BiTNode
{
Type data;  //数据域；Type: 用户定义数据类型
struct BiTNode *Lchild;  //左指针域
struct BiTNode *Rchild;  //右指针域
} BiTNode, *BiTree;

//建立一个带头结点的空二叉链表
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
	p->Lchild = TreeCreate();//左边
	index+=2;
	p->Rchild = TreeCreate();//右边
	
	return p;
}

//前序遍历
void PreOrder(BiTree T)
{
	if(T==NULL)
		return;
	printf("%c ",T->data);
	PreOrder(T->Lchild);
	PreOrder(T->Rchild);
}

//中序遍历
void InOrder(BiTree T)
{
	if(T==NULL)
		return;
	InOrder(T->Lchild);
	printf("%c ",T->data);
	InOrder(T->Rchild);
}

//后序遍历
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

//把二叉树按照字符形式输出
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
	
	printf("根据字符串:\n%s\n构建二叉树\n",Str);
	Tree = TreeCreate();
	printf("先序遍历:\n");
	PreOrder(Tree);
	printf("\n");
	printf("中序遍历:\n");
	InOrder(Tree);
	printf("\n");
	printf("后序遍历:\n");
	PostOrder(Tree);
	printf("\n");

	printf("树高度为：%d\n",TreeDepthS(Tree));
	printf("树按照字符形式输出:\n");
	PrintChar(Tree);


	TreeDistroy(Tree);

	return 0;
}
