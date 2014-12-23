#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;

typedef char String[MAXSIZE+1];


Status StrAssign(String string,char *src){
	int i=0;
	while(src[i]!='\0'){
		string[i+1]=src[i];
		i++;
		if(i >= MAXSIZE){
		return FALSE;
		}
	}
	string[0] = (char)i ;
	return TRUE;
}

Status StrCopy(String dist,String src){
	int i = 0 ;
	for(i=0; i<=src[0] ; i++){
		dist[i] = src[i];
	}
	return TRUE;
}

Status ClearString(String str){
	str[0] = 0 ;
	return TRUE;
}

Status StringEmpty(String str){
	if(str[0] == 0)
		return TRUE;
	return FALSE;
}

int StrLength(String str){
	return str[0];
}

//将a,b拼接成一个子串 
Status Concat(String t,String a,String b){
	int i = 0 , j = 0;
	if(a[0]+b[0] >= MAXSIZE){
		return FALSE;
	}
	t[0] = a[0] + b[0];
	for(i=1 ; i<=a[0] ; i++){
		t[i] = a[i];
	}
	for(j=1 ; j<=b[0] ;j++){
		t[i] = b[j];
		i++;
	}
	return TRUE;
}

//返回从a中，pos位置开始的长为len的字串
Status SubString(String t,String a,int pos,int len){
	int i = 0 ;
	if( a[0] < pos + len  || pos>=a[0] ){
		return FALSE;	
	}
	for(i=1; i<=len ; i++){
		t[i]=a[pos + i - 1];
	}
	t[0] = (char)len ;
		return TRUE;
}

//返回t在s的pos位置之后第一次出现的位置，没有则返回0
int Index(String s,String t,int pos){
	int i = pos , j = 1 , k = 1;
	while( i + t[0] <= s[0] ){
		j = 1;
		k = 0;
		while(s[i+k] == t[j]){
			j++;
			k++;
			if( j == t[0] + 1)
			{
				return i;
			}
		}
		i++;
	}
	return 0;
}

//从s中删去第pos个字符起长度为len的字符串
Status StrDelete(String s,int pos,int len){
	int i = 0;
	if(len<0 || pos+len > s[0]+1)
	{
		return FALSE;
	}
	while(i+len <= s[0]){
	s[i]=s[i+len];
	}
	s[0] -= (char)len ;
	return TRUE;
	
}

////用v替换s中所有的t
//int Replace(String s,String t,String v){
//	int pos = 0;
//	pos = Index(s,t,0);
//	while(pos != 0){
//		StrDelete(s,
//	}
//}

//在pos位置之前插入insert这个字符串
Status StrInsert(String str,int pos,String insert){
	int i = 0;
	int mov ;
	int insertLen = insert[0];
	if(pos <=0 || pos > str[0]+1){
		return FALSE;
	}
	mov = str[0] + insertLen;
	for(i=mov;i-insertLen >= pos;i--){
		str[i-insertLen]=str[i];
	}
	for(i=0;i<insert[0];i++){
		str[pos+i] = insert[i+1];
	}
	str[0]+=insertLen;
	return TRUE;
}
void Print(String str){
	int i =0 ;
	for(i=1;i<=str[0];i++)
	{
		printf("%c",str[i]);
	}
	printf("\n");
}

int main()
{
	String str ,str2 ,str3,strtmp;
	StrAssign(str,"Hello!");
	StrAssign(str2,"OK!");
	Concat(str3,str,str2);
	Print(str3);
	StrCopy(str3,str);
	Print(str3);

	StrAssign(strtmp,"llo");
	printf("\"Hello!\" Index \"llo\" %d\n",Index(str3,strtmp,1));
	printf("str3 :\n");
	Print(str3);
	StrInsert(str3,1,str2);
	Print(str3);
	return 0;
}