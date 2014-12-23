/*
*  编程之美 3.2 题目
*/

#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Node {
	list<string> words;
	Node *Child[8];
	Node()
	{
		for(int i=0;i<8;i++)
		Child[i]=NULL;
	}
};

const string map[8]={"AaBbCc","DdEeFf","GgHhIi","JjKkLl","MmNnOo","PpQqRrSs","TtUuVv","WwXxYyZz"};

class Dictionary{
	Node *origin;
public:
	Dictionary()
	{
		origin = new Node;
		origin->words.clear();
		for(int i=0;i<8;i++)
		origin->Child[i]=NULL;
	}
	
	//将单词转成数字表示
	string transWord(string word){
		string ret;
		for(unsigned int i=0;i<word.length();i++)
		{
			for(int j=0;j<8;j++){
				if(string::npos != map[j].find(word[i])){
					ret += j+2+'0';
					break;
				}
			}
		}
		return ret;
	}

	void addWord(string word){
		string number = transWord(word);
		Node *now = origin;

		//找到对应的层
		for(unsigned int i=0;i<number.length();i++){
			int pos = number[i] - '0' - 2;
			if(now->Child[pos]==NULL){
				now->Child[pos] = new Node;
			}
			now = now->Child[pos] ;
		}
		//加入单词到字典中
		now->words.push_back(word) ;
	}

	//查询某个号码是否在其中
	void SearchNumber(string number){
		Node *now = origin;
		for(unsigned int i=0;i<number.length();i++){
			int pos = number[i] - '0' - 2;
			if(now->Child[pos] == NULL){
				cout<<" 没有在字典中查找到 ！"<<endl;
				return;
			}
			now = now->Child[pos];
		}
		if(now->words.size()!=0){cout<<" 所有可能的单词为:"<<endl;}
		for(list<string>::iterator it =now->words.begin();it!= now->words.end();it++){
			cout<<*it<<" ";
		}
		cout<<endl;
		return ;
	}

};

int main()
{
	Dictionary dic;
	int i;
	string str;

	cout<<"1+(word) : 添加单词"<<endl;
	cout<<"2+(number) : 查找单词"<<endl;

	while (true)
	{
		cin>>i>>str;
		if(i==1){
			dic.addWord(str);
		}
		if(i==2){
			dic.SearchNumber(str);
		}
	}
}