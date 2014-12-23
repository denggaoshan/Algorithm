//给定一些不同的一位数字，你可以从这些数字中选择若干个，并将它们按一定顺序排列，组成一个整数，把剩下的数字按一定顺序排列，组成另一个整数。组成的整数不能以0开头（除非这个整数只有1位）。
//　　例如，给定6个数字，0,1,2,4,6,7，你可以用它们组成一对数10和2467，当然，还可以组成其他的很多对数，比如210和764，204和176。这些对数中两个数差的绝对值最小的是204和176，为28。
//　　给定N个不同的0~9之间的数字，请你求出用这些数字组成的每对数中，差的绝对值最小的一对（或多对）数的绝对值是多少？
//输入格式 Input Format	
// 	 　　第一行包括一个数T（T≤1000），为测试数据的组数。
//　　每组数据包括两行，第一行为一个数N（2≤N≤10），表示数字的个数。下面一行为N个不同的一位数字。
//输出格式 Output Format	
// 	
//　　T行，每行一个数，表示第i个数据的答案。即最小的差的绝对值
// 
//样例输入 Sample Input
//2
//6
//0 1 2 4 6 7
//4
//1 6 3 4
// 
//样例输出 Sample Output
//28
//5

#include <stdio.h>

#define EMPTY -100 //如果该位置为EMPTY说明未填充该位置

int AbsMin ; //用来存放当前最小的绝对值


//将data数组中的 从begin开始到end结束的一段拼成数字
//如果开头是0 返回EMPTY ， 否则返回拼好的数字
int getNumber(int data[],int begin,int end)
{
	int num = 0;
	int i ;
	//开头是0无视掉
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

//如果此函数被调用，说明answer中已经得到一种排列
//将answer分割成为2个数字，计算绝对值差
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
	
	//如果更小，记下来
	if(delt < AbsMin)
	{
		AbsMin = delt ; 
	}
	
}

/*判断是否能够选择当前数字*/
//如果num在answer中还没有被选取，返回1，否则返回0
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


/*获得全排列*/
/*data是原数组， answer临时存放一种排列，NumLen存放第一个数字的长度，n存放数组的总长度，k表示当前递归层数*/
void GetArrange(int data[],int answer[],int NumLen,int n,int k)
{
	int i;
	//如果找到一个排列，对排列结果进行判断
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

			/*剪枝部分，为了计算快一点，把一些特殊情况直接输出。。*/
			if(count == 10)
			{
				printf("247\n");//额，是 49876 跟 50123
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

			/*开始搜索*/
			//初始化
			len = count / 2;

			for(i=0;i<count;i++)
			{
				answer[i] = EMPTY;
			}
			AbsMin = 100000;

			//搜索结果
			GetArrange(data,answer,len,count,0);
			//将存在AbsMin中的结果输出
			printf("%d\n",AbsMin);
		}
	}

	return 0;
}
