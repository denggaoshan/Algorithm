#include "stdio.h"

int N,result[21]={1};
int visit[22]={1,1};

int IsPrime(int num)
{
	int i,flag=1;

	for(i=2;i<num;i++)
	{
		if(num%i==0)
		{
			flag=0;
			break;
		}
	}
	return flag;
}

void Print(int num)
{
	int i;
	for(i=0;i<num-1;i++)
		printf("%d ",result[i]);
	printf("%d\n",result[num-1]);

}

void DFS(int num)
{
	int i;

	if(num>=N && IsPrime(result[num-1]+result[0]))
	{
		Print(num);
		return;
	}                          //find
	else
	{
		for(i=2;i<=N;i++)
		{
			if( IsPrime(result[num-1]+i) && !visit[i])
			{
				result[num]=i;
				visit[i]=1;
				DFS(num+1);
				visit[i]=0;
			}
		}
	}
}


int main()
{
	int k=1;
	int i;

	while(scanf("%d",&N)!=EOF)
	{
		printf("Case %d:\n",k++);
	    
		for(i=1;i<21;i++)
		{
			result[i]=0;
		    visit[i]=0;
		}

		DFS(1);
      printf("\n");
	}
	return 0;
}