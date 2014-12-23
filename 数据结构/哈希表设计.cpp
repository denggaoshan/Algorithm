/*
3-2哈希表设计。为班级30个人的姓氏(单字姓)设计一个哈希表，假设姓氏用汉语拼音表示。要求用除留取余法构造哈希函数，用线性探测再散列法处理冲突，平均查找长度的上限为2。
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define DATA_SIZE 30 //一共30个姓氏
#define FIRSTNAME_LEN 10 //姓氏的最大长度

// ASL = 1/2(1+1/(1-a)) <=2;
// 得出  a <= 2/3;
// 得出 HASHSIZE = 30/(2/3) = 15*3 = 45 ;
// 取最近的素数 ， 得出 HASHSIZE  应该为 47；

#define HASHSIZE 47 


//根据姓氏计算哈希值。
//我设计的计算函数是，把所有姓氏的ASCII码的和加起来，然后对 HASHSIZE 取模。
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

//插入 firstName 到 哈希表中
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

//查找并且返回索引
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


	printf("初始化Hash表\n");
	HashInit(&hash,HASHSIZE);
	
	
	printf("插入30个姓氏\n");
	for(i=0;i<DATA_SIZE;i++)
	{
		HashInsert(hash,FirstNameSet[i]);
	}


	index = HashSearch(hash,"Zhao",HASHSIZE);
	printf("在Hash表中查找姓氏 Zhao： 索引为 %d \n",index);
	index = HashSearch(hash,"Zou",HASHSIZE);
	printf("在Hash表中查找姓氏 Zou： 索引为 %d \n",index);
	index = HashSearch(hash,"Deng",HASHSIZE);
	printf("在Hash表中查找姓氏 Deng： 索引为 %d \n",index);

	return 0;
}