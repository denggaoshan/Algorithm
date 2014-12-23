/*生成一个满足数独的解
*	 主要思想 DFS  
*/
#include <iostream>
#include <vector>

#define ROW 9
#define COL 9

using namespace std;

class Sudoku{
private:
	int Board[ROW][COL]; 
public:
	Sudoku()
	{
		memset(Board,0,sizeof(Board));
		
	}

	void SetBoard(int Dist[ROW][COL]){
		memcpy(Board,Dist,sizeof(Board));
	}

	//生成一组游戏数据
	void GetNewBoard()
	{
		DFS(0,0);
	}

	void DFS(int nowi,int nowj)
	{
		if(nowi == ROW-1 && nowj == COL-1)
		{
			PrintAnswer();
			return;
		}
		vector<int> val;
		val = GetValidValueList(nowi,nowj);
		//如果已经有数了
		if(val.size() == 0 && Board[nowi][nowj]!=0)
		{
			if(nowj + 1 < COL )
			{
				DFS(nowi,nowj+1);
			}else
			{
				DFS(nowi+1,0);
			}
		}
		else
		{
			for(int &num:val)
			{
				Board[nowi][nowj]=num;
				if(nowj + 1 < COL )
				{
					DFS(nowi,nowj+1);
				}else
				{
					DFS(nowi+1,0);
				}
				Board[nowi][nowj]=0;
			}
		}
		return;
	}

	bool CheckPos(int i,int j,int number){
		int p,q;
		//检测一行有没有重复
		for(p=i,q=0;q<COL;q++){
			if( Board[p][q]== number)	
				return false;
		}
		//检测一列中有没有重复
		for(p=j,q=0;q<ROW;q++){
			if( Board[q][p]== number)	
				return false;
		}
		//检测方格中有没有重复
		int tempi,tempj;
		tempi = i / 3;
		tempj = j / 3;//说明左上角的坐标是 (tempi,tempj)
		for(p=0;p<3;p++)
			for(q=0;q<3;q++)
			{
				if(Board[3*tempi+p][3*tempj+q] == number)
					return false;
			}
		return true;
	}

	//获得当前格子中所有可能的取值
	vector<int> GetValidValueList(int i,int j)
	{
		vector<int>ret;
		if(Board[i][j]!=0){
			return ret;
		}
		for(int k=1;k<=9;k++){
			if(CheckPos(i,j,k)==true){
				ret.push_back(k);
			}
		}
		return ret;
	}

	void PrintAnswer()
	{
		for(int i=0;i<ROW;i++)
		{
			for(int j=0;j<COL;j++)
			{
				cout<<Board[i][j]<<" ";
			}
			cout<<endl;
		}
		getchar();
	}

};

int main()
{
	int MyBoard[ROW][COL]=
	{3,4,0,0,0,2,0,1,7,
	 0,0,2,9,0,1,4,0,5,
	 7,0,9,0,0,5,0,0,0,
	 0,0,7,6,2,3,1,5,4,
	 0,3,1,0,8,0,2,7,0,
	 2,5,4,1,9,7,3,0,0,
	 0,0,0,2,0,0,5,0,3,
	 1,0,3,7,0,6,8,0,0,
	 5,2,0,3,0,0,0,6,1
	};
	Sudoku game;
	game.SetBoard(MyBoard);
	game.GetNewBoard();
}

