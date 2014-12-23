#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1000

typedef struct Node
{
	char data;   //�����Ҷ�ӽڵ�,data��ʾ������ַ�������Ϊ0
	double freq; //����
	struct Node * left;
	struct Node * right;
}Node;


//��С���ȶ���
typedef struct
{
	Node* data[MAXSIZE];
	int count;
}*Queue;

//���
void EnQueue(Queue q,Node *node)
{
	q->data[q->count] = node;
	q->count++;
}



//ѡ����С��Ԫ�أ�����
Node *DeQueue(Queue q)
{
	int i;
	
	double minFreq=10000;
	int minIndex=0;
	for(i=0;i<q->count;i++)
	{
		if(q->data[i]->freq < minFreq)
		{
			minFreq = q->data[i]->freq ;
			minIndex = i;
		}
	}
	Node *tmp = q->data[0];
	q->data[0]= q->data[minIndex];
	q->data[minIndex] = tmp;


	Node *p = q->data[0];
	for(i=0;i< q->count-1 ;i++)
	{
		q->data[i]=q->data[i+1];
	}

	q->count--;
	return p;
}

//��ʼ��һ����С���ȶ���,data����ַ���freq�����Ӧ��Ȩֵ,count��������
void InitQueue(Queue &q,char data[],int freq[],int count)
{
	int i=0;
	q = (Queue)malloc(sizeof(Queue));
	q->count = 0;



	for(i=0;i<count;i++)
	{
		Node *p = new(Node);
		p->data = data[i];
		p->freq = freq[i];
		p->left = NULL;
		p->right = NULL;
		EnQueue(q,p);
	}

	q->count = count;
}

char answer[150][100]; //����ַ��Ͷ�Ӧ�ı���

void PrintAnswer(Node *head,char *nowcode)
{
	if(head==NULL)
	{
		return;
	}
	if(head->data != '\0')
	{
		printf("%c -> %s\n",head->data,nowcode);
		strcpy(answer[head->data],nowcode);
		return;
	}
	else
	{
		char str[20];
		strcpy(str,nowcode);
		strcat(str,"0");
		PrintAnswer(head->left,str);
		strcpy(str,nowcode);
		strcat(str,"1");
		PrintAnswer(head->right,str);
	}
}


//����������
Node* HuffmanInit(char data[],int freq[],int count)
{
	Queue q=NULL;
	InitQueue(q,data,freq,count);

	while(q->count > 1)
	{
		Node *node = (Node *)malloc(sizeof(Node));
		node->left = DeQueue(q);
		node->right = DeQueue(q);
		node->freq = node->left->freq + node->right->freq;
		node->data = '\0';
		EnQueue(q,node);	
	}
	
	Node *head = DeQueue(q);

	PrintAnswer(head,"");
	return head;
}

//�����ַ����е�ÿ���ַ����ֵ�Ƶ��
int getFreq(char *origin,char data[],int freq[])
{
	int len = strlen(origin);
	int i = 0;
	int j = 0;
	int charCnt;
	int flag = 0;

	memset(data,0,sizeof(data)*len);
	memset(freq,0,sizeof(freq)*len);

	data[0]=origin[0];
	freq[0]=0;
	charCnt = 1;

	while(i<len)
	{
		flag = 0;
		for(j=0;j<=charCnt;j++)
		{
			if(data[j]==origin[i])
			{
				freq[j]++;			
				flag = 1;
			}
		}
		if(flag == 0)
		{
			freq[charCnt]++;
			data[charCnt]=origin[i];
			charCnt++;
		}
		i++;
	}
	return charCnt;
}
//huffman����
char *HuffmanEncoding(Node *huffmanTree,char *origin)
{
	int i =0 ;
	int len =strlen(origin);

	printf("����֮��Ϊ��\n");
	for(i=0;i<len;i++)
	{
		printf("%s",answer[origin[i]]);
	}
	printf("\n");
	return 0;
}


//huffman����
void HuffmanDecoding(Node *huffmanTree,char *code)
{
	int index = 0;
	int len = strlen(code);
	while(index<len)
	{
		
	}
}

int main()
{
	char data[300];
	int freq[100];
	char code[100];

	char originData[] = "abbaabcbabaddfbbbbbbbbbbaaa";

	int len = getFreq(originData,data,freq);
	printf("Դ��Ϊ:\n%s\n",originData);
	printf("�������������\n");
	Node * huffmanTree = HuffmanInit(data,freq,len);

	HuffmanEncoding(huffmanTree,originData);

	return 0;
}