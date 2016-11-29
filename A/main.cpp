/*************************************************************************
	> File Name: A.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com
	> Created Time: 2016年10月05日 星期三 09时19分54秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[30][20][200];
ll dfs(int n,int k,int s)
{
    ll &res=dp[n][k][s];
    if(res)
        return res;
	if(k==1)
	{
        if(n>=s)
            res=1;
		return res;
    }
	for(int i=n-1;i>=(k-1);i--)
	{
		if(s-i-1>0)
			res=res+dfs(i,k-1,s-i-1);
	}
	return res;
}
int main()
{
	int n,k,s;
	while(cin >> n >> k >> s && n && k &&s)
	{
		cout << dfs(n,k,s) << endl;
	}
	return 0;
}
