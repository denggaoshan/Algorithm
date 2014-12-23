/*
3-2��ϣ����ơ�Ϊ�༶30���˵�����(������)���һ����ϣ�����������ú���ƴ����ʾ��Ҫ���ó���ȡ�෨�����ϣ������������̽����ɢ�з������ͻ��ƽ�����ҳ��ȵ�����Ϊ2��
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define DATA_SIZE 30 //һ��30������
#define FIRSTNAME_LEN 10 //���ϵ���󳤶�

// ASL = 1/2(1+1/(1-a)) <=2;
// �ó�  a <= 2/3;
// �ó� HASHSIZE = 30/(2/3) = 15*3 = 45 ;
// ȡ��������� �� �ó� HASHSIZE  Ӧ��Ϊ 47��

#define HASHSIZE 47 


//�������ϼ����ϣֵ��
//����Ƶļ��㺯���ǣ����������ϵ�ASCII��ĺͼ�������Ȼ��� HASHSIZE ȡģ��
int getHashVal(char* fistName)
{
	char ch ;
	int i;
	int sum = 0;
	for(i=0;i<strlen(fistName);i++)
	{
		sum += fistName[i] ;
	}
	return sum % HASHSIZE ;
}

void HashInit(char ***hash,int size)
{
	int i = 0;

	(*hash) = (char **)malloc(sizeof(char*)*size);

	for(i=0;i<size;i++)
	{
		(*hash)[i] = (char *)malloc(sizeof(char) * FIRSTNAME_LEN);
		strcpy((*hash)[i],"");
	}
}

//���� firstName �� ��ϣ����
void HashInsert(char **hash,char *firstName)
{
	int hashval = 0;
	int index = 0;

	hashval =  getHashVal(firstName);
	index = hashval;

	while(strcmp(hash[index],"") != 0 )
	{
		index = (index + 1) % HASHSIZE;
	}

	strcpy(hash[index],firstName);
}

//���Ҳ��ҷ�������
int HashSearch(char **hash,char *findName,int len)
{
	int index = 0;
	int hashval = 0;

	hashval = getHashVal(findName);
	index = hashval;

	while(len && strcmp(hash[index],findName)!=0)
	{
		index = (index + 1)% HASHSIZE;
		len -- ;
	}
	if(len ==0)
		return -1;
	else
		return index;
}


char FirstNameSet[DATA_SIZE][FIRSTNAME_LEN]=
{
	"Zhao","Qian","Sun","Li","Zhou","Wu","Zheng","Wang","Feng","Cheng",
	"Zou","Wei","Jiang","Sheng","Han","Yang","Zhu","Qing","You","Xu",
	"He","Lv","Shi","Zhang","Kong","Cao","Yan","Hua","Jin","Fan"
};

int main()
{
	char **hash=NULL;
	int i = 0;
	int index = 0;


	printf("��ʼ��Hash��\n");
	HashInit(&hash,HASHSIZE);
	
	
	printf("����30������\n");
	for(i=0;i<DATA_SIZE;i++)
	{
		HashInsert(hash,FirstNameSet[i]);
	}


	index = HashSearch(hash,"Zhao",HASHSIZE);
	printf("��Hash���в������� Zhao�� ����Ϊ %d \n",index);
	index = HashSearch(hash,"Zou",HASHSIZE);
	printf("��Hash���в������� Zou�� ����Ϊ %d \n",index);
	index = HashSearch(hash,"Deng",HASHSIZE);
	printf("��Hash���в������� Deng�� ����Ϊ %d \n",index);

	return 0;
}