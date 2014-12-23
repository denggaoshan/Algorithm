#include <stdio.h>
#include <stdlib.h>
#include <string>

#define Ln 20 //˳�����󳤶�
#define Lm 9  //�ؼ��ֿ��+1
#define In 6  //��������󳤶�
#define Im 5  //�����ؼ��ֿ��+1

char L[Ln][Lm];  //˳���[�ؼ�������]

//������洢�ṹ
typedef struct
{
	char index[Im];  //�����ؼ���
	int start;	//�ӱ��1����¼��˳����е�λ��
	int len;	//�ӱ�ĳ���
} IndexType;
IndexType I[In];  //������

//����˳�����������
int CreateIndex(int &n)
{
	//˳����ʼ��
	FILE *fp=fopen("Index.in","r");  //�������ļ�
	int i , j ;
	fscanf(fp,"%d",&n);  //��ȡ��¼��
	fscanf(fp,"%c");  //�������з�
	printf("Key List:\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<Lm-1; j++)
			fscanf(fp,"%c",&L[i][j]);
		fscanf(fp,"%c");  //�������з�
		L[i][j]='\0';
		puts(L[i]);
	}

	//����������
	int Len=0,m=1;  //m:�������ȼ���
	strncpy(I[0].index,L[0],Im-1);
	I[0].index[Im-1]='\0';
	I[0].start=1;
	char Index[Im]="";
	for(i=1; i<n; i++)
	{
		Len++;  //�ӱ��ȼ���
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
	return m;  //������������
} //CreateIndex

//nΪ˳����ȣ� keyΪ����ؼ���ֵ�� mΪ��������
int IndexSearch(int n,char key[Lm],int m)
{
	char indexkey[Im];
	int i ;
	strncpy(indexkey,key,4);  //ȡ�����ؼ���
	indexkey[Im-1]='\0';

	//���������в���
	for(i=0; i<m; ++i)
	{
		if(!strcmp(indexkey,I[i].index))
			break;
	}
	if(i>=m) return -1;   //����ʧ��

	//�ڴ�j��ʼ���ӱ��в���
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