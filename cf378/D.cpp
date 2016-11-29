/* ************************************************************************
	> File Name: D.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年11月08日 星期二 20时37分42秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+10;
int a[mx],b[mx],c[mx];
int n;
struct pp
{
	int a,b,c1,c2;
	pp(int a,int b)a(a),b(b)
	{
		if(a>b)swap(a,b);
	}
	pp(int a,int b,int c1,int c2,int c3):a(a),b(b),c1(c1),c2(c2)
	{
		if(a>b)swap(a,b);
		if(c1<c2)swap(c1,c2);
		if(c3>c1)c2=c1,c1=c3;
		else if(c3>c2)c2=c3;
	}
	bool operator <(const pp& t)const
	{
		if(a==t.a)
			return b<t.b;
		return a<t.a;
	}
};
set<pp> S;
set<pp>::iterator it;
int ans1[2];
int ans2[3];
void putin(int a,int b,int c)
{
	if(a>b)swap(a,b);
	it=S.find(pp(a,b));
	int c1,c2;
	if(it!=S.end()){
		c1=it->c1,c2=it->c2;
		S.erase(it),S.insert(pp(a,b,c1,c2,c));
	}
	else
		S.insert(pp(a,b,c,-1,-1));
}
void cul(int a,int b,int c)
{
	if(a>b)swap(a,b);
	it=S.find(pp(a,b));
	int c1,c2;
	if(it!=S.end())
	{
		c1=it->c1,c2=it->c2;
		if(c!=c1)
	}
}
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	scanf("%d",&n);
	ans1[0]=-1,ans2[0]=-1;
	int mmi;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		mmi=min(a[i],min(b[i],c[i]));
		if(mmi>ans1[0])ans1[0]=mmi,ans1[1]=i;
		putin(a[i],b[i],c[i]);
		putin(c[i],b[i],a[i]);
		putin(a[i],c[i],b[i]);
	}
	for(int i=1;i<=n;i++)
	{
		
	}
	return 0;
}
