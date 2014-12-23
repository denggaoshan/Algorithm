#include<stdio.h>
#include<stdlib.h>

typedef int KeyType;
typedef int ElemType;

typedef struct BiTnode
{
	KeyType key;  //�ؼ�����
	struct BiTnode *Lchild;  //��ָ����
	struct BiTnode *Rchild;  //��ָ����
} BiTnode, *BiTree;


bool TreeInsert(BiTree *tree,KeyType key)
{
	BiTnode *p = *tree;
	BiTnode *q = NULL;

	if (!(*tree))
	{
		(*tree) = (BiTree)malloc(sizeof(BiTnode));
		(*tree)->key = key;
		(*tree)->Lchild = NULL;
		(*tree)->Rchild = NULL;
		return true;
	}
	while (p != NULL)
	{
		q = p;
		if (key > p->key)
		{
			p = p->Rchild;
		}
		else
		{
			p = p->Lchild;
		}
	}
	
	p = (BiTnode *)malloc(sizeof(BiTnode));
	if (!p)return false;
	p->key = key;
	p->Lchild = NULL;
	p->Rchild = NULL;
	if (q->key > p->key)
	{
		q->Lchild = p;
	}
	else
	{
		q->Rchild = p;
	}
	return true;
}


//����  ����pָ���ҵ���λ��
int TreeSearch(BiTree tree,KeyType key,BiTree f,BiTree *p)
{
	if (!tree)
	{
		*p = f;
		return 0;
	}
	else if (key == tree->key)
	{
		*p = tree;
		return 1;
	}
	else if (key < tree->key)
	{
		TreeSearch(tree->Lchild,key,tree,p);
	}
	else
	{
		TreeSearch(tree->Rchild, key, tree, p);
	}
}

bool DelNode(BiTree *tree)
{
	BiTree p = NULL;	//��ʱ���
	BiTree front = NULL; //ָ���ɾ����ǰһ�����

	if ((*tree)->Rchild == NULL)
	{
		//���������Ϊ�գ�ֻ��Ҫ�ؽ�������
		p = *tree;
		*tree = (*tree)->Lchild;
		free(p);
	}
	else if ((*tree)->Lchild == NULL)
	{
		//���������Ϊ��,ֻ���ؽ�������
		p = *tree;
		*tree = (*tree)->Rchild;
		free(p);
	}
	else
	{
		//������Ҷ���Ϊ�գ��ڽ������ҵ�����ֱ��ǰ�������滻�������㣬ɾ��ֱ��ǰ����
		front = *tree;
		p = front->Lchild;
		while (p->Rchild != NULL)
		{
			front = p;
			p = p->Rchild;
		}
		(*tree)->key = p->key;
		front->Rchild = p->Lchild;
		free(p);
	}
	return 1;
}

int TreeDelete(BiTree* tree,KeyType key)
{
	if ( (*tree) == NULL)
		return 0;

	if (tree)
	{
		if ((*tree)->key == key)
			return DelNode(tree);
		else if ((*tree)->key > key)
			return TreeDelete(&(*tree)->Lchild, key);
		else
			return TreeDelete(&(*tree)->Rchild, key);
	}
	return 0;
}


int main()
{
	int i;
	int data[] = { 10, 6 , 20, 4, 7, 15, 3,5,2 };
	BiTree tree = NULL;
	for (i = 0; i < 9;i++)
	TreeInsert(&tree, data[i]);
	
	TreeDelete(&tree, 6);
	TreeDelete(&tree, 10);
	return 0;
}