#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIST_LEN 20	//˳����ܳ���
#define LIST_KEY_LEN 9	//˳���ؼ��ֳ���
#define INDEX_LEN 6 	//���������󳤶�
#define INDEX_KEY_LEN 5	//�ؼ�����󳤶�+1


char List[LIST_LEN][LIST_KEY_LEN]; //����˳���

typedef struct IndexType 
{
	char index[INDEX_KEY_LEN]; 	//������Ĺؼ���
	int start;			//�����ʼλ��
	int len;			
}IndexType;

IndexType IndexList[INDEX_LEN];

//��ȡ˳���,����˳�����
int CreateList()
{
	int count;
	int i = 0 ;
	FILE * file = fopen("Index.in","r");
	if(!file)
	{
		printf("can't find data file!\n");
		return -1;
	}

	fscanf(file,"%d",&count);
	fscanf(file,"%c");
	printf("Key List : \m");
	for( i = 0 ; i < count ; i++)
	{
		fscanf(file,"%s",List[i]);
		fscanf(file,"%c");
		printf("%s\n",List[i]);
	}

	return count;
}

//����˳���������Ӧ��������,listLen�������Ա�ĳ���,������������
int CreateIndexTable(int listLen)
{
	int i = 0;	
	char nowIndex[INDEX_KEY_LEN];
	int indexCount = 0;

	strncpy(IndexList[indexCount].index,List[0],INDEX_KEY_LEN - 1);
	IndexList[indexCount].start = 1;
	IndexList[indexCount].len = 1;

	strcpy(nowIndex,IndexList[0].index);

	for(i = 1  ; i < listLen ; i++)
	{
		strncpy(nowIndex , List[i] , INDEX_KEY_LEN - 1);
		nowIndex[INDEX_KEY_LEN - 1] = '\0';
		if(strcmp( nowIndex , IndexList[indexCount].index ) == 0)
		{
			IndexList[indexCount].len++;
		}
		else
		{
			indexCount++ ;
			strcpy(IndexList[indexCount].index,nowIndex);
			nowIndex[INDEX_KEY_LEN - 1] = '\0';
			IndexList[indexCount].start = i + 1;
			IndexList[indexCount].len = 1 ;	
		}
	}

	return indexCount + 1; 
}

//key��Ҫ���ҵĹؼ��֣�indexLen��������ĳ���
int IndexSearch(char key[INDEX_KEY_LEN],int indexLen)
{
	int j = 0 ;
	int i = 0 ;
	char keyIndex[INDEX_KEY_LEN] ; 
	int start = 0 , len = 0;
	
	strncpy(keyIndex,key,INDEX_KEY_LEN - 1);
	keyIndex[INDEX_KEY_LEN - 1] = '\0';
	
	for( i = 0 ; i <indexLen ; i++)
	{
		if(strcmp(IndexList[i].index,keyIndex)==0)
		{
			break;
		}
	}
	if(i == indexLen )
	{
		return 0;
	}
	
	start = IndexList[i].start;
	len = IndexList[i].len;
	for(j=0; j < len ; j++)
	{
		if(strcmp(key,List[start + j - 1])==0)
		{
			return start +j - 1 ;
		}
	}
	return 0;
}

int main()
{
	int n = 0 ;
	int m = 0 ;
	int status = 0;
	char key[LIST_KEY_LEN] ;
	n = CreateList();
	m = CreateIndexTable(n);
	printf("Input Key :\n");
	scanf("%s",key);
	status = IndexSearch(key,m);
	if(status!=0)
	{
		printf("Position = %d\n",status);
	}
	else
	{
		printf("Can not find!\n");
	}
	return 0;
}