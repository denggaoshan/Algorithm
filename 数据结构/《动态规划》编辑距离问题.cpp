//http://www.cnblogs.com/biyeymyhjob/archive/2012/09/28/2707343.html
//编辑距离与编辑距离算法
//笔记
// 主要是找准最优子结构之间的关系，确定表达式，然后采用自底向上的方法求解

#include <iostream>
#include <vector>
#include <string>
using namespace std;
//
////算法
//int ldistance(const string source,const string target)
//{
//    //step 1
//
//    int n=source.length();
//    int m=target.length();
//    if (m==0) return n;
//    if (n==0) return m;
//    //Construct a matrix
//    typedef vector< vector<int> >  Tmatrix;
//    Tmatrix matrix(n+1);
//    for(int i=0; i<=n; i++)  matrix[i].resize(m+1);
//
//    //step 2 Initialize
//
//    for(int i=1;i<=n;i++) matrix[i][0]=i;
//    for(int i=1;i<=m;i++) matrix[0][i]=i;
//
//     //step 3
//     for(int i=1;i<=n;i++)
//     {
//        const char si=source[i-1];
//        //step 4
//        for(int j=1;j<=m;j++)
//        {
//
//            const char dj=target[j-1];
//            //step 5
//            int cost;
//            if(si==dj){
//                cost=0;
//            }
//            else{
//                cost=1;
//            }
//            //step 6
//            const int above=matrix[i-1][j]+1;
//            const int left=matrix[i][j-1]+1;
//            const int diag=matrix[i-1][j-1]+cost;
//            matrix[i][j]=min(above,min(left,diag));
//
//        }
//     }//step7
//      return matrix[n][m];
//}
//

// //递归解法
//int myEdit(string a,string b)
//{
//	thecount++;
//	if(a.length()==0 && b.length()==0)return 0;
//	if(a.length()==0)return b.length();
//	if(b.length()==0)return a.length();
//	if(a.length()>=1 && b.length()>=1)
//	{
//		string c=a,d=b;
//		char p=a[a.length()-1],q=b[b.length()-1];
//		c.pop_back();
//		d.pop_back();
//		return min(myEdit(c,d)+!(p==q),min(myEdit(c,b)+1,myEdit(a,d)+1));
//	}
//	cout<<"error!"<<endl;
//	return 0;
//}

////我自己写的
int ldistance(string a,string b)
{
	int line=a.length(),row=b.length();
	vector<vector<int>>data;
	data.resize(line+1);
	for(int i=0;i<line+1;i++)
		data[i].resize(row+1);

	for(int i=0;i<line+1;i++)
		data[i][0]=i;
	for(int i=0;i<row+1;i++)
		data[0][i]=i;

	for(int i=1;i<line+1;i++)
	{
		for(int j=1;j<row+1;j++)
		{
			char sa=a[i-1];
			char sb=b[j-1];
			int cost = !(sa==sb);
			data[i][j]=min(data[i-1][j-1]+cost,min(data[i-1][j]+1,data[i][j-1]+1));
		}
	}

	return data[line][row];
}

int main(){
    string s;
    string d;
    cout<<"source=";
    cin>>s;
    cout<<"diag=";
    cin>>d;
    int dist=ldistance(s,d);
	//int dist=myEdit(s,d);
	cout<<"dist="<<dist<<endl;

}