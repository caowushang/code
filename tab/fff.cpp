/*************************************************************************
	> File Name: fff.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2016年10月18日 星期二 11时41分48秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<int> tmp;
typedef long long ll;
bool vis[110];
ll mx;
const ll inf=0x3f3f3f3f3f3f3f3f;
void dfs(int n)
{
	ll sum=0;
	ll sx=1;
	for(int i=0;i<tmp.size();i++)
	{
		sum+=tmp[i];
		sx*=tmp[i];
	}
	if(sum>=n)
	{
		if(sum==n&&sx>mx)
			mx=sx,ans=tmp;
		return;
	}
	for(int i=2;i<=100;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			tmp.push_back(i);
			dfs(n);
			tmp.pop_back();
			vis[i]=0;

		}
	}
}
int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	for(int n=1;n<=50;n++)
	{
		ans.clear();
		tmp.clear();
		mx=-inf;
		memset(vis,0,sizeof vis);
		dfs(n);
		cout << n << ": " << mx << ": ";
		for(int j=0;j<ans.size();j++)
			cout << ans[j] << " ";
		cout << endl;
	}
	return 0;
}
