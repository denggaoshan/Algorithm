/*
有些得注意的测试样例：
3 -3 -2 -3 ；            -2 2 2 
 
3 -3 2 -3  ；            2 2 2
*/

#include "stdio.h"

int main()
{
	int b;
	int T,n,i,j;
	int begin,mbegin,mend,end,num,max;

	while(scanf("%d",&T)!=EOF)
	{

		for(j=0;j<T;j++)
		{
			scanf("%d",&n);
			b=0,begin=1,max=-999999;
			for(i=0;i<n;i++)
			{
				scanf("%d",&num);
				b+=num;			
				if(b>max)
				{
					max=b;
					end=i+1;
					mbegin=begin;
					mend=end;
				}
				if(b<0)
				{
					b=0;
					begin=i+2;   //最后一次把这里从i+1改成了i+2就AC了；
				}
			}

			if(max<0)
			printf("Case %d:\n%d %d %d\n",j+1,max,mend,mend);
			else
			printf("Case %d:\n%d %d %d\n",j+1,max,mbegin,mend);
			if(j!=T-1)printf("\n");
		}
	}
	return 0;
}