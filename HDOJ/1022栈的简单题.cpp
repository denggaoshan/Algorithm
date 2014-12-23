/*ջ��Ӧ�� ����һ�����ѹ��*/
/*
       ע�����
	   ��̬ջ�Ķ�������ʼ����ʱ��topǧ����Ϊ0��Ҫ����Ϊ-1;
	   ��ջ��ʱ���Ȱ�top++���ٷ�Ԫ�أ�����
*/

#include "stdio.h"
#include "string.h"

typedef struct Stack
{
	int length;
	char str[3000];
	int top;
}Stack;

void Init(Stack *s)
{
	s->length=0;
	s->top=-1;
}

void Push(Stack *s,char e)
{
	s->top++;
	s->str[s->top]=e;
    s->length++;
}

char Pop(Stack *s)
{
	char c;
	s->length--;
	c=s->str[s->top];
	s->top--;
	return c;
}

int main()
{
	Stack train;
	char in[5000],out[5000];
	int order[5000];  //1�� 2�� �ӵ�1����ʼ ��0����flag
	int num,len;
	int i,j,k;

	while(scanf("%d%s%s",&num,in,out)!=EOF)
	{
		len=i=j=k=0;
	    Init(&train);
		len = strlen(out);

		while( ((train.length==0 || train.str[train.top]!=out[j]))  && (i<len)  ) 
		{
			Push(&train,in[i++]);
			order[k++]=1;
			
			while(train.str[train.top] == out[j] && train.length>0)
			{
				Pop(&train);
				j++;
				order[k++]=2;
			}
		}
		
		if(train.length==0)
		{
			i=0;
			printf("Yes.\n");
			while(i<2*len)
			{
				if(order[i]==1)
					printf("in\n");
				else printf("out\n");
				i++;
			}
			printf("FINISH\n");
		}
		else
			printf("No.\nFINISH\n");
	}

	return 0;
}
