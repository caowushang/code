/*************************************************************************
  > File Name: tmp.cpp
  > Author: caowushang
  > Mail: 15630929347@163.com 
  > Created Time: 2016年10月01日 星期六 09时34分38秒
 ************************************************************************/

#include<bits/stdc++.h>
const int inf=0x3f3f3f3f;
using namespace std;
int dp[5100][5100];
int lu[5100][5100];
struct ed
{
	int u,v,t;
	ed(int u=0,int v=0,int t=0):u(u),v(v),t(t){}
}p[5100];
int ll[5100];
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n,m,T;
	while(scanf("%d%d%d",&n,&m,&T)!=EOF)
	{
		for(int i=0;i<m;i++)
		{
			int u,v,t;
			scanf("%d%d%d",&u,&v,&t);
			p[i]=ed(u,v,t);
		}
		memset(dp,inf,sizeof dp);
		memset(lu,-1,sizeof lu);
		dp[1][1]=0;
		int ans;
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<m;j++){

				int u=p[j].u;
				int v=p[j].v;
				int t=p[j].t;
				if(dp[i-1][u]+t<dp[i][v])
				{
					dp[i][v]=dp[i-1][u]+t;
					lu[i][v]=u;
				}
			}
			if(dp[i][n]<=T)
				ans=i;
		}
		cout << ans << endl;
		int cc=0,sum=ans;
		int x=n;
		while(x!=-1){
			ll[cc++]=x;
			x=lu[sum--][x];
		}
		for(int i=cc-1;i>=0;i--)
			printf("%d ",ll[i]);
		puts("");
	}
	return 0;
}
