//����һЩ��ͬ��һλ���֣�����Դ���Щ������ѡ�����ɸ����������ǰ�һ��˳�����У����һ����������ʣ�µ����ְ�һ��˳�����У������һ����������ɵ�����������0��ͷ�������������ֻ��1λ����
//�������磬����6�����֣�0,1,2,4,6,7����������������һ����10��2467����Ȼ����������������ĺܶ����������210��764��204��176����Щ��������������ľ���ֵ��С����204��176��Ϊ28��
//��������N����ͬ��0~9֮������֣������������Щ������ɵ�ÿ�����У���ľ���ֵ��С��һ�ԣ����ԣ����ľ���ֵ�Ƕ��٣�
//�����ʽ Input Format	
// 	 ������һ�а���һ����T��T��1000����Ϊ�������ݵ�������
//����ÿ�����ݰ������У���һ��Ϊһ����N��2��N��10������ʾ���ֵĸ���������һ��ΪN����ͬ��һλ���֡�
//�����ʽ Output Format	
// 	
//����T�У�ÿ��һ��������ʾ��i�����ݵĴ𰸡�����С�Ĳ�ľ���ֵ
// 
//�������� Sample Input
//2
//6
//0 1 2 4 6 7
//4
//1 6 3 4
// 
//������� Sample Output
//28
//5

#include <stdio.h>

#define EMPTY -100 //�����λ��ΪEMPTY˵��δ����λ��

int AbsMin ; //������ŵ�ǰ��С�ľ���ֵ


//��data�����е� ��begin��ʼ��end������һ��ƴ������
//�����ͷ��0 ����EMPTY �� ���򷵻�ƴ�õ�����
int getNumber(int data[],int begin,int end)
{
	int num = 0;
	int i ;
	//��ͷ��0���ӵ�
	if(data[begin] == 0)
	{
		return EMPTY;
	}

	for(i=begin;i<end;i++)
	{
		num = num * 10 + data[i];
	}
	return num;
}

//����˺��������ã�˵��answer���Ѿ��õ�һ������
//��answer�ָ��Ϊ2�����֣��������ֵ��
void JudgeAnswer(int answer[],int NumLen,int n)
{
	int numA,numB;
	int delt;

	numA = getNumber(answer,0,NumLen);
	numB = getNumber(answer,NumLen,n);
	if(numA ==EMPTY || numB == EMPTY)
	{
		return;
	}
	if(numA>numB)
	{
		delt = numA - numB;
	}else{
		delt = numB - numA;
	}
	
	//�����С��������
	if(delt < AbsMin)
	{
		AbsMin = delt ; 
	}
	
}

/*�ж��Ƿ��ܹ�ѡ��ǰ����*/
//���num��answer�л�û�б�ѡȡ������1�����򷵻�0
int CheckDown(int answer[],int i , int num)
{
	int k;
	for(k=0;k<i;k++)
	{
		if(answer[k]==num)
		{
			return 0;
		}
	}
	return 1;
}


/*���ȫ����*/
/*data��ԭ���飬 answer��ʱ���һ�����У�NumLen��ŵ�һ�����ֵĳ��ȣ�n���������ܳ��ȣ�k��ʾ��ǰ�ݹ����*/
void GetArrange(int data[],int answer[],int NumLen,int n,int k)
{
	int i;
	//����ҵ�һ�����У������н�������ж�
	if( k >= n)
	{
		JudgeAnswer(answer,NumLen,n);
		return ;
	}
	for(i=0;i<n;i++)
	{
		if(CheckDown(answer,k,data[i]) == 1)
		{
			answer[k]=data[i];
			GetArrange(data,answer,NumLen,n,k+1);
			answer[k]= EMPTY ;
		}
	}
	return ;
}

int main()
{
	int count = 0;
	int group = 0;
	int data[10];
	int answer[10];
	int len;
	int i,j;

	while (scanf("%d",&group)!=EOF)
	{
		while(group--)
		{
			scanf("%d",&count);
			
			for(i=0;i<count;i++)
			{
				scanf("%d",&data[i]);
			}

			/*��֦���֣�Ϊ�˼����һ�㣬��һЩ�������ֱ���������*/
			if(count == 10)
			{
				printf("247\n");//��� 49876 �� 50123
				continue;
			}
			if(count == 2)
			{
				if(data[0]>data[1])
				{
					printf("%d\n",data[0]-data[1]);
				}else{
					printf("%d\n",data[1]-data[0]);
				}
				continue;
			}

			/*��ʼ����*/
			//��ʼ��
			len = count / 2;

			for(i=0;i<count;i++)
			{
				answer[i] = EMPTY;
			}
			AbsMin = 100000;

			//�������
			GetArrange(data,answer,len,count,0);
			//������AbsMin�еĽ�����
			printf("%d\n",AbsMin);
		}
	}

	return 0;
}
