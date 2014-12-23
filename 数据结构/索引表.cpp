#include <stdio.h>
#include <stdlib.h>
#include <string>

#define Ln 20 //顺序表最大长度
#define Lm 9  //关键字宽度+1
#define In 6  //索引表最大长度
#define Im 5  //索引关键字宽度+1

char L[Ln][Lm];  //顺序表[关键字序列]

//索引表存储结构
typedef struct
{
	char index[Im];  //索引关键字
	int start;	//子表第1个记录在顺序表中的位置
	int len;	//子表的长度
} IndexType;
IndexType I[In];  //索引表

//根据顺序表创建索引表
int CreateIndex(int &n)
{
	//顺序表初始化
	FILE *fp=fopen("Index.in","r");  //打开数据文件
	int i , j ;
	fscanf(fp,"%d",&n);  //读取记录数
	fscanf(fp,"%c");  //跳过换行符
	printf("Key List:\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<Lm-1; j++)
			fscanf(fp,"%c",&L[i][j]);
		fscanf(fp,"%c");  //跳过换行符
		L[i][j]='\0';
		puts(L[i]);
	}

	//构造索引表
	int Len=0,m=1;  //m:索引表长度计数
	strncpy(I[0].index,L[0],Im-1);
	I[0].index[Im-1]='\0';
	I[0].start=1;
	char Index[Im]="";
	for(i=1; i<n; i++)
	{
		Len++;  //子表长度计数
		strncpy(Index,L[i],Im-1);
		Index[Im-1]='\0';
		if(strcmp(Index,I[m-1].index))
		{
			strcpy(I[m].index,Index);
			I[m].start=i+1;
			I[m-1].len=Len;
			m++;
			Len=0;
		}
	}
	I[m-1].len=n-I[m-1].start+1;
	return m;  //返回索引表长度
} //CreateIndex

//n为顺序表长度， key为待查关键字值， m为索引表长度
int IndexSearch(int n,char key[Lm],int m)
{
	char indexkey[Im];
	int i ;
	strncpy(indexkey,key,4);  //取索引关键字
	indexkey[Im-1]='\0';

	//在索引表中查找
	for(i=0; i<m; ++i)
	{
		if(!strcmp(indexkey,I[i].index))
			break;
	}
	if(i>=m) return -1;   //查找失败

	//在从j开始的子表中查找
	int j=I[i].start;
	while(j<I[i].start+I[i].len)
		if(!strcmp(key,L[j-1])) return j;
		else ++j;
	return -1;
} //IndexSearch

void main()
{
	int n=0,m=CreateIndex(n);
	printf("\nIndex List:\n");
	for(int i=0; i<m; i++)
		printf("%s,%d,%d\n",I[i].index,I[i].start,I[i].len);
	
	printf("\nKey: ");
	char x[Lm]="";
	scanf("%s",&x);
	m=IndexSearch(n,x,m);
	if(m<0) printf("\nNo Found.\n\n");
	else printf("\n%d,%s\n\n",m,L[m-1]);
}

/*
Index.in

12
20102589
20102617
20102692
20122465
20122478
20122516
20124991
20132503
20132630
20132632
20132668
20133357
*/