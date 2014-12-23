#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class Node
{
public:
	double weight;
	Node *left;
	Node *right;

	bool operator<(Node &node)
	{
		if(this->weight < node.weight)
			return true;
		else
			return false;
	}
};

class EmptyNode:public Node
{
};

class CodecNode:public Node
{
public:
	char origin;
	CodecNode(char origin, double weight)
	{
		this->weight = weight;
		this->origin = origin;
	}
};

class HuffmanCodec
{ 
	list<Node> allNode;		//构造用的临时队列

	vector<char> charSet;		//字符集
	vector<double> charWeight;	//每个字符对应权重
	int count;
public:
	
	HuffmanCodec(){};
	
	HuffmanCodec(char *charSet,double *charWeight,int n)
	{
		count = n;
		for(int i=0;i<n;i++)
		{
			this->charSet.push_back(charSet[i]);
			this->charWeight.push_back(charWeight[i]);
		}
	}

	bool AddAllNode()
	{
		for(int i =0;i<count ;i++)
		{
			CodecNode node(charSet[i],charWeight[i]); 
			allNode.push_front(node);
			allNode.sort();
		}
	}

	bool BuildHuffTree()
	{
		AddAllNode();
		
		while (allNode.size() > 1)
		{
			list<Node>::iterator it = allNode.begin();
			Node first = *it;
			allNode.remove(*it);
			it++;
			Node second = *it;
			allNode.remove(*it);
		}

		return true;
	}

};

int main()
{
	HuffmanCodec *huff = NULL;
	char data[6]={'A','B','C','D','E','F'};
	double weight[6]={27,8,15,15,30,5};
	huff = new HuffmanCodec(data,weight,6);
	huff->BuildHuffTree();
	return 0;
}