/*************************************************************************
	> File Name: d.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年10月04日 星期二 15时20分30秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int mm[100][100];
int vis[100][100];
struct lake
{
	int x,y;
	int ar;
	bool operator <(const lake&t)const
	{
		return ar<t.ar;
	}
} L[55];
void oc(int x,int y)
{
	vis[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx>=0&&xx<=n+1&&yy>=0&&yy<=m+1&&!mm[xx][yy]&&!vis[xx][yy])
			oc(xx,yy);
	}
}
int la(int x,int y)
{
	vis[x][y]=1;
	int s=1;
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(!mm[xx][yy]&&!vis[xx][yy])
			s+=la(xx,yy);
	}
	return s;
}
void fil(int x,int y)
{
	mm[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(!mm[xx][yy])
			fil(xx,yy);
	}
}
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char x;
			cin >> x;
			if(x=='*')
				mm[i][j]=1;
		}
	}
	oc(0,0);
	int cl=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(!vis[i][j]&&!mm[i][j])
			{
				L[cl].x=i;
				L[cl].y=j;
				L[cl].ar=la(i,j);
				cl++;
			}
	}
	sort(L,L+cl);
	int ans=0;
	for(int i=0;i<cl-k;i++)
	{
		ans+=L[i].ar;
		fil(L[i].x,L[i].y);
	}
	cout << ans << endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mm[i][j])
				cout << "*";
			else
				cout << ".";
		}
		cout << endl;
	}
	return 0;
}
