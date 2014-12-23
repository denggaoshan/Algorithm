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
				--num;//记录出现过几次点,只能出现3次 
				if(num<0 || sum>255 || p>3){flag=false;break;}
				sum=p=0;
				if(x != -1)++t;//t记录出现过几次字符,防止..123.11这种情况 
				x=-1;
				continue;
			} 
			if(s[i]<'0' || s[i]>'9'){flag=false;break;}
			sum=sum*10+s[i]-'0';
			x=0;//标记是否出现过数字 
			++p;//记录出现几个数字字符 
		}
		if(x != -1)++t;
		if(num || t != 4 || sum>255)flag=false;
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}