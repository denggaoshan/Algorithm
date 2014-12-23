/* 通过前序遍历，中序遍历，来构建一棵二叉树*/

#include <iostream>
#include <queue>

using namespace std;

struct Node{
	int data;
	Node * left;
	Node * right;
};

class BitTree{
	Node * head;
	Node * Rebuild(int preOrder[] , int inOrder[] , int preBegin , int preEnd,int inBegin,int inEnd)
	{
		if(inBegin == inEnd )
		{
			return NULL;
		}
		Node * ret = new Node;
		ret->data = preOrder[preBegin];
		int rightCount,leftCount;
		int index = FindIndexIninOrder(inOrder,inBegin,inEnd,preOrder[preBegin],leftCount,rightCount);
		Node * left = Rebuild(preOrder,inOrder,preBegin+1,preBegin+1+leftCount,index-leftCount,index);
		Node * right= Rebuild(preOrder,inOrder,preBegin+1+leftCount,preEnd,index+1,inEnd);
		ret->left = left;
		ret->right = right;
		return ret;
	}

	int FindIndexIninOrder(int inOrder[],int begin,int end,int val,int &leftcount,int &rightcount){
		int ret = -1;
		for(int i=begin;i<end;i++){
			if(inOrder[i] == val){
				ret = i;
			}
		}
		leftcount = ret - begin;
		rightcount = end - ret - 1; 
		return ret;
	}

	void DoPostOrder(Node *p)
	{
		if(p==NULL)
			return;
		DoPostOrder(p->left);
		DoPostOrder(p->right);
		cout<<p->data<<" ";
		return ;
	}
	void DoMidOrder(Node *p)
	{
		if(p==NULL)
			return;
		DoMidOrder(p->left);
		cout<<p->data<<" ";
		DoMidOrder(p->right);
		return ;
	}
	void DoPreOrder(Node *p)
	{
		if(p==NULL)
			return;
		cout<<p->data<<" ";
		DoPreOrder(p->left);
		DoPreOrder(p->right);
		return ;
	}

	void DoPrintNodeAtLevel()
	{
		queue<Node*> que;

	}
	
	void CleanBitTree(Node *head){
		if(head == NULL)
			return;
		CleanBitTree(head->left);
		CleanBitTree(head->right);
		delete head;
		head = NULL;
	}

public:
	BitTree()
	{
		head = NULL;
	}

	//二叉树的销毁
	~BitTree(){
		CleanBitTree(head);
	}
	bool RebuildByPreAndIn(int preOrder[],int inOrder[],int len){
		head = Rebuild(preOrder,inOrder,0,len,0,len);
		return true;
	}

	void PreOrder()
	{
		cout<<"前序遍历的结果是： "<<endl;
		DoPreOrder(head);
		cout<<endl;
	}

	void MidOrder()
	{
		cout<<"中序遍历的结果是 : "<<endl;
		DoMidOrder(head);
		cout<<endl;
	}
	void PostOrder()
	{
		cout<<"后序遍历的结果是 : "<<endl;
		DoPostOrder(head);
		cout<<endl;
	}

	//使用3种方式遍历二叉树
	void TraverseAll()
	{
		PreOrder();
		MidOrder();
		PostOrder();
	}

	//分层遍历二叉树
	void PrintNodeAtLevel(){
		cout<<"分层遍历二叉树的结果为 ： "<<endl;
	}
};



int main()
{
	BitTree bit;
	int preOrder[] = {1,2,4,3,5,6};
	int inOrder[] = {4,2,1,5,3,6};
	bit.RebuildByPreAndIn(preOrder,inOrder,6);
	bit.TraverseAll();
	return 0;
}