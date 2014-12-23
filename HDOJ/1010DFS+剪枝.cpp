#include "stdio.h"

int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int flag;
char maze[1000][10];
int M,N,T;
int endi,endj,begi,begj;

void DFS(int i,int j,int time)
{
    int p;
	if(flag == 1)return;                     //已找到
	if(time > T)return;                //超时
	if(i>= N || i<0 || j>= M || j <0 )return; //越界
	if(maze[i][j]=='X')return;
	if(i==endi && j == endj){flag=1;return;} //找到

	for(p=0;p<4;p++)
	{
	  maze[i][j]='X';
	  DFS(i+direction[p][0],j+direction[p][1],time+1);
	  maze[i][j]='.';
	  if(flag==1)return;
	}
}


int main()
{
    int i,j;

    while(scanf("%d %d %d",&N,&M,&T)!=EOF)
    {
        if(M==0 && N==0 && T==0)break;

        flag=0;

		getchar();
        for(i=0;i<N;i++)
        {
         for(j=0;j<M;j++)
         {
             scanf("%c",&maze[i][j]);
             if(maze[i][j]=='S')
             {
                endi=i;endj=j;
             }
             if(maze[i][j]=='D')
             {
                begi=i;begj=j;
             }
         }
         getchar();
        }

		if( (endi+endj+begi+begj+T)%2 == 1)
		{
        printf("NO\n");
		continue;
		}

        DFS(begi,begj,0);
        if(flag==1)
        printf("YES\n");
        else
        printf("NO\n");

    }

   return 0;
}
