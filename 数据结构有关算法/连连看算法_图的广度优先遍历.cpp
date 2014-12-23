/*�����㷨*/


#include <iostream>
#include <queue>

using namespace std;

#define ROW 10
#define COL 10

enum Direction{
	ORIGIN,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Position{
public:
	int x;
	int y;
	bool operator ==(Position& other)
	{
		return this->x == other.x && this->y == other.y;
	}
};

class PathNode{
public:
	Position nowpos; //��ǰλ������
	queue<Position> prePos; //�洢����ڵ�֮ǰ��·��
	Direction nowDir; //��ǰ�ķ���
	int trunedCount ; //��ǰ��ת������
};

class Game{
public:
	Game()
	{
		for(int i=0;i<ROW+1;i++)
		{
			for(int j=0;j<COL+1;j++)
			{
				Board[i][j]=0;
			}
		}
		Board[3][5] = 2;
		Board[3][6] = 3;
		Board[3][7] = 1;
		Board[4][7] = 4;
		Board[4][6] = 4;
		Board[4][8] = 2;
		Board[5][6] = 2;
		Board[5][7] = 3;
	}
	
	void Print()
	{
		for(int i=0;i<ROW;i++)
		{
			for(int j=0;j<COL;j++)
			{
				//if(Board[i][j]!=0)
				cout<<Board[i][j]<<" ";
				//else
				//	cout<<"  ";
			}
			cout<<endl;
		}
	}

	queue<Position> FindPath(Position src,Position dist){
		memset(ifVisited,0,sizeof(ifVisited));
		int PicNumber = FindPic(src);
		queue<PathNode> path;
		queue<Position> retpath;
		PathNode Node;
		Node.nowDir = ORIGIN;
		Node.nowpos = src;
		Node.trunedCount = -1;
		path.push(Node);

		do
		{
			PathNode node = path.front();
			path.pop();
			if( node.nowpos == dist && CmpPic(node.nowpos,dist )&& (node.nowDir != ORIGIN)){
				retpath = node.prePos ;
				retpath.push(node.nowpos);
				return retpath;
			}
			else
			{
					PathNode nodetmp;
					if( getNodeByDir(node,PicNumber,LEFT,nodetmp)){
						path.push(nodetmp);
					}
					if( getNodeByDir(node,PicNumber,DOWN,nodetmp)){
						path.push(nodetmp);
					}
					if( getNodeByDir(node,PicNumber,RIGHT,nodetmp)){
						path.push(nodetmp);
					}
					if( getNodeByDir(node,PicNumber,UP,nodetmp)){
						path.push(nodetmp);
					}
					ifVisited[node.nowpos.x][node.nowpos.y] = 1;
			}
		}while (path.size()>0);

		return retpath;
	}

private:

	int ifVisited[ROW+1][COL+1]; //��������Ƿ����

	//�������һ��node
	bool getNodeByDir(PathNode node,int PicNum,Direction dir,PathNode& ret){

		int deltx = 0,delty = 0;

		switch (dir)
		{
		case ORIGIN:
			break;
		case UP: deltx = -1,delty = 0;
			break;
		case DOWN:deltx = 1,delty = 0;
			break;
		case LEFT:deltx = 0,delty = -1;
			break;
		case RIGHT:deltx = 0,delty = 1;
			break;
		default:
			break;
		}

		ret.nowpos.x = node.nowpos.x + deltx;
		ret.nowpos.y = node.nowpos.y + delty;

		if(ifVisited[ret.nowpos.x ][ret.nowpos.y])
		{
			return false;
		}

		//���Խ�� ����false
		if(ret.nowpos.x>=ROW+1 ||ret.nowpos.x<=0 ||ret.nowpos.y>=COL+1||ret.nowpos.y<=0){
			return false;
		}
		//��������ͼƬ��ס ����false
		if(FindPic(ret.nowpos)!=0 && FindPic(ret.nowpos)!= PicNum){
			return false;
		}
		else
		{
			ret.nowDir = dir;

			if(ret.nowDir != node.nowDir){
				ret.trunedCount = node.trunedCount + 1;
			}else{
				ret.trunedCount = node.trunedCount;
			}

			if(ret.trunedCount > 2 ){
			return false;
			}

			ret.prePos = node.prePos;
			ret.prePos.push(node.nowpos);

			return true;
		}
	}

	int Board[ROW+1][COL+1];
	//����posλ�õ�ͼƬ���
	int FindPic(Position pos){
		return Board[pos.x][pos.y];
	}
	bool CmpPic(Position a,Position b){
		return FindPic(a)==FindPic(b);
	}
};

void PlayGame()
{
	
}

int main()
{
	
	Game game;
	Position a,b;
	a.x = 4;
	a.y = 8;
	b.x = 3;
	b.y = 5;
	game.Print();
	queue<Position> path = game.FindPath(a,b);
	cout<<"����Ϊ ��"<<endl;
	while(path.size()!=0){
		Position pos =path.front();
		path.pop();
		cout<<pos.x<<" "<<pos.y<<endl;
	}
	return 0;
} 