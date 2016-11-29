/* ************************************************************************
	> File Name: d.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年11月04日 星期五 14时10分35秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int a[300];
int b[300];
int dp[300][300];
int dfs(int l,int r)
{
	if(dp[l][r]!=inf)
		return dp[l][r];
	if(l>r)
		return 0;
	if(l==r)
		return dp[l][r]=a[l]+b[l-1]+b[r+1];
	for(int i=l;i<=r;i++)
		dp[l][r]=min(dp[l][r],a[i]+dfs(l,i-1)+dfs(i+1,r)+b[l-1]+b[r+1]);
	return dp[l][r];
}
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);	
	int t;
	scanf("%d",&t);
	for(int ii=1;ii<=t;ii++)
	{
		memset(dp,inf,sizeof(dp));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		a[n+1]=0,b[n+1]=0;
		printf("Case #%d: %d\n",ii,dfs(1,n));
	}
	return 0;
}
