#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=100+10;
char s[MAX];
bool flag;

int main(){
	while(gets(s)){
		flag=true;
		int num=3,p=0,x=-1,t=0;
		__int64 sum=0;
		for(int i=0;s[i] != '\0';++i){
			if(s[i] == '.'){
				--num;//��¼���ֹ����ε�,ֻ�ܳ���3�� 
				if(num<0 || sum>255 || p>3){flag=false;break;}
				sum=p=0;
				if(x != -1)++t;//t��¼���ֹ������ַ�,��ֹ..123.11������� 
				x=-1;
				continue;
			} 
			if(s[i]<'0' || s[i]>'9'){flag=false;break;}
			sum=sum*10+s[i]-'0';
			x=0;//����Ƿ���ֹ����� 
			++p;//��¼���ּ��������ַ� 
		}
		if(x != -1)++t;
		if(num || t != 4 || sum>255)flag=false;
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}