/*************************************************************************
	> File Name: m.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年10月06日 星期四 19时04分22秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int n,m;
int S[100100];
int E[100100];
int vs[100100];
int ve[100100];
struct node
{
	int c,no;
	node(int c=0,int no=0):c(c),no(no){}
	bool operator <(const node&t)const
	{
		return c>t.c;
	}
};
int minc,mno;
vector<node> M[100100];
void debfs()
{
	priority_queue<node> s;
	priority_queue<node> e;
	s.push(node(0,1));
	e.push(node(0,n));
	vs[1]=1,ve[n]=1;
	while(!s.empty()&&!e.empty())
	{
		node x=s.top(),s.pop();
		int no=x.no;
		for(int i=0;i<M[no].size();i++)
		{
			node k=node(M[no][i].c+x.c,M[no][i].no);
			if(!vs[k.no])
			{
				vs[k.no]=1;
				if(S[k.no])
				{
					minc=k.c+S[k.no];
					mno=k.no;
					return;
				}
				S[k.no]=k.c;
				s.push(k);
			}
		}
		node y=e.top(),e.pop();
		no=y.no;
		for(int i=0;i<M[no].size();i++)
		{
			node k=node(M[no][i].c+y.c,M[no][i].no);
			if(!ve[k.no])
			{
				ve[k.no]=1;
				if(S[k.no])
				{
					minc=k.c+S[k.no];
					mno=k.no;
					return;
				}
				S[k.no]=k.c;
				e.push(k);
			}
		}
	}
}
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int ii=1;ii<=t;ii++)
	{
		cout << "Case #" << ii << "
		memset(S,0,sizeof S);
		memset(vs,0,sizeof vs);
		memset(ve,0,sizeof ve);
		minc=-1,mno=-1;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			M.clear();
		for(int i=0;i<m;i++)
		{
			int c,sn;
			scanf("%d%d",&c,&sn);
			for(int j=0;j<sn;j++)
				scanf("%d",E[j]);
			for(int j=0;j<sn-1;j++)
				for(int k=j+1;k<sn;k++)
				{
					M[E[j]].push_back(node(c,E[k]));
					M[E[k]].push_back(node(c,E[j]));
				}
		}
		debfs();
		if(mno!=-1)
			
	}
	return 0;
}
