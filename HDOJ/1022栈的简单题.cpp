/*栈的应用 哈哈一遍过无压力*/
/*
       注意事项：
	   静态栈的顶部，初始化的时候，top千万不能为0，要设置为-1;
	   入栈的时候，先把top++，再放元素！！！
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
	int order[5000];  //1入 2出 从第1个开始 第0个存flag
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
